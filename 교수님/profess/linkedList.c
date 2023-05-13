#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define IS_EMPTY(first) (!(first))

typedef struct linkedList* linkPointer;
typedef struct linkedList{
    char data[4];
    linkPointer link;
}Node;



void attachData(linkPointer *first,linkPointer L, char *input){//pointer first if just for empty node, *for edit first pointer in main..
    linkPointer pointer = malloc(sizeof(Node));
    if(pointer == NULL){
        printf("The memory is full\n");
        exit(1);
    }
    strcpy(pointer->data,input);//1. 데이터 대입

    if(IS_EMPTY(first)){
        pointer->link = NULL;
        *first = pointer;  // first -> (main)first , replacing (main)fisrt to pointer;
    } else {
        pointer->link = L->link; //2. 다음 노드 주소 대입
        L->link = pointer; //3. 이전 노드 주소 대입
        //2,3순서가 바뀌면, 다음 노드의 주소값이 날라간다.
    }
    
}

void dettachData(linkPointer *first, linkPointer L, linkPointer M){
    if(L != NULL && L->link != NULL) //삭제할 노드의 왼쪽 노드와, 삭제할 노드의 존재 확인
        L->link = M->link;
    else // case for 1 remaining node
        *first = (*first)->link; //왜 그냥 NULL을 대입하지 않았을까?
    free(M);
}
linkPointer invert(linkPointer lead){
    linkPointer middle, trail;   //trail-middle-lead
    middle = NULL;
    while(lead){
        trail = middle;
        middle = lead;
        lead = lead->link; //칙칙폭폭   
        middle->link = trail; //inverting
    }return middle; //this gonna be lead
}


linkPointer concatenate(linkPointer ptr1, linkPointer ptr2){
    linkPointer temp;//임시 저장소

    if(!ptr1) return ptr2;
    if(!ptr2) return ptr1;// 둘 중 하나가 비어있는 경우

    for(temp = ptr1; temp->link; temp=temp->link); //temp가 ptr1의 끝 노드까지 이동
    temp->link = ptr2; //포인터 연결  

    return ptr1;
}

int main(){
    linkPointer first = NULL;

    first = (linkPointer)malloc(sizeof(Node));
    strcpy(first->data,"1");
    first->link = NULL;   

    attachData(&first,first,"2");
    dettachData(&first,first,first->link);
    printf("%s",first->data);

}