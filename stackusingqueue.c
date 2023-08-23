#include<stdio.h>
#define MAX 5
int dequeue(int[],int*,int*);
void enqueue(int[],int*,int*,int);
void push(int[],int*,int*,int);
void pop(int[],int*,int*);
int isEmpty(int ,int);
int isFull(int,int);
void display(int*,int*,int []);
int main(){
    int queue1[MAX];
    int start=-1;
    int end=-1;
    int ch=1,val;
    while(ch==1){
        printf("Enter the operation to be performed in stack :\n");
        printf("1 for push\n2 for pop\n3 for display:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter element to be pushed :");
            scanf("%d",&val);
            push(queue1,&start,&end,val);
            break;
        
        case 2:
            pop(queue1,&start,&end);
            break;
        case 3:
            display(&start,&end,queue1);
            break;
        default:
            printf("Invalid choice :\n");
            break;
        }
        printf("Want to continue (1/0):");
        scanf("%d",&ch);
    }
   


}
int isEmpty(int start,int end){
    if(start==-1 && end==-1){
        return 1;
    }
    return 0;
}
int isFull(int start,int end){
    if(end==MAX-1){
        return 1;
    }
    return 0;
}
void push(int queue1[],int* start,int* end,int val){
    if(isFull(*start,*end)){
        printf("The stack is full\n");
        return;
    }
    enqueue(queue1,start,end,val);
}
void pop(int queue1[],int* start,int* end){
    if(isEmpty(*start,*end)){
        printf("The stack is Empty\n");
        return;   
    }
    int count=0;
    int temp;
    for(int i=(*start);i<((*start)+(*end))/2;i++){
        temp=queue1[i];
        queue1[i]=queue1[(*end)-count];
        queue1[(*end)-count]=temp;
        count++;
    }
    int element=dequeue(queue1,start,end);
    printf("The popped Element is :%d\n",element);
    count=0;
    if(!isEmpty(*start,*end)){
        for(int i=*start;i<((*start)+(*end))/2;i++){
        temp=queue1[i];
        queue1[i]=queue1[(*end)-count];
        queue1[(*end)-count]=temp;
        count++;
    }
    }

}
void enqueue(int queue1[],int *start,int *end,int val){
    (*end)++;
    queue1[*end]=val;
    if(*start==-1){
        *start=*end;
    }
}
int dequeue(int queue1[],int* start,int* end){
    int element=queue1[*start];
    (*start)++;
    if((*start)>(*end)){
        *start=*end=-1;
    }
    return element;
}
void display(int* start,int* end,int queue1[]){
    if(isEmpty(*start,*end)){
        printf("The stack is Empty\n");
        return;   
    }
    int count=0;
    int temp;
    for(int i=(*start);i<((*start)+(*end))/2;i++){
        temp=queue1[i];
        queue1[i]=queue1[(*end)-count];
        queue1[(*end)-count]=temp;
        count++;
    }
    for(int i=*start;i<=*end;i++){
        printf("%d\n",queue1[i]);
    }
    count=0;
    if(!isEmpty(*start,*end)){
        for(int i=*start;i<((*start)+(*end))/2;i++){
        temp=queue1[i];
        queue1[i]=queue1[(*end)-count];
        queue1[(*end)-count]=temp;
        count++;
    }
    }
}