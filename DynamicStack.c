#include<stdio.h>

#include<stdlib.h>

void push(int *s,int *top,int elem);

void pop(int *s,int *top);

void display(int *s,int top);

int main()

{

     int *s,top=-1,ch,elem;

     s=(int*)malloc(sizeof(int));

       while(1)

       {

           printf("1.Push,\n2.Pop\n,3.Display\n");

           printf("Enter your choice\n");

           scanf("%d",&ch);

            switch(ch)

            {

               case 1:printf("Enter an element\n");

                      scanf("%d",&elem);

                      push(s,&top,elem);

                      break;

               case 2:pop(s,&top);

                      break;

               case 3:display(s,top);

                      break;

               default:exit(0);

            }

       }

 }

  void push(int *s,int *top,int elem)

  {

     (*top)++;

     if(*top==0)

     {

        s[*top]=elem;

     }

     else

     {

        s=(int*)realloc(s,sizeof(int)*((*top)+1));

        s[*top]=elem;

     }

 }

  void pop(int *s,int *top)

  {

     if(*top==-1)

     {

       printf("Underflow condition\n");

       return;

     }

     int elem=s[*top];

     printf("Deleted element is %d\n",elem);

     (*top)--;

     if(*top==-1)

     {

        return;

     }

     s=(int*)realloc(s,sizeof(int)*((*top)+1));

 }

   void display(int *s,int top)

   {

      int i;

      for(i=0;i<=top;i++)

      {

        printf("%d\t",s[i]);

      }

  }                                                            