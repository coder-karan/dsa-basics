#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
void push(node**,int);
void pop(node**);
void display(node*);
void peek(node*);
int main(){
    node* head=NULL;
    int ch=1,val;
    while(ch==1){
        printf("Enter the operation to be performed in stack :\n");
        printf("1 for push\n2 for pop\n3 for peek\n4 for display:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter element to be pushed :");
            scanf("%d",&val);
            push(&head,val);
            break;
        
        case 2:
            pop(&head);
            break;
        case 3:
            peek(head);
            break;
        case 4:
            display(head);
            break;
        default:
            printf("Invalid choice :\n");
            break;
        }
        printf("Want to continue (1/0):");
        scanf("%d",&ch);
    }
}
void push(node** head,int val){
    node* p=(node*)malloc(sizeof(node));
    p->data=val;
    if(*head==NULL){
        *head=p;
        (*head)->next=NULL;
        return;
    }
    
    p->next=*head;
    *head=p;

}
void pop(node** head){
    if(*head==NULL){
        printf("The stack is empty\n");
        return;
    }
    int element;
    element=(*head)->data;
    *head=(*head)->next;
    printf("Popped element is :%d\n",element);
}
void display(node* head){
    if(head==NULL){
        printf("The stack is empty \n");
        return;
    }
    node* temp=head;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
void peek(node* head){
    if(head==NULL){
        printf("The stack is empty\n");
        return;
    }
    printf("The peak element is : %d\n",head->data);


}