#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct linkedList* linkPointer;
typedef struct linkedList{
    char data[4];
    linkPointer link;
}Nodes;
#define IS_EMPTY(first) (!(first))


void attachData(linkPointer address, char *input){
    linkPointer pointer = malloc(sizeof(Nodes));
    strcpy(pointer->data,input);
    pointer->link = NULL;
    address = pointer;
}

void dettachData(){

}


int main(){
    linkPointer first = NULL;
    

    first = (linkPointer)malloc(sizeof(Nodes));
    strcpy(first->data,"1");
    first->link = NULL;    
}