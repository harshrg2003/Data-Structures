#include<stdio.h>
typedef struct Sparse
{
	int row, col,value;
} S;

void accept(S a[10])
{
	int m,n,i,j,elem,k=1;
	printf("Enter the size of the sparse matrix:\n");
	scanf("%d%d",&m,&n);
	printf("Enter the elements of the sparse matrix\n");
	for(i=0;i<m;i++)
	{	
		for(j=0;j<n;j++)
		{
			scanf("%d",&elem);
			if(elem!=0)
			{
				a[k].row=i;
				a[k].col=j;
				a[k].value=elem;
				k++;
			}
		}
	}
	a[0].row=m;
	a[0].col=n;
	a[0].value=k-1;
}

void transpose(S a[10],S b[10])
{
	int i,j,k=1;
	for(i=0;i<a[0].col;i++)
	{
		for(j=1;j<=a[0].value;j++)
		{
			if(i==a[j].col)
			{
				b[k].row=a[j].col;
				b[k].col=a[j].row;
				b[k].value = a[j].value;
				k++;
			}
		}
	}
	b[0].row=a[0].col;
	b[0].col=a[0].row;
	b[0].value= a[0].value;
}
		

void display(S a[10])
{
	int i,j,k=1;
	
	printf("Displaying the sparse matrix\n");
	for(i=0;i<a[0].row;i++)
	{
		for(j=0;j<a[0].col;j++)
		{
			if(i==a[k].row && j==a[k].col)
			{
				printf("%d\t",a[k].value);
				k++;
			}
			else
				printf("0\t");
		}
		printf("\n");
	}
	
	
}

int main()
{
	S a[10],b[10];
	accept(a);
	display(a);
	transpose(a,b);
	printf("Displaying the transpose of the sparse matrix\n");
	display(b);
	return 0;
}