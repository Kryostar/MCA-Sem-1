#include <stdio.h>
struct node {
	int data;
	struct node* leftChild;
	struct node* rightChild;
};

struct node* root = NULL;
void insert(int data) {
	struct node* tempNode = (struct node*)malloc(sizeof(struct node));
	struct node* current;
	struct node* parent;
	tempNode->data = data;
	tempNode->leftChild = NULL;
	tempNode->rightChild = NULL;
	//if tree is empty
	if (root == NULL) {
		root = tempNode;
	}
	else {
		current = root;
		parent = NULL;
		while (1) {
			parent = current;
			//go to left of the tree
			if (data < parent->data) {
				current = current->leftChild;
				//insert to the left
				if (current == NULL) {
					parent->leftChild = tempNode;
					return;
				}
			} //go to right of the tree
			else {
				current = current->rightChild;
				//insert to the right
				if (current == NULL) {
					parent->rightChild = tempNode;
					return;
				}
			}
		}
	}
}
//FIXME:Unfinished Search function
/*struct node* search(int data) {
	struct node* current = root;
	printf("Visiting elements: ");
	while (current->data != data) {
		if (current != NULL)
			printf("%d ", current->data);
		//go to left tree
		if (current->data > data) {
			current = current->leftChild;
		}
		//else go to right tree
		else {
			current = current->rightChild;
		}
		//not found
		if (current == NULL) {
			return NULL;
		}
	}
	return current;
}
*/

void pre_order_traversal(struct node* root) {
	if (root != NULL) {
		printf("%d ", root->data);
		pre_order_traversal(root->leftChild);
		pre_order_traversal(root->rightChild);
	}
}

void inorder_traversal(struct node* root) {
	if (root != NULL) {
		inorder_traversal(root->leftChild);
		printf("%d ", root->data);
		inorder_traversal(root->rightChild);
	}
}

void post_order_traversal(struct node* root) {
	if (root != NULL) {
		post_order_traversal(root->leftChild);
		post_order_traversal(root->rightChild);
		printf("%d ", root->data);
	}
}

void main() {
	int ch, n, i;
	system("cls");
	do {
		printf("\n**MENU**\n1.Enter Elements\n0.Exit\nEnter your Choice: ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			system("cls");
			printf("Enter number of elements: ");
			scanf("%d", &i);
			printf("Enter the elements: ");
			while (i != 0) {
				scanf("%d", &n);
				insert(n);
				i--;
			}
			system("cls");
			printf("\nPreorder Traversal: ");
			pre_order_traversal(root);
			printf("\nInorder Traversal: ");
			inorder_traversal(root);
			printf("\nPost order Traversal: ");
			post_order_traversal(root);
			break;
		case 0:
			printf("**EXIT!**");
			break;
		}
	} while (ch != 0);
	getch();
}