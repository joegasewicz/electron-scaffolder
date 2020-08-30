/**
 *  ELECTRON SCAFFOLDER by Joe Gasewicz
 *  
 *  Electron with Typescript & React starter generator
 * 
 *  Contact joegasewicz@gmail.com
 **/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define ES_PROJECT_NAME_MAX_LENGTH 50
#define ES_CMD_HELP "--help"
#define ES_CMD_SHORT_HELP "-h"
#define ES_CMD_FLAT "--flat"
#define ES_CMD_SHORT_FLAT "-f"
#define ES_CMD_FORM "--form"
#define ES_ARGS_MAX_LENGTH 2
#define ES_NPM_ROOT_MAX_LENGTH 300
#if defined(_WIN32) || defined(WIN32)
    #define ES_NPM_ROOT "\\electron-scaffolder\\project\\*"
#else
    #define ES_NPM_ROOT "/electron-scaffolder/project/*"    
#endif
#define ES_EXEC_ROOT_MAX_LENGTH 300
#define ES_COPY_CMD_MAX_LENGTH 604


typedef struct
{
    char *args[ES_ARGS_MAX_LENGTH]; // TODO remove if not used
    int args_length;
    char *project_name;
    char *relative_path;
    bool is_flat;
    bool is_form;
} ELECTRON_SCAFFOLDER_obj;

typedef struct main
{
    char *exec_path;
} ES_metadata;

// ES_metadata *ES_metadata_create(char *argv[])
// {
//     ES_metadata *md_obj = malloc(sizeof(ES_metadata));
//     return md_obj;
// }


ELECTRON_SCAFFOLDER_obj *ELECTRON_SCAFFOLDER_create(char *argv[])
{
    int count = 0;
    ELECTRON_SCAFFOLDER_obj *es_obj = malloc(sizeof(ELECTRON_SCAFFOLDER_obj));
    // memset(es_obj, 0, sizeof(ELECTRON_SCAFFOLDER_obj));
    char *first_arg = argv[1];
    es_obj->relative_path = argv[0];
    es_obj->project_name = first_arg;
    es_obj->args_length = 0;
    es_obj->is_flat = false;
    es_obj->is_form = false;
    if(argv[2])
    {
        for(int i = 2; i < ES_ARGS_MAX_LENGTH; i++)
        {
            if(first_arg)
            {
                es_obj->args[count] = argv[i];
                if(strcmp(first_arg, ES_CMD_FLAT) == 0)
                {
                    es_obj->is_flat = true;
                }
                if(strcmp(first_arg, ES_CMD_FORM) == 0)
                {
                    es_obj->is_form = true;
                }
                count++;
                es_obj->args_length = count;
            }
        }
    }
    return es_obj;
}

void ELECTRON_SCAFFOLDER_clean(ELECTRON_SCAFFOLDER_obj *es_obj)
{   
    free(es_obj);
}

void ELECTRON_SCAFFOLDER_help(void)
{
    printf("\033[0;35m");
    printf("Usage: electron-scaffolder <project_name> [options]\n\n");
    printf("Options:\n");
    printf("\t%s, %s\t\tbuild the project in the current directory\n",
        ES_CMD_HELP, ES_CMD_SHORT_HELP);
    printf("\t%s, %s\t\toutput usage information\n",
    ES_CMD_FLAT, ES_CMD_SHORT_FLAT);
    printf("\t  Only <project_name> is requried.\n");
    printf("\033[0m");
}


int main(int argc, char *argv[])
{
    if(!argv[1])
    {
        printf("ERROR: Please specify the project directory\n");
        printf("\033[1;34m\telectron-scaffold <project_name>\033[0m\n");
        return EXIT_FAILURE;
    }

    if(strcmp(argv[1], ES_CMD_HELP) == 0 || strcmp(argv[1], ES_CMD_SHORT_HELP) == 0)
    {
        ELECTRON_SCAFFOLDER_help();
        return EXIT_SUCCESS;
    }
    ELECTRON_SCAFFOLDER_obj *es_obj = ELECTRON_SCAFFOLDER_create(argv);

    if(es_obj->project_name && es_obj->args_length)
    {
        
    }
    else    
    {
        /* __uninx__ system commands */
        /* Build the project in project name dir */
        char npm_es_root[ES_NPM_ROOT_MAX_LENGTH] = { 0 };
        char exec_root[ES_EXEC_ROOT_MAX_LENGTH] = { 0 };
        char copy_cmd[ES_COPY_CMD_MAX_LENGTH] = { 0 };
        char mkdir_project_name_cmd[ES_PROJECT_NAME_MAX_LENGTH] = { 0 };
        char *npm_root_cmd = "npm root -g";
        char *pwd_cmd = "pwd";
        #if defined(_WIN32) || defined(WIN32)
            char *cp_project_cmd = "copy ";
        #else
            char *cp_project_cmd = "cp -r -v ";
        #endif
        char *mkdir_cmd = "mkdir ";
        char *cp_project_dir_cmd = NULL;
        FILE *fp = NULL;
        FILE *fp2 = NULL;

        fp = popen(npm_root_cmd, "r");
        fscanf(fp, "%s", npm_es_root);
        fp2 = popen(pwd_cmd, "r");
        fscanf(fp2, "%s", exec_root);
        // Construct the copy command
        strcat(copy_cmd, cp_project_cmd);
        strcat(copy_cmd, npm_es_root);
        strcat(copy_cmd, ES_NPM_ROOT);
        strcat(copy_cmd, " ");
        strcat(copy_cmd, exec_root);
        if(!es_obj->is_flat)
        {
            #if defined(_WIN32) || defined(WIN32)
                strcat(copy_cmd, "\\");
            #else
                strcat(copy_cmd, "/");
            #endif
            strcat(copy_cmd, es_obj->project_name);
            strcat(mkdir_project_name_cmd, mkdir_cmd);
            strcat(mkdir_project_name_cmd, es_obj->project_name);
            printf("\033[0;34m");
            printf("Creating project directory %s\n", es_obj->project_name);
            printf("Executing %s\n", mkdir_project_name_cmd);
            printf("\033[0m");
            system(mkdir_project_name_cmd);
            printf("\033[0;34m");
            printf("Creating project...\n");
            printf("\033[0m");
            system(copy_cmd);
            printf("\033[0;34m");
            printf("Successfully created project!\n");
            printf("\033[0m");
        }
    }
    ELECTRON_SCAFFOLDER_clean(es_obj);
    return EXIT_SUCCESS;
}
