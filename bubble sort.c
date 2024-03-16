#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
void bubbleSort(int arr[],int arrLen);
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
    bubbleSort(a,arrLen_a);
    end=clock();
    double time_used_a=((double)end-start)/CLOCKS_PER_SEC;
    for (i=0;i<arrLen_a;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\ntime_used_10: %lf",time_used_a);
    
    start=clock();
    bubbleSort(b,arrLen_b);
    end=clock();
    double time_used_b=((double)end-start)/CLOCKS_PER_SEC;
    printf("\ntime_used_100: %lf",time_used_b);

    start=clock();
    bubbleSort(c,arrLen_c);
    end=clock();
    double time_used_c=((double)end-start)/CLOCKS_PER_SEC;
    printf("\ntime_used_1000: %lf",time_used_c);

    start=clock();
    bubbleSort(d,arrLen_d);
    end=clock();
    double time_used_d=((double)end-start)/CLOCKS_PER_SEC;
    printf("\ntime_used_10000: %lf",time_used_d);

    start=clock();
    bubbleSort(e,arrLen_e);
    end=clock();
    double time_used_e=((double)end-start)/CLOCKS_PER_SEC;
    printf("\ntime_used_100000: %lf",time_used_e);
}
void bubbleSort(int arr[],int arrLen)
{
    int i,j,temp;
    for (i=0;i<arrLen;i++){
        for (j=0;j<arrLen-i-1;j++){
            if (arr[j]>arr[j+1]){
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}