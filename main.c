#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ELECTRON_SCAFFOLDER_CMD_HELP " --help"
#define ELECTRON_SCAFFOLDER_CMD__SHORT_HELP " -h"
#define ELECTRON_SCAFFOLDER_CMD_FLAT " --flat"
#define ELECTRON_SCAFFOLDER_CMD_SHORT_FLAT " -f"

typedef struct
{
    char *relative_path;
} ELECTRON_SCAFFOLDER_obj;

ELECTRON_SCAFFOLDER_obj *ELECTRON_SCAFFOLDER_create(char *argv[])
{
    ELECTRON_SCAFFOLDER_obj *es_obj = malloc(sizeof(ELECTRON_SCAFFOLDER_obj));
    es_obj->relative_path = argv[0];
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
    printf("\t-f, --flat\t\tbuild the project in the current directory\n");
    printf("\t-h, --help\t\toutput usage information\n");
    printf("\t  Only <project_name> is requried.\n");
    printf("\033[0m");
}


int main(int argc, char *argv[])
{
    if(!argv[1])
    {
        printf("ERROR: Please specify the project directory\n");
        printf("\033[1;34m\telectron-scaffold <project_name>\033[0m\n");
        return 0;
    }
    if(strcmp(argv[1], ELECTRON_SCAFFOLDER_CMD_HELP))
    {
        ELECTRON_SCAFFOLDER_help();
        return 0;
    }
    ELECTRON_SCAFFOLDER_obj *es_obj = ELECTRON_SCAFFOLDER_create(argv);
    ELECTRON_SCAFFOLDER_clean(es_obj);

    return 0;
}
