// екземпляр --- об'єкт, що належить класу еееееее
class Point
{
	private:
	int x;
	int y;
	public:
	Point (int valueX, int valueY)
	{
		x=valueX;
		y=valueY;
	}

	void SetY(){

	}
	void GetY(){

	}
	void SetX(){

	}
	void GetX(){

	}
	void Print(){

	}
};

int main()
{
	Point a (5,44);
	a.Print();
	Point b (77,9);
	b.Print();
	return 0;
}
