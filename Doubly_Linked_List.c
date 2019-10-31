#include<stdio.h>
#include<stdlib.h>

struct node
{   int data;
    struct node *pre,*next;
}*f=NULL,*e=NULL,*temp;

void in_beg(int data)                                             
{  /* 1. allocate node */
   temp=(struct node *)malloc(sizeof(struct node));                  
    /* 2. put in the data  */
   temp->data=data;    
   /* 3. Make next of new node as head and previous as NULL */                                        
   temp->pre=NULL;                                                   
   if(f==NULL)       //in case list is currently empty
     { temp->next=NULL;
       e=temp;
     }
  else
     { temp->next=f;
       f->pre=temp;
     }
  /* 5. move the head to point to the new node */
  f=temp;
}

void in_end(int data)
{  temp=(struct node *)malloc(sizeof(struct node));
   temp->data=data;
   temp->next=NULL;
   if(f==NULL)
    {  temp->pre=NULL;
       f=temp;
    }
   else
    {  temp->pre=e;
       e->next=temp;
    }
   e=temp;
}

void in_mid(int data,int prev)
{  int fl=0;
   struct node *t;
   temp=(struct node *)malloc(sizeof(struct node));
   temp->data=data;
   if(f==NULL)
       printf("Empty");
   else
     {  t=f;
        while(t!=NULL)
          {   if(t->data==prev)
                 {  temp->next=t->next;
                    t->next->pre=temp;
                    temp->pre=t;
                    t->next=temp;
                    fl=1;
                    break;
                 }
              t=t->next;
          }
          if(fl==0)
               printf("Node not found\n");
     }
}

void del(int data)
{ struct node *t;
  int fl=0;
  if(f==NULL)
      printf("Empty");
  else
     {
        if(f==e && f->data==data)
            {  t=f;
               f=NULL;
               e=NULL;
               free(t);
            }
        else if(f->data==data)
            {  t=f;
               f=f->next;
               f->pre=NULL;
               free(t);
            }
        else if(e->data==data)
            {  t=e;
               e=e->pre;
               e->next=NULL;
               free(t);
            }
        else
            {  temp=f;
              while(temp!=NULL)
              {   if(temp->data==data)
                  {   t=temp;
                      temp->pre->next=temp->next;
                      temp->next->pre=temp->pre;
                      free(t);
                      fl=1;
                      break;
                  }
                  temp=temp->next;
             }
             if(fl==0)
                 printf("Node not found\n");
           }
      }
}

void display()
{
   if(f==NULL)
      printf("Empty\n");
   else
     {   temp=f;
         while(temp!=NULL)
         {   printf("%d\n",temp->data);
             temp=temp->next;
         }
     }
}

void main()
{  int i,data,ch,prev;

   while(1)
   {   printf("\n\nMENU \n1.Insertion at the begining \n2.Insertion at the end");
       printf("\n3.Insertion at the middle \n4.Deletion \n5.Exit");
       printf("\nEnter a choice:");
       scanf("%d",&ch);
       if(ch==1)
          {  printf("Enter data:");
             scanf("%d",&data);
             in_beg(data);
             display();
          }
       else if(ch==2)
          {  printf("Enter data:");
             scanf("%d",&data);
             in_end(data);
             display();
          }
       else if(ch==3)
          {  printf("Enter data:");
             scanf("%d",&data);
             printf("Enter Previous data:");
             scanf("%d",&prev);
             in_mid(data,prev);
             display();
          }
       else if(ch==4)
         {  printf("Enter data to be deleted:");
            scanf("%d",&data);
            del(data);
            display();
         }
       else if(ch==5)
           break;
       else
           printf("Invalid choice");
   }
}


