#define MAX_QUEUE 10
#define NULL 0
#define TRUE 1
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

structPointer front[MAX_QUEUE] = {NULL,};
structPointer rear[MAX_QUEUE] = {NULL, };//중간 element의 접근을 위해 인덱싱


void addQueue(structPointer *front, structPointer *rear, element _item){
    structPointer temp = malloc(sizeof(linkedStack));
    temp->item = _item;
    temp->link = NULL;
    //큐가 비어있는 경우
    if(!*front){
        *front = temp;
    } else {
        (*rear)->link = temp;// in와 temp를 이어주기
    }
    *rear = temp;//새로운 in포인터
}

void add(int i, element _item){
    addQueue(&front[i],&rear[i], _item); //인자가 다른 함수 본인을 호출(위의 addqueue)
}

element deleteQueue(structPointer *front){
    structPointer temp = *front;
    element item;
    if(!*front){
        printf("queue is empty\n");
        exit(1);
    }
    item = temp->item;
    *front = temp->link;
    free(temp);
    return item;
}

element delete(int i){
    return deleteQueue(&front[i]);
}

int main(){
    element first;
    first.data = 1;
    element second;
    second.data = 2;
    element third;
    third.data = 3;
    add(0,first);
    add(1,second);
    add(2,third);
    printf("%d\n",delete(1).data);
    printf("%d\n",delete(2).data); //3번째 원소 pop
    printf("%d\n",delete(0).data); 
    return 0;
}