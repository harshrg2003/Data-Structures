#include<stdio.h>

#include<stdlib.h>

#define MAX 20

void push(int S[MAX],int *top,int elem)

{

  if(*top==MAX-1)

  {

    printf("Insertion not possible.OVERFLOW condition\n");

    return;

  }

   (*top)++;

   S[*top]=elem;

}

int pop(int S[MAX],int *top)

{

   if(*top==-1)

   {

     printf("UNDERFLOW condition\n");

     return -1;

   }

   int elem;

   elem=S[*top];

   (*top)--;

   return elem;

}

int palindrome_Check(int S[MAX],int top,int number)

{

  int temp;

  temp=number;

  while(temp!=0)

  {        

     int digit=temp%10;

     push(S,&top,digit);

     temp=temp/10;

  }

  temp=number;

  while(temp!=0)

  {

    int digit=temp%10;

    int poppeddigit=pop(S,&top);

    if(poppeddigit!=digit)

    {

      return 0;

    }

    temp=temp/10;

 }

 return 1;

}

void display(int S[MAX],int top)

{

   if(top==-1)

   {

     printf("No elements in stack\n");

     return;

   }  

   printf("Elements of the stack are\n");

   for(int i=0;i<=top;i++)

   {

     printf("%d\t",S[i]);

   }

}

int main()

{

  int S[MAX],S1[MAX],top1=-1,top=-1,ch,elem;

  while(1)

  {

    printf("Enter your choice\n");

    printf("Press 1.Push\n2.Pop\n3.Palindrome check\n4.Display\n");

    scanf("%d",&ch);

    switch(ch)

    {

      case 1:printf("Enter an element\n");

             scanf("%d",&elem);

             push(S,&top,elem);

             break;

      case 2:int poppedElement=pop(S,&top);

             if(poppedElement==-1)

             {

               printf("Stack empty\n");

             }

             else

             {

               printf("Deleted element from the stack is %d\n",poppedElement);

             }

             break;

     case 3:if(palindrome_Check(S1,top1,elem)==1)

                printf("%d number is a palindrome\n",elem);

            else

                printf("Not a palindrome\n");

            break;

     case 4:display(S,top);

            break;

     default:exit(0);

   }

 }

  return 0;

}                                               

                