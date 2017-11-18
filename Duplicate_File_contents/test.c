#include <stdio.h>
#include <stdlib.h>
#include "duplicate.c"
int main(){
    int argc = 3; 
    char *argv[] = {"\0", "src.txt", "dupe.txt"}; //hard coded testing inputs

    duplicate(argc, argv); //pass arguments to duplicate function
}