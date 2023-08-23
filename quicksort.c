#include<stdio.h>
#include<stdlib.h>
void quicksort(int arr[],int lb,int ub){
    
    int i=lb,t;
    int j=ub;
    int key=arr[lb];
    if(i>=j){
        return;
    }
    while(i<j){
        while(i<j && arr[i]<=key){
            i++;
        }
        while(arr[j]>key){
            j--;
        }
        if(i<j){
            t=arr[i];
            arr[i]=arr[j];
            arr[j]=t;
        }
    }
    arr[lb]=arr[j];
    arr[j]=key;
    quicksort(arr,lb,j-1);
    quicksort(arr,j+1,ub);
}
int main(){
    int n;
    printf("Enter no of elements :");
    scanf("%d",&n);
    int* arr=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    quicksort(arr,0,n-1);
    printf("The array after sorting is :\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}