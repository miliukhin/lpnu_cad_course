#include <iostream>

class Vector
{
	int x;
	int y;

	public:

	Vector();
	Vector(int x, int y);
	~Vector();

	int getX ();
	int getY ();

	int setX (int x);
	int setY (int y);

	Vector& operator +	(Vector v);
	Vector& operator -	(Vector v);
	Vector& operator =	(Vector v);

	bool operator ==	(Vector v);
	bool operator <		(Vector v);
	bool operator <=	(Vector v);
	bool operator >		(Vector v);
	bool operator >=	(Vector v);
	bool operator !=	(Vector v);
};

