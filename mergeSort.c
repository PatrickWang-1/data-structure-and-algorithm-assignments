#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
void merge(int arr[],int left,int mid,int right){
    int l_len=mid-left+1;
    int r_len=right-mid;
    int l_temp[l_len];
    int r_temp[r_len];
    int i,j,k;
    for (i=0;i<l_len;i++){
        l_temp[i]=arr[left+i];
    }
    for (i=0;i<r_len;i++){
        r_temp[i]=arr[mid+1+i];
    }
    for (i=0,j=0,k=left;k<=right;k++)
    {
        if ((i<l_len)&&((j>=r_len)||(l_temp[i]<r_temp[j]))){
            arr[k]=l_temp[i];
            i++;
        }else{
            arr[k]=r_temp[j];
            j++;
        }
    }
}
void mergeSort(int arr[],int left, int right) {
    if (left<right){
        int mid=(left+right-1)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}
void temp(int arr[],int arrLen){
    mergeSort(arr,0,arrLen-1);
}
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
    for (i=0;i<10;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    start=clock();
    temp(a,arrLen_a);
    end=clock();
    double time_used_a=((double)end-start)/CLOCKS_PER_SEC;
    for (i=0;i<arrLen_a;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\ntime_used_10: %lf",time_used_a);
    
    start=clock();
    temp(b,arrLen_b);
    end=clock();
    double time_used_b=((double)end-start)/CLOCKS_PER_SEC;
    printf("\ntime_used_100: %lf",time_used_b);

    start=clock();
    temp(c,arrLen_c);
    end=clock();
    double time_used_c=((double)end-start)/CLOCKS_PER_SEC;
    printf("\ntime_used_1000: %lf",time_used_c);

    start=clock();
    temp(d,arrLen_d);
    end=clock();
    double time_used_d=((double)end-start)/CLOCKS_PER_SEC;
    printf("\ntime_used_10000: %lf",time_used_d);

    start=clock();
    temp(e,arrLen_e);
    end=clock();
    double time_used_e=((double)end-start)/CLOCKS_PER_SEC;
    printf("\ntime_used_100000: %lf",time_used_e);
}