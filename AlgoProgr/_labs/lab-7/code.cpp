#include <iostream> // Потокове введення-виведення
using namespace std; // Використання стандартного простору імен
// Структура, яка описує один вузол 2-3 дерева
struct Node
{
	int k1, k2; // Значення ключів, які можуть зберігатися в дереві
	Node *left;
	Node *middle; // Вказівники на дітей вузла (ліве, середнє, праве)
	Node *right;
	int n; // Кількість ключів в одному вузлі
};
// Корисна структура даних для таких операцій як додавання елементу/ видалення
// елементу
struct usefulData
{
	int midValue{}; // Змінна корисна для 'split operation'(операція
			// розділення)/безкорислива для 'merge operation'(операція
			// злиття)
	Node *child{};
	usefulData() { child = NULL; } // Конструктор по замовчуванню
	usefulData(Node *c) { child = c; } // Перегружений конструктор №1
	usefulData(Node *c, int m) // Перегружений конструктор №2
	{
		child = c;
		midValue = m;
	}
	usefulData
	(const usefulData &otherUsefulData) // Перегружений конструктор копіювання
	{
		child = otherUsefulData.child;
		midValue = otherUsefulData.midValue;
	}
};
class Tree
{
private:
	Node *root; // Вказівник на початок 2-3 дерева
public:
	Tree() { root = nullptr; } // Конструктор по замовчуванню
	~Tree() // Деструктор | якщо дерево пусте, то нічого не робити
	{
		if (root != nullptr)
			destroy(root);
	}
	void destroy(Node *root) // Шаблонна функція видалення вузла
	{
		if (root != nullptr)
		{
			destroy(root->left);
			destroy(root->middle);
			destroy(root->right);
			delete root;
		}
	}
	/*------------------- Функції Обертання вузлів дерева-------------------*/
	// Функція каже чи можливий поворот і якщо можливий то в яку сторону(вправо чи
	// вліво)
	int isRotationPossible(Node *p, Node *r)
				{
		if (p != r) //'p' буде = 'r' тільки коли r - корінь.
		{
			if (p->n == 1) // Блок який виконується якщо батько 2-вузол
			{
				if (r->n == 0)
				{
					// Визначаємо сторону повороту(вліво)
					if ((p->left == r) && (p->middle->n == 2))
						return 2;
					else if ((p->middle == r) && (p->left->n == 2))
						return 1;
				}
				else
				{
					// Визначаємо сторону повороту(вправо)
					if (!((p->left->n == 2) && (p->middle->n == 2)))
				{
						if (p->left == r)
							return 1;
						else
							return 2;
					}
				}
			}
			else // Блок який виконується якщо батько 3-вузол
			{
				if (r->n == 0)
				{
					if ((p->left == r) && (p->middle->n == 2))
					{
						return 2;
					}
					else if (p->middle == r)
					{
						if (p->left->n == 2)
							return 1;
						else if (p->right->n == 2)
							return 2;
					}
					else
					{
						if (p->middle->n == 2)
							return 1;
					}
				}
				else
				{
					if ((p->left == r) && (p->middle->n == 1))
						return 1;
					else if (p->middle == r)
					{
						if (p->left->n == 1)
							return 2;
						else if (p->right->n == 1)
							return 1;
					}
					else
					{
						if (p->middle->n == 1)
							return 2;
					}
				}
			}
		}
		return 0; // Без повороту
	}
	// Функція повороту вузла дерева НАПРАВО
	usefulData RotateRight(Node *p, Node *r, int d, Node *child)
				{
		if (r->n == 0)
				{
			if ((p->n == 2) && (p->right == r))
				{
				r->k1 = p->k2;
				r->n = 1;
				p->k2 = p->middle->k2;
				p->middle->n = 1;
				p->right->left = p->middle->right;
			}
			else
			{
				r->k1 = p->k1;
				r->n = 1;
				p->k1 = p->left->k2;
				p->left->n = 1;
				p->middle->left = p->left->right;
			}
		}
		else
		{
			if (p->n == 2 && p->middle == r)
			{
				p->right->k2 = p->right->k1;
				p->right->k1 = p->k2;
				if (d < r->k1)
				{
					p->k2 = r->k2;
					r->k2 = r->k1;
					r->k1 = d;
				}
				else if (d < r->k2)
				{
					p->k2 = r->k2;
					r->k2 = d;
				}
				else
				{
					p->k2 = d;
				}
				p->right->right = p->right->middle;
				p->right->middle = p->right->left;
				p->right->left = child;
				p->right->n = 2;
			}
			else
			{
				p->middle->k2 = p->middle->k1;
				p->middle->k1 = p->k1;
				if (d < r->k1)
				{
					p->k1 = r->k2;
					r->k2 = r->k1;
					r->k1 = d;
				}
				else if (d < r->k2)
				{
					p->k1 = r->k2;
					r->k2 = d;
				}
				else
				{
					p->k1 = d;
				}
				p->middle->right = p->middle->middle;
				p->middle->middle = p->middle->left;
				p->middle->left = child;
				p->middle->n = 2;
			}
		}
		return nullptr;
	}
	// Функція повороту вузла дерева НАЛІВО
	usefulData RotateLeft(Node *p, Node *r, int d, Node *child)
				{
		if (r->n == 0)
				{
			if ((p->n == 2) && (p->middle == r))
				{
				r->k1 = p->k2;
				r->n = 1;
				p->k2 = p->right->k1;
				p->right->k1 = p->right->k2;
				p->right->n = 1;
				p->middle->middle = p->right->left;
				p->right->left = p->right->middle;
				p->right->middle = p->right->right;
			}
			else
			{
				r->k1 = p->k1;
				r->n = 1;
				p->k1 = p->middle->k1;
				p->middle->k1 = p->middle->k2;
				p->middle->n = 1;
				p->left->middle = p->middle->left;
				p->middle->left = p->middle->middle;
				p->middle->middle = p->middle->right;
			}
		}
		else
		{
			if (p->n == 2 && p->right == r)
			{
				p->middle->k2 = p->k2;
				if (d < r->k1)
				{
					p->k2 = d;
				}
				else if (d < r->k2)
				{
					p->k2 = r->k1;
					r->k1 = d;
				}
				else
				{
					p->k2 = r->k1;
					r->k1 = r->k2;
					r->k2 = d;
				}
				p->middle->right = p->right->left;
				p->right->left = p->right->middle;
				p->right->middle = p->right->right;
				p->right->right = child;
				p->middle->n = 2;
			}
			else
			{
				p->left->k2 = p->k1;
				if (d < r->k1)
				{
					p->k1 = d;
				}
				else if (d < r->k2)
				{
					p->k1 = r->k1;
					r->k1 = d;
				}
				else
				{
					p->k1 = r->k1;
					r->k1 = r->k2;
					r->k2 = d;
				}
				p->left->right = p->middle->left;
				p->middle->left = p->middle->middle;
				p->middle->middle = p->middle->right;
				p->middle->right = child;
				p->left->n = 2;
			}
		}
		return nullptr;
	}
	/*--------------------------Функція вставлення нового
	 * елементу---------------------*/
	// Шаблонна функція вставки елементу, яка перевіряє чи є вже такий елемент,
	// якщо ні то вставляє його у дерево
	bool insert(int d)
				{
		int temp = searchFor(d);
		if (temp != d)
				{
			Node *p = root; // Вказівник на батьківський вузол (використовується для
											// обертання)
			usefulData s1 = insert(root, d, p);
			if (s1.child != NULL) // Випадок, коли результат розділення досягає
														// кореневого вузла і сам корінь потрібно розділити.
			{
				Node *temp = new Node;
				temp->k1 = s1.midValue;
				temp->n = 1;
				temp->left = root;
				temp->middle = s1.child;
				temp->right = nullptr;
				root = temp;
			}
			return true;
		}
		else
			cout << "\n Поточний елемент уже присутній.\n";
		return false;
	}
	// Рекурсивна функція вставки елемента у дерево
	usefulData insert(Node *&r, int d, Node *p)
	{
		// Якщо дерево порожнє
		if (r == nullptr)
		{
			Node *temp = new Node;
			temp->k1 = d;
			temp->left = temp->middle = temp->right = NULL;
			temp->n = 1;
			r = temp;
			return nullptr;
		}
		// Якщо є вузли листків дерева
		else if (r->left == nullptr)
		{
			if (r->n == 1)
			{
				if (d < r->k1)
				{
					r->k2 = r->k1;
					r->k1 = d;
				}
				else
					r->k2 = d;
				r->n = 2;
				return nullptr;
			}
			else
			{
				usefulData s1;
				int e = isRotationPossible(p, r);
				if (e == 1)
					s1 = RotateRight(p, r, d, nullptr);
				else if (e == 2)
					s1 = RotateLeft(p, r, d, NULL);
				else
					s1 = split_3_node(
							r, d, NULL); // Розбиття 3-вузла якщо неможливо виконати повороту
				return s1;
			}
		}
		// Якщо немає вузлів листків
		else
				{
			if (r->n == 1) // Якщо 'r' - 2-вузол
			{
				if (d < r->k1)
				{
					usefulData s1 = insert(r->left, d, r);
					if (s1.child != nullptr)
					{
						r->k2 = r->k1;
						r->k1 = s1.midValue;
						r->right = r->middle;
						r->middle = s1.child;
						r->n = 2;
					}
				}
				else if (d > r->k1)
				{
					usefulData s1 = insert(r->middle, d, r);
					if (s1.child != NULL)
					{
						r->k2 = s1.midValue;
						r->right = s1.child;
						r->n = 2;
					}
				}
				return nullptr;
			}
			else // Якщо 'r' - 3-вузол
			{
				usefulData s1;
				if (d < r->k1)
					s1 = insert(r->left, d, r);
				else if (d < r->k2)
					s1 = insert(r->middle, d, r);
				else
					s1 = insert(r->right, d, r);
				if (s1.child != NULL)
				{
					int e = isRotationPossible(p, r);
					if (e == 1)
						s1 = RotateRight(p, r, s1.midValue, s1.child);
					else if (e == 2)
						s1 = RotateLeft(p, r, s1.midValue, s1.child);
					else
						s1 = split_3_node(r, s1.midValue, s1.child);
					return s1;
				}
				return nullptr;
			}
		}
	}
	// Функція, яка розбиває 3-вузол на окремі вузли дерева
	usefulData split_3_node(Node *current, int k, Node *child)
				{
		int mid;
		Node *temp = new Node;
		temp->n = 1;
		temp->left = temp->middle = temp->right = nullptr;
		if (k < current->k1)
				{
			mid = current->k1;
			temp->k1 = current->k2;
			current->k1 = k;
			if (current->left != nullptr)
				{
				temp->left = current->middle;
				temp->middle = current->right;
				current->middle = child;
			}
		}
// (='.'=)
		else if (k < current->k2)
				{
			mid = k;
			temp->k1 = current->k2;
			if (current->left != nullptr)
				{
				temp->left = child;
				temp->middle = current->right;
			}
		}
		else
		{
			mid = current->k2;
			temp->k1 = k;
			if (current->left != nullptr)
				{
				temp->left = current->right;
				temp->middle = child;
			}
		}
		current->right = nullptr;
		current->n = 1;
		usefulData s1(temp, mid);
		return s1;
	}
	/*------------------- Функція злиття -------------------*/
	usefulData merge(Node *p, Node *&r, Node *child)
				{
		if ((p->n == 2) && (p->right == r))
				{
			p->middle->k2 = p->k2;
			p->middle->n = 2;
			p->middle->right = child;
			child = nullptr;
		}
		else
		{
			if (p->left == r)
			{
				p->middle->k2 = p->middle->k1;
				p->middle->k1 = p->k1;
				p->middle->n = 2;
				p->middle->right = p->middle->middle;
				p->middle->middle = p->middle->left;
				p->middle->left = child;
				child = p->middle;
				p->left = p->middle;
				p->middle = p->right;
			}
			else
			{
				p->left->k2 = p->k1;
				p->left->n = 2;
				p->left->right = child;
				child = p->left;
				p->middle = p->right;
			}
			if (p->n == 2)
				{
				p->k1 = p->k2;
				child = nullptr;
			}
		}
		p->right = nullptr;
		p->n--;
		r->left = r->middle = r->right = nullptr;
		delete r;
		r = nullptr;
		return (child);
	}
	/*------------------- Функція видалення елементу з дерева
	 * -------------------*/
	// Шаблонна функція видалення елементу
	void deleteNode(int d)
				{
		Node *p = root; // Вказівник на батька буде використовуватися у
										// операціяскладання і розбивання
		Delete(root, d, p);
	}
	// Рекурсивна функція видалення елементу з дерева
	usefulData Delete(Node *r, int d, Node *p)
	{
		if (r != nullptr) // Якщо дерево пусте, нічого не робити
		{
			if (r->left != nullptr)
			{
				usefulData s1(nullptr);
				if (r->n == 1) // Якщо вузол - 2-вузол
				{
					if (d != r->k1)
				{
						if (d < r->k1)
							s1 = Delete(r->left, d, r);
						else
							s1 = Delete(r->middle, d, r);
						if (s1.child == NULL)
							return s1;
					}
				}
				else // Якщо вузол - 3-вузол
				{
					if ((d != r->k1) && (d != r->k2))
				{
						if (d < r->k1)
							s1 = Delete(r->left, d, r);
						else if (d < r->k2)
							s1 = Delete(r->middle, d, r);
						else
							s1 = Delete(r->right, d, r);
						if (s1.child == NULL)
							return s1;
					}
				}
				if (root->n == 0) // Коли корінь було злито. Формується новий корінь
				{
					root->left = root->middle = root->right = nullptr;
					delete root;
					root = s1.child;
					r = root;
					return nullptr;
				}
				if (s1.child != nullptr)
				{
					int e = isRotationPossible(p, r);
					if (e == 1)
						s1 = RotateRight(p, r, s1.midValue, s1.child);
					else if (e == 2)
						s1 = RotateLeft(p, r, s1.midValue, s1.child);
					else
						s1 = merge(
								p, r,
								s1.child); // Виконується злиття,якщо поворот неможливо виконати
					return s1;
				}
				Node *current;
				int temp{};
				if ((r->n == 2) && (r->k2 == d))
				{
					temp = r->k2;
					current = r->middle;
					p = r;
					while (current->left != nullptr)
					{
						p = current;
						if (current->n == 1)
							current = current->middle;
						else
							current = current->right;
					}
					if (current->n == 1)
					{
						r->k2 = current->k1;
						current->k1 = temp;
					}
					else
					{
						r->k2 = current->k2;
						current->k2 = temp;
					}
				}
				else
				{
					temp = r->k1;
					current = r->left;
					p = r;
					while (current->left != NULL)
					{
						p = current;
						if (current->n == 1)
							current = current->middle;
						else //(\_/)
							current = current->right;
					}
					if (current->n == 1)
					{
						r->k1 = current->k1;
						current->k1 = temp;
					}
					else if (current->n == 2)
					{
						r->k1 = current->k2;
						current->k2 = temp;
					}
				}
				current->n--; // Видаляємо значення ключа цього вузла
				r = current;
			}
			else if ((r->left == NULL) &&
								 ((r->k1 == d) ||
									(r->k2 ==
									 d))) // 'r' - листовий вузол, виконується просте видалення
			{
				if (r->n == 2) // Якщо 'r' - 3-вузол
				{
					if (r->k1 == d)
						r->k1 = r->k2;
				}
				r->n--; // Видаляємо значення ключа вузла
			}
			// Якщо можливе обертання - обертаємо, інакше робимо злиття
			if ((r->n == 0) && (p == r)) // Означає що корінь було видалено
			{
				delete r;
				root = NULL;
			}
			else if (r->n == 0)
				{
				usefulData s1;
				int e = isRotationPossible(p, r);
				if (e == 1)
					s1 = RotateRight(p, r, s1.midValue, nullptr);
				else if (e == 2)
					s1 = RotateLeft(p, r, s1.midValue, nullptr);
				else
					s1 = merge(p, r,
										 nullptr); // Виконується злиття, якщо неможливе обертання
				return s1;
			}
		}
		else
			cout << "\nДерево вже пусте.";
		return nullptr;
	}
	/*------------------- Функція пошуку елемента -------------------*/
	int searchFor(int item)
				{ return search(root, item); }
	// Рекурсивна функція пошуку елемента 2-3 дерева
	int search(Node *r, int d)
				{
		if (r != nullptr)
				{
			if (r->n == 1) // Якщо 2-вузол
			{
				if (d == r->k1)
					return r->k1;
				else if (d < r->k1)
					return search(r->left, d);
				else
					return search(r->middle, d);
			}
			else // Якщо 3-вузол
			{
				if (d == r->k1)
					return r->k1;
				else if (d == r->k2)
					return r->k2;
				else if (d < r->k1)
					return search(r->left, d);
				else if (d < r->k2)
					return search(r->middle, d);
				else
					return search(r->right, d);
			}
		}
		else
			return -99999999; // Викидається виключення
	}
	/*------------------- Функція виводу 2-3 дерева -------------------*/
	void PrintTree()
				{ print(root); }
	// Рекурсивна функція виведення 2-3 дерева
	void print(Node *r)
	{
		if (r != nullptr)
		{
			if (r->n == 1) // Якщо 2-вузол
			{
				print(r->left);
				cout << " " << r->k1;
				print(r->middle);
			}
			else // Якщо 3-вузол
			{
				print(r->left);
				cout << " " << r->k1;
				print(r->middle);
				cout << " " << r->k2 ;
				print(r->right);
			}
		}
	}
	void DisplayFunctions()
				{
		cout << "1) Вставити; 2) Видалити; 3)Пошук; 4) Друк |"
				 << " Ввести \'-1\' для зупинки "
				 << "| Введіть дію: ";
	}
};


void Start()
{
	Tree tree;
	int userInput = 0;
	int data;
	while (userInput != -1)
				{
		tree.DisplayFunctions();
		cin >> userInput;
		if (userInput == 1)
		{
			cout << "Введіть дані, які потрібно вставити в дерево >> ";
			cin >> data;
			tree.insert(data);
		}
		else if (userInput == 2)
		{
			cout << "Введіть дані, які потрібно видалити з дерева >> ";
			cin >> data;
			tree.deleteNode(data);
		}
		else if (userInput == 3)
		{
			cout << "Введіть елемент даних, який потрібно шукати >> ";
			cin >> data;
			if (tree.searchFor(data) != -99999999)
				cout << "\nЕлемент знайдено.\n";
			else
				cout << "\nЕлемент НЕ знайдено.\n";
		}
		else if (userInput == 4)
		{
			cout << endl;
			tree.PrintTree();
			cout << endl;
		}
		cout << endl;
	}
}

void test()
{
	Tree tree;
	int userInput = 0;
	/* int data; */
	/* int data[] = { 25, 17, 29, 41, 30, 44, 38}; */

	int data[] =  {7,9,10,2,20,15,50,120,54,63,23};

    cout << "           |  15  |          "<< endl;
    cout << "          /       \\          "<< endl;
    cout << "        |9|    |  50 -.- 63  | "<< endl;
    cout << "       /  \\    /      |   \\  "<< endl;
    cout << "   |2 7| |10||20 23||54| |120|"<< endl;
    cout << endl;

	for (int var : data)
		tree.insert(var);
	tree.PrintTree();
	std::cout << std::endl;

	int to_delete[] = {20, 120, 23, 10};
	for (int var : to_delete)
		tree.deleteNode(var);
	    cout << "         |15| "<< endl;
            cout << "        /    \\ " << endl;
            cout << "      |7|   |54| "<< endl;
            cout << "     /  \\   /  \\" << endl;
            cout << "   |2|  |9||50| |63| " << endl;
	std::cout << std::endl;
	tree.PrintTree();
	std::cout << std::endl;
}

int main()
{
	/* Start(); */
	test();
	return 0;
}
