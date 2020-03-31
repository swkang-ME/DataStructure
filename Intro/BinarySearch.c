#include <stdio.h>

int BSearch(int arr[], int len, int target)
{
    int first = 0;
    int last = len - 1;
    int mid;

    while(first <= last)
    {
        mid = (first + last)/2;

        if (target == arr[mid])
        {
            return mid;
        }
        else if (target < arr[mid])
        {
            last = mid - 1;
        }
        else
        {
            first = mid + 1;
        }
        
    }
    return -1;
    
}


int main()
{
    int arr[] = {1, 3, 5, 6, 7, 8, 10, 12, 14};
    int idx;

    idx = BSearch(arr, sizeof(arr)/sizeof(int), 10);

    if (idx == -1)
        printf("탐색 실패\n");
    else
        printf("타겟 저장 인덱스: %d\n", idx);
    

    idx = BSearch(arr, sizeof(arr)/sizeof(int), 4);

    if (idx == -1)
        printf("탐색 실패\n");
    else
        printf("타겟 저장 인덱스: %d\n", idx);

}