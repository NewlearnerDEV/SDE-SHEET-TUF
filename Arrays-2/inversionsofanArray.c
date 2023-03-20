#include <stdio.h>
int merge(int arr[], int x, int y, int z)
{  int ans=0;
    int n1 = y - x + 1;
    int n2 = z - y;
    int temp1[n1];
    int temp2[n2];
    for (int i = 0; i < n1; i++)
    {
        temp1[i] = arr[x + i];
    }
    for (int i = 0; i < n2; i++)
    {
        temp2[i] = arr[y + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = x;
    while (i < n1 && j < n2)
    {
        if (temp1[i] < temp2[j])
        {
            arr[k] = temp1[i];
            i++;
        }
        else
        {   
            ans+=y-x;
            arr[k] = temp2[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = temp1[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = temp2[j];
        j++;
        k++;
    }
}
int mergesort(int arr[], int a, int b)
{   int ans=0;
    if (a < b)
    {
        int mid = (a + b) / 2;
        ans+=mergesort(arr, a, mid);
        ans+=mergesort(arr, mid + 1, b);
        ans+=merge(arr, a, mid, b);
    }
    return ans;
}

int main()
{
    int n;
    printf("Enter number of elements in an array\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Before sorting elements are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d \t", arr[i]);
    }
    int x=mergesort(arr, 0, n - 1);
    printf("\n");
    printf("After sorting elements are:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d \t", arr[i]);
    }
    printf("inversions are %d",x);
    return 0;
}