/**
 *  ELECTRON SCAFFOLDER by Joe Gasewicz
 *  
 *  Electron with Typescript & React starter generator
 * 
 *  Contact joegasewicz@gmail.com
 **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ES_CMD_HELP "--help"
#define ES_CMD_SHORT_HELP "-h"
#define ES_CMD_FLAT "--flat"
#define ES_CMD_SHORT_FLAT "-f"
#define ES_CMD_FORM "--form"
#define ES_ARGS_MAX_LENGTH 2

typedef struct
{
    char *args[ES_ARGS_MAX_LENGTH];
    int args_length;
    char *project_name;
    char *relative_path;
} ELECTRON_SCAFFOLDER_obj;

ELECTRON_SCAFFOLDER_obj *ELECTRON_SCAFFOLDER_create(char *argv[])
{
    int count = 0;
    ELECTRON_SCAFFOLDER_obj *es_obj = malloc(sizeof(ELECTRON_SCAFFOLDER_obj));
    es_obj->relative_path = argv[0];
    es_obj->project_name = argv[1];
    es_obj->args_length = 0;
    if(argv[2])
    {
        for(int i = 2; i < ES_ARGS_MAX_LENGTH; i++)
        {
            if(argv[i])
            {
                es_obj->args[count] = argv[i];
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
        /* Build the project in project name dir */

    }
    
    ELECTRON_SCAFFOLDER_clean(es_obj);
    return EXIT_SUCCESS;
}
