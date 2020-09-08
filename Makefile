# -------------------------------------
# Dependencies
# 	- Progressbar:
# 		https://github.com/doches/progressbar
STATIC_LIB_PATH=/usr/local/lib
STATIC_LIB_HEADER_FILE_PATH=/usr/local/lib

default: bin

bin: electron_scaffolder.c
	gcc electron_scaffolder.c -L$(STATIC_LIB_PATH) -lprogressbar -I$(STATIC_LIB_HEADER_FILE_PATH) -o bin
