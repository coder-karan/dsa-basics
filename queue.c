#include<stdio.h>

#define MAX 1

int isFull(int);

int isEmpty(int);
void enqueue(int[],int*,int*);
void dequeue(int[],int*,int*);

void display(int[],int,int);

void peek(int[]);


int main(){
    int arr[MAX];
    int start=-1,end=-1;
    enqueue(arr,&start,&end);
    enqueue(arr,&start,&end);
    
    display(arr,start,end);

    dequeue(arr,&start,&end);

    display(arr,start,end);

    dequeue(arr,&start,&end);

    display(arr,start,end);

    dequeue(arr,&start,&end);


}

int isFull(int end){
    if(end==MAX-1){
        return 1;
    }
    return 0;
}
int isEmpty(int start){
    if(start==-1){
        return 1;
    }
    return 0;
}


void enqueue(int arr[],int* start,int* end){
    if(isFull(*end)){
        printf("The queueu is full\n");
        return;
    }
    (*end)++;
    int k;
    printf("Enter element:");
    scanf("%d",&k);
    arr[*end]=k;
    if(*start==-1){
        *start=*end;
    }

    
}



void dequeue(int arr[],int * start,int * end){
    if(isEmpty(*start)){
        printf("queue is empty\n");
        return;
    }
    else{
        printf("Dequeed element is %d\n",arr[*start]);
    (*start)++;
    if(*start>*end){
        *start=-1;*end=-1;
    }
    }
    
}


void display(int arr[],int start,int end){
    if(isEmpty(start)){
        printf("The queue is empty\n");
        return;
    }
    while(start<=end){
        printf("%d ",arr[start]);
        start++;
    }
    printf("\n");
}