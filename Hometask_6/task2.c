/*
Ќапишите программу, котора€ возвращает сумму всех элементов в дереве
ƒанные на выходе  
78

ћы должны обойти дерево по всем значени€м, которые наход€тс€ в корне и всех листь€х и просуммировать их
*/
#include <stdio.h>

#define datatype int

typedef struct node // определ€ем структуру дерево
{
	datatype key; // у каждого элемента дерева есть ключ - значение в корне или листе
	struct node *left, *right, *parent; // у каждого элемента двоичного дерева есть лева€ и права€ ветвь, а также родитель 
} node;

int sumTree(node *root) // находим сумму всех элементов дерева
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return root->key + sumTree(root->left) + sumTree(root->right); // указатель на тип дерево root присваиваетс€ ключу (значению) и суммируетс€ со значени€ми в листь€х, наход€щимис€ слева и справа от текущего родител€ 
	}
}

void preorder(node *root)
{
	if (root == NULL)
		return;
	printf("%d ", root->key);
	if (root->left)
		preorder(root->left);
	if (root->right)
		preorder(root->right);
}

void postorder(node *root)
{
	if (root == NULL)
		return;
	if (root->left)
		postorder(root->left);
	if (root->right)
		postorder(root->right);
	printf("%d ", root->key);
}


int main(int argc, char **argv)
{
	node n[10] = {0}; // создаем дерево, представленное на рисунке к заданию
	n[0].left = n + 1; // лева€ ветвь
	n[0].right = n + 2; // права€ ветвь
	n[0].key = 10; // ключ равен дес€ти - это значение, которое расположено в корне дерева
	n[1].left = n + 3;
	n[1].right = n + 4;
	n[1].key = 5; // ключ листа 5
	n[1].parent = n + 0;
	n[2].left = n + 5;
	n[2].right = n + 6;
	n[2].key = 15; // ключ листа 15
	n[2].parent = n + 0;
	n[3].left = n + 7;
	n[3].parent = n + 1;
	n[3].key = 3;
	n[4].left = n + 8;
	n[4].parent = n + 1;
	n[4].key = 7;
	n[5].key = 13;
	n[5].parent = n + 2;
	n[6].key = 18;
	n[6].parent = n + 2;
	n[7].key = 1;
	n[7].parent = n + 3;
	n[8].key = 6;
	n[8].parent = n + 4;

	printf("preorder: ");
	preorder(n);
	putchar('\n');
	printf("postorder: ");
	postorder(n);
	putchar('\n');

	int sum = sumTree(n);
	printf("Sum tree : %d\n", sum);

	return 0;
}



