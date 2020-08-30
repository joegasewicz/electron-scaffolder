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
#define DEBUG 1


typedef struct
{
    char *args[ES_ARGS_MAX_LENGTH]; // TODO remove if not used
    int args_length;
    char *project_name;
    bool is_flat;
    bool is_form;
} ELECTRON_SCAFFOLDER_obj;

typedef struct main
{
    char *project_src;
    char *poject_dest;

} ES_metadata;

ES_metadata *ES_metadata_create(char *argv[])
{
    ES_metadata *md_obj = malloc(sizeof(ES_metadata));
    return md_obj;
}

ELECTRON_SCAFFOLDER_obj *ELECTRON_SCAFFOLDER_create(char *argv[])
{
    int count = 0;
    ELECTRON_SCAFFOLDER_obj *es_obj = malloc(sizeof(ELECTRON_SCAFFOLDER_obj));
    char *first_arg = argv[1];
    char *second_arg = argv[2];
    es_obj->project_name = first_arg;
    es_obj->args_length = 0;
    es_obj->is_flat = false;
    es_obj->is_form = false;
    if(second_arg)
    {
        for(int i = 2; i <= ES_ARGS_MAX_LENGTH; i++)
        {
            es_obj->args[count] = argv[i];
            if(strcmp(argv[i], ES_CMD_FLAT) == 0 || strcmp(argv[i], ES_CMD_SHORT_FLAT) == 0)
            {
                es_obj->is_flat = true;
            }
            if(strcmp(argv[i], ES_CMD_FORM) == 0)
            {
                es_obj->is_form = true;
            }
            count++;
            es_obj->args_length = count;
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

void ES_create_project_src(char *npm_es_root)
{
    char *npm_root_cmd = "npm root -g";
    FILE *fp = NULL;
    fp = popen(npm_root_cmd, "r");
    fscanf(fp, "%s", npm_es_root);
    #ifdef DEBUG
        printf("\033[0;33m");
        printf("DEBUG src root: %s\n", npm_es_root);
        printf("\033[0m");
    #endif
}

void ES_create_project_dest(ELECTRON_SCAFFOLDER_obj *es_obj, char *exec_root)
{
        char *pwd_cmd = "pwd";
        FILE *fp = NULL;
        fp = popen(pwd_cmd, "r");
        fscanf(fp, "%s", exec_root);
        #ifdef DEBUG
            printf("\033[0;33m");
            printf("DEBUG exec root: %s\n", exec_root);
            printf("\033[0m");
        #endif
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
    // ES_metadata *es_meta = ES_metadata_create();
    /* Build the project in project name dir */
    char *P_npm_es_root = (char *)malloc(ES_NPM_ROOT_MAX_LENGTH * sizeof(char));
    char *P_exec_root = (char *)malloc(ES_EXEC_ROOT_MAX_LENGTH * sizeof(char));
    char copy_cmd[ES_COPY_CMD_MAX_LENGTH] = { 0 };
    char mkdir_project_name_cmd[ES_PROJECT_NAME_MAX_LENGTH] = { 0 };
    // char *pwd_cmd = "pwd";
    #if defined(_WIN32) || defined(WIN32)
        char *cp_project_cmd = "copy ";
    #else
        char *cp_project_cmd = "cp -r -v ";
    #endif
    char *mkdir_cmd = "mkdir ";
    char *cp_project_dir_cmd = NULL;

    ES_create_project_src(P_npm_es_root);
    ES_create_project_dest(es_obj, P_exec_root);

    // Construct the copy command
    strcat(copy_cmd, cp_project_cmd);
    strcat(copy_cmd, P_npm_es_root);
    strcat(copy_cmd, ES_NPM_ROOT);
    strcat(copy_cmd, " ");
    strcat(copy_cmd, P_exec_root);
    #if defined(_WIN32) || defined(WIN32)
        strcat(copy_cmd, "\\");
    #else
        strcat(copy_cmd, "/");
    #endif
    if(es_obj->is_flat != true)
    {
        strcat(copy_cmd, es_obj->project_name);
    }
    strcat(mkdir_project_name_cmd, mkdir_cmd);
    if(es_obj->is_flat != true)
    {
        strcat(mkdir_project_name_cmd, es_obj->project_name);
        printf("\033[0;34m");
        printf("Creating project directory %s\n", es_obj->project_name);
        printf("Executing %s\n", mkdir_project_name_cmd);
        printf("\033[0m");
        system(mkdir_project_name_cmd);
    }
    printf("\033[0;34m");
    printf("Creating project...\n");
    printf("\033[0m");
    system(copy_cmd);
    printf("\033[0;34m");
    printf("Successfully created project!\n");
    printf("\033[0m");
    // Clean up!
    free(P_npm_es_root);
    free(P_exec_root);

    ELECTRON_SCAFFOLDER_clean(es_obj);
    return EXIT_SUCCESS;
}
