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
void postorder_itr(NODE root)
{
    struct stack
    {
        NODE adress;
        int flag;
    };
    NODE curr;
    struct stack S[10];
    int top=-1;
    if(root==NULL)
    {
        return;
    }
    curr=root;
    for(;;)
    {
        while(curr!=NULL)
        {
            ++top;
            S[top].adress=curr;
            S[top].flag=1;
            curr=curr->llink;
        }
        while(S[top].flag<0)
        {
            curr=S[top].adress;
            top--;
            printf("%d\n",curr->info);
            if(top==-1)
            {
                return;
            }
        }
        curr=S[top].adress;
        curr=curr->rlink;
        S[top].flag=-1;
    }
}
int main()
{
    NODE root;
    root=NULL;
    int n,elem;
    printf("Enter the no of nodes for BST\n");
    scanf("%d",&n);
    printf("Enter the elements into BST one by one\n");
    for(int i=0;i<n;i++)
    {
        printf("Enter element\n");
        scanf("%d",&elem);
        root=insert_BST(root,elem);
    }
    printf("Displaying the elements in postorder\n");
    postorder_itr(root);
    return 0;
}