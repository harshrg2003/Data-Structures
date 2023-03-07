
#include<stdio.h>

#include<stdlib.h>

struct node

{

   int info;

   struct node *link;

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

 NODE insert_front(NODE last,int item)

 {

     NODE temp;

     temp=getnode();

     temp->info=item;

     if(last==NULL)

     {

        last=temp;

     }

     else

     {

        temp->link=last->link;

     }   

        last->link=temp;

        return last;

 }

 int count(NODE last)

 {

    int c=0;

    NODE curr;

    if(last==NULL)

    {

      return c;

    }

    if(last->link==last)

    {

       c++;

       return c;

    }

    curr=last->link;

    while(curr!=last)

    {

       c++;

       curr=curr->link;

    }

     c++;

     return c;

 }

 int main()

 {

   int n=3;

   int elem;

   NODE last;

   for(int i=0;i<n;i++)

   {

      printf("Enter the element\n");

      scanf("%d",&elem);

      last=insert_front(last,elem);

   }

   int cnt=count(last);

   printf("No of elemets of circular SLL is %d\n",cnt);

   return 0;

 }