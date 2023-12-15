#include <iostream>

/*	ЛабЗадача
	Лишилося написати функцію, що стирає.
	До речі, можна видаляти все й на ходу шукати Z
*/

template <typename F>
class List
{
	public:
		List();
		~List();

		void pop_front();
		void clear();
		void push_back(F data);
		void push_front(F data);
		int getSize() {return size;};

		F& operator[](const int index);
		// повертаємо посилання на тип F

	private:
		class Node
		{
			public:
				Node *pNext;
				F data;
				/*	Конструктор	*/
				Node (F data = F(), Node *pNext=nullptr)
				{
					this->data = data;
					this->pNext = pNext;
				}
		};

		int size;
		Node *head;
};

template <typename F>
List<F>::List()
{
	size = 0;
	head = nullptr;
}

template <typename F>
List<F>::~List()
{
	clear();
}

template <typename F>
void List<F>::push_back(F data)
{
	if (head == nullptr)
		head = new Node(data);
	else
	{
		Node *current = this->head;
		while (current->pNext != nullptr)
			current = current->pNext;
		current->pNext = new Node(data);
	}

	size++;
}

template <typename F>
F & List<F>::operator[](const int index)
{
	int counter = 0;
	Node *current = this->head;
		while (current != nullptr)
		{
			if (counter == index)
				break; //return
			current = current->pNext;
			counter++;
		}
	return current->data;
}

int main ()
{
	List<int> list;
	list.push_back('X');
	list.push_back(10);
	list.push_back('Z');

	/* std::cout << list.getSize() << std::endl; */
	/* std::cout << std::endl; */

	/* for (int i = 0; i < list.getSize(); i++) */
	/* 	std::cout << list[i] << std::endl; */
	int x_index = -1;
	int z_index = -1;

	for (int i = 0; i < list.getSize(); i++)
		if(list[i] == 'X' && z_index < 0)
			x_index = i;
		else if(list[i] == 'Z' && x_index > -1)
			z_index = i;
		else
			continue;
	std::cout << x_index << "\t" << z_index << std::endl;


	int number_count = 4;

	std::cout << std::endl;
	for (int i = 0; i < number_count; i++)
		list.push_back(rand()%10);

	std::cout << "no_pep_front" << std::endl;
	for (int i = 0; i < list.getSize(); i++)
		std::cout << list[i] << std::endl;

	std::cout << "pep_front" << std::endl;

	list.pop_front();
	for (int i = 0; i < list.getSize(); i++)
		std::cout << list[i] << std::endl;

	list.clear();
}

template<typename F>
void List<F>::pop_front()
{
	Node *temp = head;

	head = head->pNext;

	delete temp;

	size--;
}

template<typename F>
void List<F>::clear()
{
	while (size) //всі крім 0 --- true
	{
		pop_front();
	}
}
