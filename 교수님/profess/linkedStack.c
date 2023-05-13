#define MAX_STACK 10
#include <stdlib.h>
#include <stdio.h>

typedef struct _element *ptr;
typedef struct _element{
    int data;
    //etc
}element;

typedef struct _linkedStack *structPointer; 

typedef struct _linkedStack{
    element item;
    structPointer link;
}linkedStack;

structPointer top[MAX_STACK];


void addQueue(structPointer *top, element _item){//top값을 변경해야 하니 더블포인터 사용
    structPointer temp = malloc(sizeof(linkedStack));//포인터를 사용하여 동적으로 구조체 공간 할당
    if(temp == NULL){
        printf("Memory is full\n");
        exit(1);
    }

    temp->item = _item;
    temp->link = *top;
    *top = temp;
}

void push(int i, element _item){
    addQueue(&top[i], _item);
}

element deleteQueue(structPointer *top){
    structPointer temp = *top;
    element item; //정적 구조체 공간 할당, 동적으로 할당할 필요가 없음(한번 만들어 놓고 계속 사용)
    if(temp == NULL){
        printf("Stack is empty\n");
        exit(1);
    }
    item = temp->item;
    *top = temp->link;
    free(temp);
    return item;
}
element pop(int i){
    return deleteQueue(&top[i]);
}

int main(){
    return 0;
}