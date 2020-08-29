#include <stdio.h>
#include <string.h>

#define ELECTRON_SCAFFOLDER_HELP_CMD " --help"

// --help commands

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

void ELECTRON_SCAFFOLDER_help(void)
{
    printf("Help:\n --help\n");
}


int main(int argc, char *argv[])
{
    if(strcmp(argv[1], ELECTRON_SCAFFOLDER_HELP_CMD))
    {
        ELECTRON_SCAFFOLDER_help();
        return 0;
    }
    // get path
    ELECTRON_SCAFFOLDER_obj *es_obj = ELECTRON_SCAFFOLDER_create(argv);

    // add e-scaffolder to .bash_profile

    // get users install path

    // get user args
    
    // 
    return 0;
}
