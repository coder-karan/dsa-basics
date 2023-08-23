#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}node;
void insertAtHead(node** l,node** r,int val);
void insertAtTail(node** l,node** r,int val);
void insertAtPosition(node**l,node**r,int val,int pos);
void deletionAtHead(node** l,node** r);
void deletionAtTail(node** l,node** r);
void deletionAtPosition(node** l,node** r,int pos);
void display(node** l,node**r);


int main(){
    node* l=NULL;
    node* r=NULL;
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
                insertAtHead(&l,&r,val);
            }
            else if(ch==2){
                insertAtTail(&l,&r,val);
            }
            else if(ch==3){
                printf("Ente rthe position:");
                scanf("%d",ch);
                insertAtPosition(&l,&r,val,ch);
            }
            else{
                printf("Invalid ans\n");
            }
            break;
        
        case 2:
            
            printf("Enter 1 for deletion at head\n2 for deletion at tail\n3 for deletion at position");
            scanf("%d",&ch);
            if(ch==1){
                deletionAtHead(&l,&r);
            }
            else if(ch==2){
                deletionAtTail(&l,&r);
            }
            else if(ch==3){
                printf("Enter the position:");
                scanf("%d",ch);
                deletionAtPosition(&l,&r,ch);
            }
            else{
                printf("Invalid ans\n");
            }
            break;
        
        case 3:
            display(&l,&r);
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

void insertAtHead(node** l,node** r,int val){
    node* p=(node*)malloc(sizeof(node));
    p->data=val;
    if(*l==NULL && *r==NULL){
        p->next=p;
        *l=*r=p;
        return;
    }
    p->next=*l;
    (*r)->next=p;
    *l=p;
}
void insertAtTail(node** l,node** r,int val){
    node* p=(node*)malloc(sizeof(node));
    p->data=val;
    if(*l==NULL && *r==NULL){
        p->next=p;
        *l=*r=p;
        return;
    }
    (*r)->next=p;
    p->next=*l;
    *r=p;
}
void insertAtPosition(node**l,node**r,int val,int pos){
    node* p=(node*)malloc(sizeof(node));
    p->data=val;
    int start=2;
    if(pos==1){
        insertAtHead(l,r,val);
        return;
    }
    node* temp=(*l)->next;
    while(temp!=*l){
        if(pos==start){
            if(temp->next==*l){
                temp->next=p;
                p->next=*l;
                *r=p;
                return;
            }
            p->next=temp->next;
            temp->next=p;
        }
        else{
            start++;
            temp=temp->next;
        }
    }
    printf("position out of bound\n");
    
}

void deletionAtHead(node** l,node** r){
    if(*l==NULL && *r==NULL){
        printf("The list is empty\n");
        return;
    }
    if((*l)->next==NULL){
        *l=*r=NULL;
        return;
    }
    node* ans=*l;
    *l=(*l)->next;
    (*r)->next=*l;
    free(ans);

}

void deletionAtTail(node** l,node** r){
    if(*l==NULL && *r==NULL){
        printf("The list is empty\n");
        return;
    }
    if((*l)->next==NULL){
        *l=*r=NULL;
        return;
    }
    node* temp=*l;
    while(temp->next!=*r){
        temp=temp->next;
    }
    temp->next=*l;
    free(*r);
    *r=temp;

}
void deletionAtPosition(node** l,node** r,int pos){
    int start=1;
    node* temp=*l;
    while(temp->next!=*l && start!=pos){
        start++;
        temp=temp->next;
    }
    if(temp->next==*l && start+1==pos){
        deletionAtTail(l,r);
        return;
    }
    else if(temp->next!=*l && (*r)->next==temp){
        deletionAtHead(l,r);
        return;
    }
    else{
        node* ans=temp->next;
        temp->next=temp->next->next;
        free(ans);
        return;
    }
    printf("Position out of bound");
}
void display(node** l,node**r){
    node* temp=*l;
    if(*l==NULL){
        printf("The list is empty!!\n");
        return;
    }
    printf("%d->",temp->data);
    temp=temp->next;
    while(temp!=*l){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
