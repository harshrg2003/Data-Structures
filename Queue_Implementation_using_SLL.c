#include<stdio.h>

#include<stdlib.h>

#define MAX 10

struct Student

{

   char name[20];

   int age;

   char usn[20];

   int marks;

};

typedef struct Student S;

struct node

{

  S info;

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

NODE insert_rear(NODE first,S elem)

{

  NODE temp,prev,curr;

  temp=getnode();

  temp->info=elem;

  temp->link=NULL;

   if(first==NULL)

   {

     return temp;

   }

   prev=NULL;

   curr=first;

   while(curr!=NULL)

   {

     prev=curr;

     curr=curr->link;

   }

   prev->link=temp;

   return first;

}

NODE delete_front(NODE first)

{

  if(first==NULL)

  {

    printf("Deletion not possible\n");

    return NULL;

  }

  NODE next;

  next=first->link;

  printf("Deleted details of student are %s\n%d\n%s\n%d\n",(first->info).name,(first->info).age,(first->info).usn,(first->info).marks);

  free(first);

  return next;

}

void display(NODE first)

{

  printf("Elements of the queue of student data is\n");

  NODE curr;

  if(first==NULL)

  {

    printf("Empty queue SLL\n");

    return;

  }

  curr=first;

  while(curr!=NULL)

  {

     printf("Name=%s\n",(curr->info).name);

     printf("Age=%d\n",(curr->info).age);

     printf("USN:%s\n",(curr->info).usn);

     printf("Marks out of 500 is %d\n",(curr->info).marks);

     curr=curr->link;

 }

}       

int main()

{

  NODE first;

  S elem;

  first=NULL;

  int ch;

  while(1)

  {

    printf("Press 1.Insert rear\n2.Delete front\n3.Display\n");

    printf("Enter your choice\n");

    scanf("%d",&ch);

    switch(ch)

    {

      case 1:printf("Enter the name, age,USN,and marks of the student\n");

             scanf("%s%d%s%d",elem.name,&elem.age,elem.usn,&elem.marks);

             first=insert_rear(first,elem);

             break;

      case 2:first=delete_front(first);

             break;

      case 3:display(first);

             break;

      default:exit(0);

    }

 }

 return 0;

}                                      

           