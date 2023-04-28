//Implement Stack program

#include<stdio.h>

#include<stdlib.h>

#define MAX_SIZE 4

void push(int s[MAX_SIZE],int *top,int Elem);

void pop(int s[MAX_SIZE],int *top);

void display(int s[MAX_SIZE],int top);

int main()

{

   int s[MAX_SIZE],top=-1,Elem,ch;

     while(1)

     {

       printf("Enter 1.push,2.pop,3.display\n");

       printf("Enter your choice\n");

       scanf("%d",&ch);

         switch(ch)

         {

           case 1:printf("Enter the element to be pushed\n");

                  scanf("%d",&Elem);

                  push(s,&top,Elem);

                  break;

           case 2:pop(s,&top);

                  break;

           case 3:display(s,top);

                  break;

           default:exit(0); 

         }

     }                          

   

     return 0;

}

 void push(int s[MAX_SIZE],int *top,int Elem)

 {

    

      if(*top==MAX_SIZE-1)

      {

        printf("Overflow condition.Stack full");

      }

      else

      {

         (*top)++;

         s[*top]=Elem;

      }

    

 }        

   void pop(int s[MAX_SIZE],int *top)

   {

      int Elem;

      if((*top)==-1)

      {

        printf("Underfolw condition\n");

        return;

      }

      Elem=s[*top];

      printf("Deleted Element is %d\n",Elem);

       (*top)--;

  }

  void display(int s[MAX_SIZE],int top)

  {

     int i;

     printf("Elements of the Stack\n");

     for(i=0;i<=top;i++)

     {

     

       printf("%d\t",s[i]);

     }

  }                         