#include <stdio.h>
#define MAX 10


int isEmpty(int);

int isFull(int);
void push(int [],int*);
void pop(int[],int*);
void peek(int[],int*);
void display(int[],int);


int main()
{
    int arr[MAX], top = -1;
    int n;
    push(arr,&top);
    push(arr,&top);
    pop(arr,&top);
    display(arr, top);
    return 0;
}


int isEmpty(int top)
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(int top)
{
    if (top == MAX-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(int arr[], int *top)
{
    if (isFull(*top))
    {
        printf("Stack is full!!");
        
    }
    else
    {
        int element;
        printf("Enter element :");
        scanf("%d", &element);
        (*top)++;
        arr[*top] = element;

    }
}
void pop(int arr[], int* top)
{
    
    if (isEmpty(*top))
    {
        printf("Stack is empty!!\n");

    }
    else
    {
        printf("Element popped %d\n", arr[*top]);
        (*top)=(*top)-1;

    }
}
void display(int arr[], int top)
{
    if (isEmpty(top))
    {
        printf("Stack is Empty!!");
    }
    else
    {
        while (top != -1)
        {
            printf("%d\n", arr[top]);
            top--;
        }
    }
}

void peek(int arr[], int* top)
{
    if (isEmpty)
    {
        printf("STack is Empty!!!");
    }
    else
    {
        printf("Peeked element is %d ", arr[*top]);
    }
}



