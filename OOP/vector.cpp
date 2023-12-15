#include <iostream>
#include <vector>
using namespace std;

int main ()
{
	vector<int> myVector;
	myVector.reserve(100); // самостійно встановити capacity

	myVector.push_back(2);
	myVector.push_back(3);
	myVector.push_back(7);

	myVector[10] = 55;

	cout << myVector[10] << endl ;

	try
	{
		cout << myVector.at(10) << endl ;
		// безпечніше, але повільніше
	}
	catch (const std::out_of_range & ex)
	{
		cout << ex.what() << endl;
	}

	for (int i = 0; i < myVector.size(); i++)
	{
		cout << myVector[i] << endl;
	}

	cout << endl;

	myVector.pop_back();

	for (int i = 0; i < myVector.size(); i++)
	{
		cout << myVector[i] << endl;
	}

	cout << endl;

	myVector.clear();

	cout << "розмір"	<< myVector.size() << endl;
	cout << "місткість"	<< myVector.capacity() << endl;

	myVector.shrink_to_fit();

	cout << "розмір"	<< myVector.size() << endl;
	cout << "місткість"	<< myVector.capacity() << endl;

	vector<int> other_Vector(20, 1);

	for (int i = 0; i < other_Vector.size(); i++)
	{
		cout << other_Vector[i] << endl;
	}

	cout << "Порожній? " << other_Vector.empty();

	other_Vector.resize(70, 99);

	/* myVector.insert() */
	/* myVector.erase() */

	return 0;
}
