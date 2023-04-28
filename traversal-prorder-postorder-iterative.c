#include<stdio.h>

#include<stdlib.h>

struct node

{

  struct node *llink;

  int info;

  struct node *rlink;

};

typedef struct node* NODE;

NODE getnode()

{

  NODE x;

  x=(NODE)malloc(sizeof(struct node));

  if(x==NULL)

  {

    printf("Memory not Allocated\n");

    exit(0);

  }

  return x;

}

NODE insert_BST(NODE root,int elem)

{

  NODE temp;

  temp=getnode();

  temp->info=elem;

  temp->llink=NULL;

  temp->rlink=NULL;

  if(root==NULL)

  {

    return temp;

  }

  NODE prev,curr;

  curr=root;

  while(curr!=NULL)

  {

    prev=curr;

    if(curr->info>elem)

    {

      curr=curr->llink;

    }

    else

    {

      curr=curr->rlink;

    }

  }

  if(prev->info>elem)

  {

    prev->llink=temp;

  }

  else

  {

    prev->rlink=temp;

  }

  return root;

}

void preorder_it(NODE root)

{

  NODE s[10],curr;

  int top=-1;

  if(root==NULL)

     return;

  curr=root;

  for(;;)

  {

    while(curr!=NULL)

    {

      printf("%d\n",curr->info);

      s[++top]=curr;

      curr=curr->llink;

    }

    if(top!=1)

    {

      curr=s[top--];

      curr=curr->rlink;

    }

    else

    {

      return;

    }

  }

}

void inorder_it(NODE root)

{

  NODE s[10],curr;

  int top=-1;

  if(root==NULL)

       return;

  curr=root;

  for(;;)

  {

    while(curr!=NULL)

    {

      s[++top]=curr;

      curr=curr->llink;

    }

    if(top!=1)

    {

      curr=s[top--];

      printf("%d\n",curr->info);

      curr=curr->rlink;

    }

    else

    {

      return;

      

    }

  }

}

int main()

{

  NODE root;

  root=NULL;

  int n,elem;

  printf("Accept the number of elements\n");

  scanf("%d",&n);

  for(int i=0;i<n;i++)

  {

    printf("Enter the element\n");

    scanf("%d",&elem);

    root=insert_BST(root,elem);

  }

  printf("Displaying elements in preorder\n"); 

  preorder_it(root);

  printf("Displaying the elements in inorder\n");

  inorder_it(root);

  return 0;

}                             