#include <iostream> // Потокове введення-виведення
#include <fstream>
#define MAX 4			 // Створення макроса для максимум
#define MIN 2			 // Створення макроса для мінімуму

using namespace std; // Використання стандартного простору імен

/* Структура, яка описує один вузол Б-Дерева */
struct btreeNode
{
	int val[MAX + 1], count;
	btreeNode *link[MAX + 1];
};
btreeNode *root;
// Створення нового вузла В-дерева
btreeNode *createNode(int val, btreeNode *child)
{
	btreeNode *newNode = new btreeNode;
	newNode->val[1] = val;
	newNode->count = 1;
	newNode->link[0] = root;
	newNode->link[1] = child;
	return newNode;
}
// Вставляємо значення у вузол дерева
void addValToNode(int val, int pos, btreeNode *node, btreeNode *child)
{
	int j = node->count;
	while (j > pos)
	{
		node->val[j + 1] = node->val[j];
		node->link[j + 1] = node->link[j];
		j--;
	}
	node->val[j + 1] = val;
	node->link[j + 1] = child;
	node->count++;
}
// Функція яка розбиває вузол В-дерева
void splitNode(int val, int *pval, int pos, btreeNode *node, btreeNode *child,
							 btreeNode **newNode)
{
	int median, j;
	if (pos > MIN)
		median = MIN + 1;
	else
		median = MIN;
	*newNode = new btreeNode;
	j = median + 1;
	while (j <= MAX)
	{
		(*newNode)->val[j - median] = node->val[j];
		(*newNode)->link[j - median] = node->link[j];
		j++;
	}
	node->count = median;
	(*newNode)->count = MAX - median;
	if (pos <= MIN)
	{
		addValToNode(val, pos, node, child);
	}
	else
	{
		addValToNode(val, pos - median, *newNode, child);
	}
	*pval = node->val[node->count];
	(*newNode)->link[0] = node->link[node->count];
	node->count--;
}
// Вставлення нового елемента в вузол В-дерево
int setValueInNode(int val, int *pval, btreeNode *node, btreeNode **child)
{
	int pos;
	if (!node)
	{
		*pval = val;
		*child = NULL;
		return 1;
	}
	if (val < node->val[1])
	{
		pos = 0;
	}
	else
	{
		for (pos = node->count; (val < node->val[pos] && pos > 1); pos--)
			;
		if (val == node->val[pos])
	{
			cout << "Однакові елементи масиву не записуються в Дерево\n";
			return 0;
		}
	}
	if (setValueInNode(val, pval, node->link[pos], child))
	{
		if (node->count < MAX)
		{
			addValToNode(*pval, pos, node, *child);
		}
		else
		{
			splitNode(*pval, pval, pos, node, *child, child);
			return 1;
		}
	}
	return 0;
}
// Вставлення вузла в В-дерево
void insertion(int val)
{
	int flag, i;
	btreeNode *child;
	flag = setValueInNode(val, &i, root, &child);
	if (flag)
		root = createNode(i, child);
}
// Функція яка копіює наставника для елемента, який буде видалятись
void copySuccessor(btreeNode *myNode, int pos)
{
	btreeNode *dummy;
	dummy = myNode->link[pos];
	for (; dummy->link[0] != NULL;)
		dummy = dummy->link[0];
	myNode->val[pos] = dummy->val[1];
}
/* видаляєм значення з заданого вузла та перевпорядковуєм значення */
void removeVal(btreeNode *myNode, int pos)
{
	int i = pos + 1;
	while (i <= myNode->count)
{
		myNode->val[i - 1] = myNode->val[i];
		myNode->link[i - 1] = myNode->link[i];
		i++;
	}
	myNode->count--;
}
// Функція яка змінює значення від батька до правої дитини
void doRightShift(btreeNode *myNode, int pos)
{
	btreeNode *x = myNode->link[pos];
	int j = x->count;
	while (j > 0)
{
		x->val[j + 1] = x->val[j];
		x->link[j + 1] = x->link[j];
	}
	x->val[1] = myNode->val[pos];
	x->link[1] = x->link[0];
	x->count++;
	x = myNode->link[pos - 1];
	myNode->val[pos] = x->val[x->count];
	myNode->link[pos] = x->link[x->count];
	x->count--;
	return;
}
// Функція яка змінює значення від батька до лівої дитини
void doLeftShift(btreeNode *myNode, int pos)
{
	int j = 1;
	btreeNode *x = myNode->link[pos - 1];
	x->count++;
	x->val[x->count] = myNode->val[pos];
	x->link[x->count] = myNode->link[pos]->link[0];
	x = myNode->link[pos];
	myNode->val[pos] = x->val[1];
	x->link[0] = x->link[1];
	x->count--;
	while (j <= x->count)
	{
		x->val[j] = x->val[j + 1];
		x->link[j] = x->link[j + 1];
		j++;
	}
	return;
}
// Функція яка з'єднює вузли
void mergeNodes(btreeNode *myNode, int pos)
{
	int j = 1;
	btreeNode *x1 = myNode->link[pos], *x2 = myNode->link[pos - 1];
	x2->count++;
	x2->val[x2->count] = myNode->val[pos];
	x2->link[x2->count] = myNode->link[0];
	while (j <= x1->count)
	{
		x2->count++;
		x2->val[x2->count] = x1->val[j];
		x2->link[x2->count] = x1->link[j];
		j++;
	}
	j = pos;
	while (j < myNode->count)
	{
		myNode->val[j] = myNode->val[j + 1];
		myNode->link[j] = myNode->link[j + 1];
		j++;
	}
	myNode->count--;
	free(x1);
}
// Функція регулює даний вузол
void adjustNode(btreeNode *myNode, int pos)
{
	if (!pos)
{
		if (myNode->link[1]->count > MIN)
{
			doLeftShift(myNode, 1);
		}
		else
	{
			mergeNodes(myNode, 1);
		}
	}
	else
	{
		if (myNode->count != pos)
		{
			if (myNode->link[pos - 1]->count > MIN)
			{
				doRightShift(myNode, pos);
			}
			else
			{
				if (myNode->link[pos + 1]->count > MIN)
				{
					doLeftShift(myNode, pos + 1);
				}
				else
				{
					mergeNodes(myNode, pos);
				}
			}
		}
		else
		{
			if (myNode->link[pos - 1]->count > MIN)
				doRightShift(myNode, pos);
			else
				mergeNodes(myNode, pos);
		}
	}
}
// Видалення елемента з вузла дерева
int delValFromNode(int val, btreeNode *myNode)
{
	int pos, flag = 0;
	if (myNode)
	{
		if (val < myNode->val[1])
		{
			pos = 0;
			flag = 0;
		}
		else
		{
			for (pos = myNode->count; (val < myNode->val[pos] && pos > 1); pos--);
			if (val == myNode->val[pos])
			{
				flag = 1;
			}
			else
			{
				flag = 0;
			}
		}
		if (flag)
		{
			if (myNode->link[pos - 1])
			{
				copySuccessor(myNode, pos);
				flag = delValFromNode(myNode->val[pos], myNode->link[pos]);
				if (flag == 0)
				{
					cout << "Даний елемент відсутній в Б-Дереві\n";
				}
			}
			else
			{
				removeVal(myNode, pos);
			}
		}
		else
		{
			flag = delValFromNode(val, myNode->link[pos]);
		}
		if (myNode->link[pos])
		{
			if (myNode->link[pos]->count < MIN)
				adjustNode(myNode, pos);
		}
	}
	return flag;
}
// Видалення вузла з В-дерева
void deletion(int val, btreeNode *myNode)
{
	btreeNode *tmp;
	if (!delValFromNode(val, myNode))
	{
		cout << "Даного значення не має в Б-Дереві\n";
		return;
	}
	else
	{
		if (myNode->count == 0)
		{
			tmp = myNode;
			myNode = myNode->link[0];
			free(tmp);
		}
	}
	root = myNode;
	return;
}
// Охід В-дерева (вивід елементів)
void print_tree(btreeNode *myNode)
{
	int i;
	if (myNode)
	{
		for (i = 0; i < myNode->count; i++)
		{
			print_tree(myNode->link[i]);
			cout << myNode->val[i + 1] << ' ';
		}
		print_tree(myNode->link[i]);
	}
}

void show_menu()
{
	int num{};
	for (int i = 0; i < 62; ++i)
		cout << "-";
	cout << "\n[1]-Додати елемент [2]-Видалити елемент [3]-Роздрукувати Б-Дерево "
					"[4]-Вихід |\n";
	for (int i = 0; i < 62; ++i)
		cout << "-";
	cout << endl;
}

void start_menu()
{
	int val{}, num{};
	bool value = true;
	while (value)
	{

		show_menu();
		cout << "Вибір опереації >> ";
		cin >> num;
		cout << endl;
		switch (num)
		{
			case 1:
				cout << "Ввести новий елемент Б-Дерева >> ";
				cin >> val;
				insertion(val);
				break;
			case 2:
				cout << "Ввести елемент для видалення з Б-Дерева >> ";
				cin >> val;
				deletion(val, root);
				break;
			case 3:
				cout << " Обхід побудованого	Б дерева \n";
				print_tree(root);
				cout << endl;
				break;
			case 4:
				value = false;
				break;
		}
		cout << endl;
	}
}

void test()
{
	int data[] = {7, 9, 10, 2, 20, 15, 50, 120, 54, 63, 23};

	for (int var : data)
		insertion(var);
	print_tree(root);
	std::cout << std::endl;

	int to_delete[] = {20, 120, 23, 10};
	/* for (int var : to_delete) */
		/* deletion(var, root); */
	deletion(20, root);
	deletion(120,root);
	deletion(23, root);
	deletion(10, root);
	print_tree(root);
	std::cout << std::endl;

}

int main()
{
	/* start_menu(); */
	std::fstream fin ("treee", std::ios::in);
	std::string input_str;
	std::getline(fin, input_str, '\0');
	std::cout << input_str;
	fin.close();
	fin.open("tree_del", std::ios::in);

	std::getline(fin, input_str, '\0');
	std::cout << std::endl;
	std::cout << input_str;

	test();
	return 0;
}
