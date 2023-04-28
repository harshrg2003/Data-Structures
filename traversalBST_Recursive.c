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

void preorder(NODE root)

{

  if(root==NULL)

      return;

  printf("%d\t",root->info);

  preorder(root->llink);

  preorder(root->rlink);

}

void postorder(NODE root)

{

  if(root==NULL)

     return;

  postorder(root->llink);

  postorder(root->rlink);

  printf("%d\t",root->info);

}

void inorder(NODE root)

{

  if(root==NULL)

     return;

  inorder(root->llink);

  printf("%d\t",root->info);

  inorder(root->rlink);

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

  preorder(root);

  printf("\nDisplaying elements in postorder\n");

  postorder(root);

  printf("\nDisplaying elements in inorder\n");

  inorder(root);

  return 0;

}                        