#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
void create(node **);
void disp(node *);
void delpos(node **);
void main(){
    node *head = (node *)NULL;
    create(&head);
    disp(head);
    printf("\n");
    delpos(&head);
    disp(head);
}
void create(node **h){
    node *temp,*newnode;
    int ele;
    printf("enter number");
    while (1)
    {
        scanf("%d",&ele);
        if(ele==-1)
          break;
        else{
            newnode = (node *)malloc(sizeof(node));
            newnode->next = NULL;
            newnode->data = ele;
            if(*h == NULL){
                temp= *h= newnode;
            }
            else{
                temp->next = newnode;
                temp = newnode;
            }
        }  
    }
}  
void disp(node *h){
    if(h==NULL){
        printf("list is empty");
    }
    else{
        while (h!=NULL)
        {
            printf("%d",h->data);
            h = h->next;
        }
        
    }
} 
void delpos(node **h){
    node *temp,*loc,*ptemp;
    int pos,count = 0;
    temp = *h;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    printf("eneter position");
    scanf("%d",&pos);
    if(pos<1||pos>count){
        printf("element not present");
    }
    else{
        temp =*h;
        ptemp =NULL;
        for(int i=0;i<pos-1;i++){
            ptemp = temp;
            temp =temp->next;
        }
        loc = temp;
        if(temp==*h){
           (*h) = (*h)->next;
        }
        else{
            ptemp->next=temp->next;
        }
    }
}