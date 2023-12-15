#include <iostream>

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
		void insert(F value, int index);
		void remove_at(int index);
		void pop_back();
		int getSize() {return size;};

		void populate(int num);
		void delete_between_x_z();

		F& operator[](const int index);
		// повертає посилання на тип F

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
void List<F>::populate(int num)
{
	for (int i = 0; i < num; i++)
		push_back(rand()%10);
}


template <typename F>
void List<F>::delete_between_x_z()
{
	int x_index = -1;
	int z_index = -1;
	int index = 0;
	Node *current = this->head;
	bool found_x = false;

	do {
		if (!found_x && (current->data == 'x' || current->data == 'X') )
		{
			std::cout << "Знайдено " << current->data
				<< " за індексом " << index << std::endl;
			found_x = true;
			x_index = index;
		}
		if (found_x && current->data == 'z' || current-> data == 'Z')
		{
			std::cout << "Знайдено " << current->data
				<< " за індексом " << index << std::endl;
			z_index = index;
			break;
		}
		current = current->pNext;
		index++;
	}
	while(current != nullptr);


	Node *previous = this->head;
	for(int i = 0 ; i < x_index; i++)
		previous = previous->pNext;

	for(int i = x_index; i < z_index - 1; i++)
	{
		Node *toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;

		delete toDelete;
		size--;
	}

}

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

template<typename F>
void List<F>::push_front(F data)
{
	head = new Node(data, head);
	size++;
}


template<typename F>
void List<F>::insert(F value, int index)
{
	if(index == 0)
	{
		push_front(value);
	}
	else
	{
		Node *previous = this->head;

		for(int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node *newNode = new Node(value, previous->pNext);
		previous->pNext = newNode;

		size++;
	}
}


template<typename F>
void List<F>::remove_at(int index)
{
	if(index == 0)
	{
		pop_front();
	}
	else
	{
		Node *previous = this->head;

		for(int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node *toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;

		delete toDelete;

		size--;
	}
}

template<typename F>
void List<F>::pop_back()
{
	remove_at(size-1);
}

