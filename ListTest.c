//-----------------------//
// Name: Ishaan Das      //
// CruzID: isdas         //
// Assignment Name: pa1  // 
//-----------------------//

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "List.h"


int main(int argc, char* argv[]){

    List A = newList();
    List B = newList();
    List C = NULL;
    int i;

    for(i=1; i<=20; i++){
        append(A,i);
        prepend(B,i);
    }

    int lenA = length(A);
    int lenB = length(B);

    printf("List A Length: %i\n", lenA);
    printf("List B Length: %i\n", lenB);

    printList(stdout,A); 
    printf("\n");

    printList(stdout,B); 
    printf("\n");

    for(moveFront(A); index(A)>=0; moveNext(A)){
        printf("%d ", get(A));
    }
    printf("\n");
    for(moveBack(B); index(B)>=0; movePrev(B)){
        printf("%d ", get(B));
    }
    printf("\n");

    C = copyList(A);
    printf("%s\n", equals(A,B)?"true":"false");
    printf("%s\n", equals(B,C)?"true":"false");
    printf("%s\n", equals(C,A)?"true":"false");


    moveFront(A);
    for(i=0; i<5; i++) {
        moveNext(A); 
        printf("Index: %d\n", index(A));
    }
    
    insertBefore(A, -1); 
    printList(stdout, A);
    printf("\n");


    for(i=0; i<9; i++) {
        moveNext(A); 
        printf("Index: %d\n", index(A));
    }


    insertAfter(A, -2);
    printList(stdout, A);
    printf("\n");

    

    for(i=0; i<5; i++) {
        movePrev(A);
        printf("Index: %d\n", index(A));
    } 

    delete(A);
    printList(stdout,A);
    printf("\n");


    deleteBack(A);
    printList(stdout, A);
    printf("\n");

    deleteFront(A);
    printList(stdout, A);
    printf("\n");


    printf("%d\n", length(A));
    clear(A);

    printf("%d\n", length(A));

    freeList(&A);
    freeList(&B);
    freeList(&C);

    return(0);
}

