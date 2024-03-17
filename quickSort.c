#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
void quick_sort(int arr[],int s,int l);
void swap(int a,int b);
int part(int arr[],int s,int l);
int main(){
    int i,arrLen_a;
    int a[10];
    srand((unsigned int)time(NULL));
    for (i=0;i<10;i++){
        a[i]=rand()%10;
    }
    arrLen_a=sizeof(a)/sizeof(a[0]);
    for (i=0;i<10;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    quick_sort(a,0,arrLen_a);
    for (i=0;i<arrLen_a;i++)
    {
        printf("%d ",a[i]);
    }
}
void swap(int a,int b){
    int t=a;
    a=b;
    b=t;
}
int part(int arr[],int s,int l){
    int pivot=arr[l];
    int count=0;
    for (int i=s;i<l;i++){
        if (arr[i]<pivot){
            count++;
        }
    }
    swap(arr[count],arr[l]);
    return count;
}
void quick_sort(int arr[],int s,int l){
    if (s<l){
        int temp=part(arr,s,l);
        quick_sort(arr,s,temp-1);
        quick_sort(arr,temp+1,l);
    }
}