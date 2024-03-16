#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
void merge(int arr[],int arrLen);
void mergeSort(int arr[],int left,int right,int temp[]);
int main(){
    int i;
    int a[10];
    srand((unsigned int)time(NULL));
    for (i=0;i<10;i++){
        a[i]=rand()%10;
    }
    for (i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }
    mergeSort(a,10);
    for (i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }
}
void merge(int arr[],int arrLen){
    int temp[arrLen];
    mergeSort(arr,0,arrLen-1,temp);
}
void mergeSort(int arr[], int left, int right, int temp[]){
    int m;
    if (arrLen>1)
    {
        m=(int)(floor(arrLen/2));

    }

}
