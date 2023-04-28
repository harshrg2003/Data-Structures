//Doubly linked list

#include<stdio.h>

#include<stdlib.h>

struct node

{

   int info;

   struct node *llink,*rlink;

};

typedef struct node* NODE;

 NODE getnode()

 {

    NODE x;

    x=(NODE)malloc(sizeof(struct node));

    if(x==NULL)

    {

       printf("Memory not allocated\n");

       exit(0);

    }

     return x;

 }

 NODE insert_front(NODE first,int item)

 {

    NODE temp;

    temp=getnode();

    temp->info=item;

    temp->rlink=NULL;

    temp->llink=NULL;

   if(first==NULL)

   {

     return temp;

   }

   temp->rlink=first;

   first->llink=temp;

   return temp;

}

NODE insert_rear(NODE first,int item)

{

  NODE temp;

  temp=getnode();

  temp->info=item;

  temp->rlink=NULL;

  temp->llink=NULL;

  if(first==NULL)

  {

    return temp;

  }

  NODE curr;

  curr=first;

  while(curr->rlink!=NULL)

  {

    curr=curr->rlink;

  }

  curr->rlink=temp;

  temp->llink=curr;

  return first;

}      

void display(NODE first)

{

  if(first==NULL)

  {

    printf("Empty DLL\n");

    return;

  }

  NODE curr;

  curr=first;

  printf("\nElements of DLL are\n");

  while(curr!=NULL)       

  {

     printf("%d\t",curr->info);

     curr=curr->rlink;

  }

}

NODE delete_front(NODE first)

{

  NODE curr;

  if(first==NULL)

  {

     printf("Deletion not possible\n");

     return first;

  }

  if(first->rlink==NULL)

  {

     printf("Deleted element is %d\n",first->info);

     free(first);

     return NULL;

  }

  curr=first->rlink;

  curr->llink=NULL;

  printf("Deleted element is %d\n",first->info);

  free(first);

  return curr;

}

NODE delete_rear(NODE first)

{

  NODE prev,curr;

  if(first==NULL)

  {

    printf("Deletion not possible\n");

    return first;

  }

  prev=NULL;

  curr=first;

  while(curr->rlink!=NULL)

  {

     prev=curr;

     curr=curr->rlink;

  }

  prev->rlink=NULL;

  printf("Deleted element is %d\n",curr->info);

  free(curr);

  return first;

}               

int main()

{

  NODE first=NULL;

  int elem,ch;

  while(1)

  {

    printf("Press 1.Insert front\n2.Insert rear\n3.Delete front\n4.Delete rear\n5.Display\n");

    printf("Enter your choice\n");

    scanf("%d",&ch);

    switch(ch)

    {

      case 1:printf("Enter the element\n");

             scanf("%d",&elem);

             first=insert_front(first,elem);

             break;

      case 2:printf("Enter the element\n");

             scanf("%d",&elem);

             first=insert_rear(first,elem);

             break;

      case 3:first=delete_front(first);

             break;

      case 4:first=delete_rear(first);

             break;

      case 5:display(first);

             break;

      default:exit(0);

    }

  }

  return 0;

}                                          

 