//-----------------------//
// Name: Ishaan Das      //
// CruzID: isdas         //
// Assignment Name: pa1  // 
//-----------------------//


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include "List.h"

#define OPTIONS "i:o:"

int main (int argc, char *argv[]) {

    FILE *in;
    FILE *out;


    if( argc != 3 ){
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        exit(1);
    }

    // open files for reading and writing 
    in = fopen(argv[1], "r");
    if ( in==NULL ){
        printf("Unable to open file %s for reading\n", argv[1]);
        exit(1);
    }

    out = fopen(argv[2], "w");
    if( out==NULL ){
        printf("Unable to open file %s for writing\n", argv[2]);
        exit(1);
    }


    int lines = 0;
    for (char c = getc(in); c != EOF; c = getc(in)) {
        if (c == '\n') {
            lines += 1;
        }
    }
    rewind(in);

    //creates array of size lines
    char **wordList = calloc(lines, sizeof(char *));
    for (int i = 0; i < lines; i++) {
        wordList[i] = calloc(300, sizeof(char));
    }


    //char buffer[300];

    //int numLines = 0;
    //while (fscanf(in, "%s", wordList[numLines]) != EOF) {
    //    numLines++;
    //}
    for (int i = 0; i < lines; i++) {
        //fscanf(in, "%s", wordList[i]);
        fgets(wordList[i], 300, in);
    }



    //for (int i = 0; i < lines; i++) {
    //    printf("%s\n", wordList[i]);
    //}

    //creating the linked list that will be sorted
    List sorted = newList();

    for (int i = 0; i < lines; i++) {
        if (i == 0) {
            append(sorted, i);
            moveFront(sorted);
        } else {
            int first = front(sorted);
            int last = back(sorted);
            if (strcmp(wordList[i], wordList[first]) <= 0){
                //printf("made prepend\n");
                prepend(sorted, i);
                moveFront(sorted);
            } else if (strcmp(wordList[i], wordList[last]) >= 0) {
                //printf("made append\n");
                append(sorted, i);
                moveFront(sorted);
            } else {
                while (1) {
                    //printf("Current: %i\n", cursorIndex(sorted));
                    int cursInd = get(sorted);
                    //moveNext(sorted);
                    //printf("Next: %i\n", cursorIndex(sorted));
                    //int cursNextInd = get(sorted);
                    if (strcmp(wordList[i], wordList[cursInd]) <= 0) {
                        //printf("before insert\n");
                        insertBefore(sorted, i);
                        //printf("after insert\n");
                        break;
                    }
                    moveNext(sorted);
                }
                moveFront(sorted);
            }
        }
    }

    int len = length(sorted);
    moveFront(sorted);
    for (int i = 0; i < len; i++) {
        int got = get(sorted);
        fprintf(out, "%s\n", wordList[got]);
        moveNext(sorted);
    }

    fclose(in);
    fclose(out);
    freeList(&sorted);
    for (int i = 0; i < lines; i++) {
        free(wordList[i]);
    }    
    free(wordList);

        return 0;

}

