#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
void insertAtTail(node** head,int val);
void insertAtHead(node** head,int val);
void insertAtPosition(node**  head,int val,int pos);
void display(node* head);
void deletionAtHead(node** head);
void deletionAtTail(node** head);
void deletionAtPosition(node** head,int pos);

int main(){
    node* head=NULL;
    int ch=1,val;
    while(ch==1){
        printf("Enter the operation to be performed in linked list :\n");
        printf("1 for insertion\n2 for deletion\n3 for display\n4 for searching:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter 1 for insertion at head\n2 for insertion at tail\n3 for insertion at position");
            scanf("%d",&ch);
            printf("Enter value to be inserted:");
            scanf("%d",&val);
            if(ch==1){
                insertAtHead(&head,val);
            }
            else if(ch==2){
                insertAtTail(&head,val);
            }
            else if(ch==3){
                printf("Ente rthe position:");
                scanf("%d",ch);
                insertAtPosition(&head,val,ch);
            }
            else{
                printf("Invalid ans\n");
            }
            break;
        
        case 2:
            
            printf("Enter 1 for deletion at head\n2 for deletion at tail\n3 for deletion at position");
            scanf("%d",&ch);
            if(ch==1){
                deletionAtHead(&head);
            }
            else if(ch==2){
                deletionAtTail(&head);
            }
            else if(ch==3){
                printf("Enter the position:");
                scanf("%d",ch);
                deletionAtPosition(&head,ch);
            }
            else{
                printf("Invalid ans\n");
            }
            break;
        
        case 3:
            display(head);
            break;
        case 4:
            printf("Enter element to be searched:");
            scanf("%d",&ch);

        default:
            printf("Invalid choice :\n");
            break;
        }
        printf("Want to continue (1/0):");
        scanf("%d",&ch);
    }
    
    


}

void insertAtTail(node** head,int val){
    node* p=(node*)malloc(sizeof(node));
    p->data=val;
    if(*head==NULL){
        p->next=NULL;
        *head=p;
        return;
    }
    node* temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=p;
    p->next=NULL;
}
void insertAtHead(node** head,int val){
    node* p=(node*)malloc(sizeof(node));
    p->data=val;
    if(*head==NULL){
        p->next=NULL;
        *head=p;
        return;
    }
    p->next=*head;
    *head=p;
}
void insertAtPosition(node**  head,int val,int pos){
    int start=1;
    node* temp=*head;
    while(pos!=start && temp!=NULL){
        temp=temp->next;
        start++;
    }
    if(temp==NULL){
        printf("The position is out bound");
        return;
    }
    node* p=(node*)malloc(sizeof(node));
    p->data=val;
    if(temp->next!=NULL){
        p->next=temp->next;
        temp->next=p;
        return;
    }
    temp->next=p;
    p->next=NULL;
}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");

}

void deletionAtHead(node** head){
    if(*head==NULL){
        printf("The list is empty\n");
        return;
    }
    *head=(*head)->next;
}
void deletionAtTail(node** head){
    if(*head==NULL){
        printf("The list is empty\n");
        return;
    }
    if((*head)->next==NULL){
        *head=NULL;
    }
    node* temp=*head;
    while(temp->next->next!=NULL ){
        temp=temp->next;
    }
    temp->next=NULL;
}

void deletionAtPosition(node** head,int pos){
    if(*head==NULL){
        printf("The list is empty\n");
        return;
    }
    int start=1;
    node* temp=*head;
    while(start!=pos && temp!=NULL){
        temp=temp->next;
        start++;
    }
    if(temp==NULL){
        printf("Position out of bound\n");
        return;
    }
    if(temp->next==NULL){
        deletionAtTail(head);
        return;
    }
    if(*head==temp){
        deletionAtHead(head);
        return;
    }
    temp->next=temp->next->next;
    
}

