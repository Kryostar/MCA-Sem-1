#include<stdio.h>
#include<stdlib.h>

struct TreeNode
{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct TreeNode* makeEmpty(struct TreeNode* root)
{
	if (root != NULL)
	{
		makeEmpty(root->left);
		makeEmpty(root->right);
		free(root);
	}
	return NULL;
}

struct TreeNode* insert(struct TreeNode* root, int x)
{
	if (root == NULL)
	{
		root = malloc(sizeof(struct TreeNode));
		root->data = x;
		root->left = root->right = NULL;
	}
	else if (x < root->data)
		root->left = insert(root->left, x);
	else if (x > root->data)
		root->right = insert(root->right, x);
	return root;
}

struct TreeNode* findMin(struct TreeNode* root)
{
	if (root == NULL)
		return NULL;
	else if (root->left == NULL)
		return root;
	else
		return findMin(root->left);
}

struct TreeNode* findMax(struct TreeNode* root)
{
	if (root == NULL)
		return NULL;
	else if (root->right == NULL)
		return root;
	else
		return findMax(root->right);
}

struct TreeNode* find(struct TreeNode* root, int x)
{
	if (root == NULL)
		return NULL;
	else if (x < root->data)
		return find(root->left, x);
	else if (x > root->data)
		return find(root->right, x);
	else
		return root;
}

int findHeight(struct TreeNode* root)
{
	int lefth, righth;
	if (root == NULL)
		return -1;
	lefth = findHeight(root->left);
	righth = findHeight(root->right);
	return (lefth > righth ? lefth : righth) + 1;
}

struct TreeNode* delete(struct TreeNode* root, int x)
{
	struct TreeNode* temp;
	if (root == NULL)
		return NULL;
	else if (x < root->data)
		root->left = delete(root->left, x);
	else if (x > root->data)
		root->right = delete(root->right, x);
	else if (root->left && root->right)
	{
		temp = findMin(root->right);
		root->data = temp->data;
		root->right = delete(root->right, root->data);
	}
	else
	{
		temp = root;
		if (root->left == NULL)
			root = root->right;
		else if (root->right == NULL)
			root = root->left;
		free(temp);
	}
	return root;
}

void inorder(struct TreeNode* root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

void main()
{
	system("cls");
	struct TreeNode* root;
	struct TreeNode* temp;
	int n, tmp, ch;
	root = NULL;

	do {
		printf("\n**Menu**\n1.Enter elements\n2.Check height\n3.In order\n4.Min\n5.Max\n6.Delete\n7.Empty Tree\n8.Find\n0.Exit\nEnter Choice : "); // add 8.Find
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			system("cls");
			printf("Enter number of elements: ");
			scanf("%d", &n);
			printf("Enter the elements: ");
			while (n != 0) {
				scanf("%d", &tmp);
				root = insert(root, tmp);
				n--;
			}
			break;
		case 2:
			system("cls");
			printf("Height: %d\n", findHeight(root));
			break;
		case 3:
			system("cls");
			printf("In order: ");
			inorder(root);
			break;
		case 4:
			system("cls");
			temp = findMin(root);
			printf("Min Element: %d\n", temp->data);
			break;
		case 5:
			system("cls");
			temp = findMax(root);
			printf("Max Element: %d\n", temp->data);
			break;
		case 6:
			system("cls");
			printf("Enter Element: ");
			scanf("%d", &tmp);
			root = delete(root, tmp);
			break;
		case 7:
			system("cls");
			printf("Empty!\n");
			root = makeEmpty(root);
			break;
		case 8:
			system("cls");
			printf("Enter value to be searched: ");
			scanf("%d", &tmp);
			temp = find(root, tmp); // Use of find() function maybe wrong here.
			printf("\nThe Element is at: %d", temp);
			break;
		case 0:
			system("cls");
			printf("**Exit**");
			break;
		default:
			system("cls");
			printf("Open your eyes");
			break;
		}

	} while (ch != 0);
	getch();
}