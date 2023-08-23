#include<stdio.h>
#define MAX 5
void push(int[],int*,int);
int pop(int[],int*);
void enqueue(int[],int*,int);
void dequeue(int[],int[],int*,int*);
void display(int[],int[],int*,int*);

int main(){
    int stack1[MAX];
    int stack2[MAX];
    int top1=-1;
    int top2=-1;
    
    int ch=1,val;
    while(ch==1){
        printf("Enter the operation to be performed in queue :\n");
        printf("1 for enqueue\n2 for dequeue\n3 for display:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter element to be pushed :");
            scanf("%d",&val);
            enqueue(stack1,&top1,val);
            break;
        
        case 2:
            dequeue(stack1,stack2,&top1,&top2);
            break;
        
        case 3:
            display(stack1,stack2,&top1,&top2);
            break;
        default:
            printf("Invalid choice :\n");
            break;
        }
        printf("Want to continue (1/0):");
        scanf("%d",&ch);
    }
    
}

int isEmpty(int top){
    if(top==-1){
        return 1;
    }
    return 0;
}
int isFull(int top){
    if(top==MAX-1){
        return 1;
    }
    return 0;
}
void push(int arr[],int* top,int val){
    (*top)++;
    arr[*top]=val;
}
int pop(int arr[],int* top){
    int element=arr[*top];
    (*top)--;
    return element;
} 
void display(int stack1[],int stack2[],int* top1,int* top2){
    if(isEmpty(*top1)){
        printf("The queue is empty");
        return;
    }
     if(isEmpty(*top2)){
        while(!isEmpty(*top1)){
            int element=pop(stack1,top1);
            push(stack2,top2,element);
        }
        printf("The queue is:\n");
        while(!isEmpty(*top2)){
            int element=pop(stack2,top2);
            printf("%d\n",element);
            push(stack1,top1,element);
        }
    }


}
void enqueue(int stack1[],int* top1,int val){
    if(isFull(*top1)){
        printf("The queue is full\n");
        return;
    }
    push(stack1,top1,val);
}

void dequeue(int stack1[],int stack2[],int* top1,int * top2){
    if(isEmpty(*top1)&& isEmpty(*top2)){
        printf("The queue is empty");
        return;
    }
    if(isEmpty(*top2)){
        while(!isEmpty(*top1)){
            int element=pop(stack1,top1);
            push(stack2,top2,element);
        }
        int element=pop(stack2,top2);
        printf("The dequeued element is : %d\n",element);
        while(!isEmpty(*top2)){
            int element=pop(stack2,top2);
            push(stack1,top1,element);
        }
    }
}