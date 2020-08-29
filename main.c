#include <stdio.h>
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
    printf("Help:\n --help\n");
}


int main(int argc, char *argv[])
{
    if(strcmp(argv[1], ELECTRON_SCAFFOLDER_CMD_HELP))
    {
        ELECTRON_SCAFFOLDER_help();
        return 0;
    }
    ELECTRON_SCAFFOLDER_obj *es_obj = ELECTRON_SCAFFOLDER_create(argv);
    ELECTRON_SCAFFOLDER_clean(es_obj);

    return 0;
}
