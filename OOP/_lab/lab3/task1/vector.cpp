#include "vector.h"

Vector& Vector::operator+ (Vector v)
{
	Vector result;
	result.x = this->x + v.x;
	result.y = this->y + v.y;
	Vector * res = &result;
	return * res;
}

Vector& Vector::operator= (Vector v)
{
	this->x = v.x;
	this->y = v.y;
	return *this;
}

Vector& Vector::operator- (Vector v)
{
	Vector result;
	result.x = this->x - v.x;
	result.y = this->y - v.y;
	Vector * res = &result;
	return * res;
}

Vector::Vector(int x, int y)
{
	this->x = x;
	this->y = y;
}
Vector::Vector()
{
	this->x = 0;
	this->y = 0;
}
Vector::~Vector()
{
}

int Vector::getX()
{
	return x;
}
int Vector::getY()
{
	return y;
}

bool Vector::operator ==	(Vector v)
{
	return( this->x == v.x && this->y == v.y );
}
bool Vector::operator <		(Vector v)
{
	return( this->x < v.x && this->y < v.y );
}
bool Vector::operator <=	(Vector v)
{
	return( this->x <= v.x && this->y <= v.y );
}
bool Vector::operator >		(Vector v)
{
	return( this->x > v.x && this->y > v.y );
}
bool Vector::operator >=	(Vector v)
{
	return( this->x >= v.x && this->y >= v.y );
}
bool Vector::operator !=	(Vector v)
{
	return( this->x != v.x && this->y != v.y );
}
