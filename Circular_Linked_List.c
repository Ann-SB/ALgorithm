#include<stdio.h>
#include<stdlib.h>

struct node
{  int data;
   struct node * link;
}*f=NULL,*e=NULL,*temp;       //'f' points to first and 'e' points to last node

void insert(int data)
{
    temp=(struct node *)malloc(sizeof(struct node));      //allocate node
    temp->data=data;                                      //put in data
    if(f==NULL)                                           //if list is empty make 'f' and 'e' point to temp
       f=e=temp;
    else                                                  //if list is not empty
      { e->link=temp;                                     
        e=temp;
      }
    e->link=f;
}


void del(int data)
{ int fl=0;
  struct node *t;
  if(f==NULL)
     printf("Empty\n");
  else if(f==e)
     {   t=f;
         f=e=NULL;
         free(t);
     }
  else if(f->data==data)
     {   t=f;
         f=f->link;
         e->link=f;
         free(t);
     }
  else
     {  temp=f;
        while(1)
        {    t=temp->link;
             if(t!=f && t->data==data)
               {   temp->link=t->link;
                   if(t==e)
                      e=temp;
                   free(t);
                   fl=2;
                   break;
               }
             else if(t==f)
                     break;
             temp=temp->link;
             fl=1;
         }
        if(fl==1)
            printf("Element not found\n");
     }
}

void display()
{  int fl=0;
   if(f==NULL)
      printf("Empty\n");
   else
    { temp=f;
      while(1)
        {   printf("%d\n",temp->data);
            if(f==e||(temp->link==f && fl==1))
                   break;
            temp=temp->link;
            fl=1;
        }
    }
}

void main()
{  int ch,prev,data;

   while(1)
   {    printf("\nMENU \n1.Insertion \n2.Deletion \n3.Exit \nEnter choice:");
        scanf("%d",&ch);
        if(ch==1)
         {  printf("Enter element to be inserted:");
            scanf("%d",&data);
            insert(data);
            display();
         }
       else if(ch==2)
         {  printf("Enter element to be deleted:");
            scanf("%d",&data);
            del(data);
            display();
        }
       else if(ch==3)
            break;
       else
           printf("Invalid choice\n");
   }
}
