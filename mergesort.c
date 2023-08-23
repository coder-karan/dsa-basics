#include<stdio.h>
#include<stdlib.h>
void merge(int arr[],int temp[],int lb,int mid,int ub){
    int k=lb,le;
    int i=lb;
    le=mid-1;
    while(lb<=le && mid<=ub){
        if(arr[lb]<=arr[le]){
            temp[k]=arr[lb];
            k++;
            lb++;
        }
        else{
            temp[k]=arr[mid];
            k++;
            mid++;
        }
    }
    while(lb<=le){
        temp[k]=arr[lb];
        k++;
        lb++;
    }
    while(mid<=ub){
        temp[k]=arr[mid];
        mid++;
        k++;
    }
    for(i=0;i<ub;i++){
        arr[i]=temp[i];
    }
}
void mergesort(int arr[],int temp[],int lb,int ub){
    int mid;
    if(lb<ub){
        mid=(ub+lb)/2;
        mergesort(arr,temp,lb,mid);
        mergesort(arr,temp,mid+1,ub);
        merge(arr,temp,lb,mid+1,ub);
    }
}


int main(){
    int arr[5],temp[5];
    for(int i=0;i<5;i++){
        scanf("%d",&arr[i]);
    }
    printf("\n");
    mergesort(arr,temp,0,4);
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
}