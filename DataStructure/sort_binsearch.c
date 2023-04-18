#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define     find_num_index(a)  loop_binary_search(arr, a, 0, 4)
#define SWAP(x,y,t)((t) = (x), (x) = (y), (y) = (t))
#define COMPARE(x,y) ((x)>(y) ? 1 : (x)==(y) ? 0 : -1)

//오름차순 정렬
void sort(int* arr, int size) {
    int min;
    int temp;
    for (int j = 0; j < size; j++)
    {
        min = j;
        for (int i = j + 1; i < size; i++)
        {
            if (arr[min] > arr[i])
                min = i;
        }
        SWAP(arr[j], arr[min], temp);
    }
}
int loop_binary_search(int* arr, int search_num, int start, int end) {
    while (start <= end) {
        int middle = (start + end) / 2;
        switch (COMPARE(arr[middle], search_num)) {
        case 1:
            end = middle - 1;
            break;
        case 0:
            return middle;
        case -1:
            start = middle + 1;
            break;
        }
    }
    return -1;
}
int recur_binary_search(int* arr, int search_num, int start, int end) {
 
    int middle = (start + end) / 2;
    if (!(start <= end))
        return -1;
    switch (COMPARE(arr[middle], search_num)) {
    case 1:
        recur_binary_search(arr, search_num, start, middle - 1);
        break;
    case 0:
        return middle;
    case -1:
        recur_binary_search(arr, search_num, middle + 1, end);
        break;
    }
}
   


int main() {
    int arr[5] = { 0,1,2,3,4 };
    int find_num, find_num_index, num;

    //printf("what do you wanna find?\n");
    //scanf_s("%d", &find_num);

    for (int i = -1; i < 6; i++) {
        num = find_num_index(i);
        if (num == -1) {
            printf("can't find the value\n");
            continue;
        }
        printf("%d\n", find_num_index(i));
    }

}