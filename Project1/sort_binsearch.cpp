#include <stdio.h>
#include <stdlib.h>
#define swap(x,y,t)((t) = (x), (x) = (y), (y) = (t))

//오름차순 정렬
void sort(int* arr, int size) {
    int min;
    int temp;
    for (int j = 0; j < size; j++)
    {
        min = j;
        for (int i = j+1 ; i < size; i++)
        {
            if ( arr[min] > arr[i])
                min = i;
        }
        swap(arr[j], arr[min], temp);
    }
}
//int binary_search(int* arr,int search_num ,int start, int end) {
//    int middle = (start + end) / 2; // 5/2 = 2
//    if (search_num < arr[middle]) {
//        binary_search(arr, search_num, 0, middle - 1);
//    }
//    else if (arr[middle] < search_num) {
//        binary_search(arr, search_num, middle + 1, end);
//    }
//    else if (arr[middle] == search_num)
//        return middle;//index
//    else
//        return -1;
//}
int binary_search(int* arr, int search_num, int left, int right) {
    
    while (left <= right) {
        int middle = (left + right) / 2;
        if (search_num < arr[middle]) {
            right = middle - 1;
        }
        else if (search_num > arr[middle]) {
            left = middle + 1;
        }
        else if (search_num == arr[middle])
            return middle;
    }
    return -1;
}


int main() {
    int arr[5] = { 0,1,2,3,4 };
    int find_num, find_num_index;

    //int* arr;
    //int n, temp;
    //printf("size of array\n");
    //scanf_s("%d", &n);
    //arr = (int*)malloc(sizeof(int) * n);
    //for (int i = 0; i < n; i++)
    //    scanf_s("%d", &arr[i]);
    //sort(arr,n);
    //for (int i = 0; i < n; i++)
    //    printf("%d ", arr[i]);

    printf("what do you wanna find?\n");
    scanf_s("%d", &find_num);
    find_num_index = binary_search(arr, find_num, 0, 4);
    if (find_num_index == -1) {
        printf("can't find file\n");
        exit(-1);
    }
    printf("arr[%d] = %d\n", find_num_index, arr[find_num_index]);

    
}