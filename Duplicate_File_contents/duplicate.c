#include <stdio.h>
#include <stdlib.h>
#include <time.h> //for "still Duplicating" parameter
#include <errno.h> //for error detection/information
int duplicate(int argc, char *argv[]){ //argc # of arguments, *argv[] is pointer to first argument

if (argc > 3){ //check if too many arguments given
    printf("Too many arguments!\nusage: duplicate <sourcefile> <duplicateFile>\n");
    }
else{


    char first, sourceFile[50], duplicateFile[50]; //initiate file reading types
    FILE *source, *duplicated;
    int byteSize; //for counting copy size
    int errnum; //for getting error description
    source = fopen(argv[1], "r"); //sourcefile is first arguement, open it
    duplicated = fopen(argv[2], "w"); //target file is second argument
    if (source == NULL){ //if sourcefile didn't open do:
        errnum = errno; //get error number
        fprintf(stderr, "Value of errno: %d\n", errno); 
        perror("Error printed by perror");
        fprintf(stderr,"Error opening file: %s\n", strerror( errnum ));//get error type that corresponds to that error number
    }
    byteSize = 0;
    clock_t begin = clock(); //get internal clock ticks 
    double time_taken; //for calculating time in seconds
    int second = 1; //condition for printing "still duplicating"
    while( ( first = fgetc(source) ) != EOF ){ //do while the end of file is not reached
    
        byteSize++; //increment bytesize
        fputc(first, duplicated); //copy read character into targetfile
        clock_t now = clock(); //get time at this point for calculation
        time_taken = (double)(now - begin)/CLOCKS_PER_SEC; //get time taken in seconds
        if (time_taken > second){ // check if time is greater than 1 second from last time it was true (or just 1 second)
            printf("Still Duplicating...\ntime taken is %1.5f seconds\n", time_taken);
            second++; //since I only want if to be true every second, this condition needs to be incremented
        }
   
   }
   printf("Duplication Complete\nCopied: %d bytes from %s to %s\n", byteSize, argv[1], argv[2]); //print bytes and source and target

   fclose(source); //close files
   fclose(duplicated);

   return 0;
    }
}
