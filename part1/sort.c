#include <stdio.h>
#include <stdlib.h>
#define swap(x,y,t)((t) = (x), (x) = (y), (y) = (x))
//오름차순 정렬
int* sort(int *arr){
    int min = arr[0];
    int temp;
    for(int j = 0; j < sizeof(arr)/sizeof(int)-1 ; j++)
    {    for(int i = 0; i < sizeof(arr)/sizeof(int) -1; i++)
        {
            if(arr[i] > arr[i+1])
                min = arr[i+1];
            swap(arr[i], min, temp);
        }
    }

    return arr;
}



int main(){
    int *not_sorted_arr;
    int *sorted_arr;
    int n;

    printf("size of array\n");
    scanf("%d",&n);
    not_sorted_arr = (int*)malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++)
        scanf("%d",&not_sorted_arr[i]);
    sorted_arr = sort(not_sorted_arr);
    for(int i = 0; i < n; i++)
        printf("%d ", sorted_arr[i]);
}