/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//doubly linked list//  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

struct abc
{
    char name[20];
    int PRN;
    struct abc*prv;
    struct abc*next;
};
void insertS(struct abc*);
void insertM(struct abc*);
struct abc* deleteP(struct abc*);
void deleteS(struct abc*);
void deleteM(struct abc*);
void count(struct abc*);
struct abc* reverse(struct abc*);
void display(struct abc*);



void main()
{
    int ch,y;
    struct abc *head;       //first node
    head=(struct abc*)malloc(sizeof(struct abc));
    printf("enter the name and PRN of president:\n");
    scanf(" %s",head->name);
    scanf("%d",&head->PRN);
    head->next=NULL;
    head->prv=NULL;
    insertS(head);

    do{
        printf("enter choice :\n1.insert member \n2.delete president \n3.delete secretary \n4.delete member \n5.count member \n6.reverse \n7.display \n8.exit");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
        insertM(head);
        break;
       
        case 2:
        head=deleteP(head);
        break;
       
        case 3:
        deleteS(head);
        break;
       
        case 4:
        deleteM(head);
        break;
         
        case 5:
        count(head);
        break;
       
        case 6:
        head =reverse(head);
        break;
       
        case 7:
        display(head);
        break;
       
        case 8:
        exit;
       
       
        default :
        printf("wrong choice !!");
       
        }
        printf("\ndo want to continue ?(0/1)");
        scanf("%d",&y);
    }
    while(y==1);
}
void insertS(struct abc*head)
{
    struct abc*new;  //last node
    new=(struct abc*)malloc(sizeof(struct abc));
    printf("enter the name and PRN of secretary:\n");
    scanf(" %s",new->name);
    scanf("%d",&new->PRN);
    new->next=NULL;
    new->prv=NULL;
    head->next=new;
    new->prv=head;
   
}
void insertM(struct abc*head)
{
    struct abc*new,*temp;
    new=(struct abc*)malloc(sizeof(struct abc));
    printf("enter the name and PRN of member:\n");
    scanf(" %s",new->name);
    scanf("%d",&new->PRN);
    new->next=NULL;
    new->prv=NULL;
    temp=head;
    temp=head->next;
    head->next=new;
    new->prv=head;
    new->next=temp;
    temp->prv=new;
}
struct abc* deleteP(struct abc*head)
{
 struct abc*temp;
 temp=head;
 head=head->next;
 head->prv=NULL;
 free(temp);
 
return head;

}
void deleteS(struct abc*head)
{
    struct abc*temp,*prv;
   
    while(temp->next!=NULL)
    {
         temp->prv=temp;
        temp=temp->next;
    }
    temp->prv->next=NULL;
    free(temp);
}
void deleteM(struct abc*head)
{
    int pos;
    struct abc*temp,*p,*prv;
    printf("enter the position of the node to be deleted :\n");
    scanf("%d",&pos);
    while(pos>1)
    {
        temp=temp->next;
        pos--;
    }
    p=temp->prv;
    p->next=temp->next;
    temp->next->prv=p;
    free(temp);
    temp=NULL;
    
    
}
void count(struct abc*head)
{
    int count=0;
    struct abc*temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
       
    }
     printf("\ncount = %d",count);
}
struct abc* reverse(struct abc*head)
{
   struct abc*p=head;
   struct abc*q=p->next;
   p->next=NULL;
   p->prv=q;
   
   while(q != NULL)
   {
       q->prv=q->next;
       q->next=p;
       p=q;
       q=q->prv;
       
   }
   head=p;
   return head;
}
void display(struct abc*head)
{
    struct abc*temp=head;
    while(temp!=NULL)
    {
        printf("\nname :%s\t PRN:%d",temp->name,temp->PRN);
        temp=temp->next;
        }
}


