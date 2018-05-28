#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	int key;
	struct node *left;
	struct node *right;
} node;

typedef node* tree;

int init(tree* root)
{
	*root = NULL;
	return 1;
}

int add(tree* root, int key, int data)
{
	tree tmp = malloc(sizeof(node));
	tmp -> data = data;
	tmp -> key = key;
	tmp -> left = NULL;
	tmp -> right = NULL;
	if ((*root) == NULL)
	{
		*root = tmp;
		return 1;
	}
	while ( 1 )
	{
		if ((*root) -> key < key)
		{
			if ((*root) -> right == NULL)
			{
				(*root) -> right = tmp;
				return 1;

			}
			root=&((*root) -> right);
		}
		else if ((*root) -> key > key)
		{
			if ((*root) -> left == NULL)
			{
				(*root) -> left = tmp;
				return 1;

			}
			root=&((*root) -> left);
		}
		else return 1;
	}
}

int find(tree* root, int key)
{
	int lvl =0;
	while ( 1 )
	{
		if ((*root) == NULL)
		{
			printf("-1\n");
			return -1;
		}
		if ((*root) -> key == key)
		{
			printf("%d %d\n", lvl, (*root) -> data);
			return 1;
		}
		else if ((*root) -> key < key)
		{
			lvl=lvl+1;
			root=&((*root) -> right);
		}
		else if ((*root) -> key > key)
		{
			lvl = lvl + 1;
			root=&((*root) -> left);
		}
	}
}
int main()
{
	tree m;
	init(&m);
	int i,n, val, k, a, b, c;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d %d", &k, &val);
		add(&m, k, val);
	}
	scanf("%d %d %d", &a, &b, &c);
	find(&m, a);
	find(&m, b);
	find(&m, c);
	return 0;
}
