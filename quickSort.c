#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
void quickSort(int arr[],int left,int right);
void swap(int* a,int* b);
int sort(int arr[],int l,int r);
int main(){
    clock_t start,end;
    int i,arrLen_a,arrLen_b,arrLen_c,arrLen_d,arrLen_e;
    int a[10],b[100],c[1000],d[10000],e[100000];
    srand((unsigned int)time(NULL));
    for (i=0;i<10;i++){
        a[i]=rand()%10;
    }
    for (i=0;i<100;i++){
        b[i]=rand()%100;
    }
    for (i=0;i<1000;i++){
        c[i]=rand()%1000;
    }
    for (i=0;i<10000;i++){
        d[i]=rand()%10000;
    }
    for (i=0;i<100000;i++){
        e[i]=rand()%100000;
    }
    arrLen_a=sizeof(a)/sizeof(a[0]);
    arrLen_b=sizeof(b)/sizeof(b[0]);
    arrLen_c=sizeof(c)/sizeof(c[0]);
    arrLen_d=sizeof(d)/sizeof(d[0]);
    arrLen_e=sizeof(e)/sizeof(e[0]);
    for (i=0;i<arrLen_a;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    start=clock();
    quickSort(a,0,arrLen_a-1);
    end=clock();
    double time_used_a=((double)end-start)/CLOCKS_PER_SEC;
    for (i=0;i<arrLen_a;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\ntime_used_10: %lf",time_used_a);
    
    start=clock();
    quickSort(b,0,arrLen_b-1);
    end=clock();
    double time_used_b=((double)end-start)/CLOCKS_PER_SEC;
    printf("\ntime_used_100: %lf",time_used_b);

    start=clock();
    quickSort(c,0,arrLen_c-1);
    end=clock();
    double time_used_c=((double)end-start)/CLOCKS_PER_SEC;
    printf("\ntime_used_1000: %lf",time_used_c);

    start=clock();
    quickSort(d,0,arrLen_d-1);
    end=clock();
    double time_used_d=((double)end-start)/CLOCKS_PER_SEC;
    printf("\ntime_used_10000: %lf",time_used_d);

    start=clock();
    quickSort(e,0,arrLen_e-1);
    end=clock();
    double time_used_e=((double)end-start)/CLOCKS_PER_SEC;
    printf("\ntime_used_100000: %lf",time_used_e);
    return 0;
}
void swap(int* a,int* b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void quickSort(int arr[],int left,int right){
    if (left>=right){
        return;
    }
    int stop=sort(arr,left,right);
    quickSort(arr,left,stop-1);
    quickSort(arr,stop+1,right);
}
int sort(int arr[],int l,int r){
    int i=l;
    int j=r;
    int pivot=l;
    while (i<j) {
        while (i<j&&arr[j]>=arr[pivot])
            j--;
        while (i<j&&arr[i]<=arr[pivot])
            i++;
        swap(&arr[j], &arr[i]);
    }
    int stop=i;
    swap(&arr[stop],&arr[pivot]);
    return stop;
}