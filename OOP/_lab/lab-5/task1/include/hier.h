class B1
{
	int data;

	public:
	B1();
	virtual ~B1();

	virtual void show();
};

class B2
{
	int data;

	public:
	B2();
	virtual ~B2();

	virtual void show();
};

class D1 : public B1, public B2
{
	int data;

	public:
	D1();
	virtual ~D1();

	virtual void show() override;
};

class D2
{
	int data;

	public:

	D2();
	virtual ~D2();

	virtual void show();
};

class D3 : public D1, public D2
{
	int data;

	public:
	D3();
	virtual ~D3();

	virtual void show() override;
};


class D4 : public D3
{
	int data;

	public:
	D4();
	virtual ~D4();

	virtual void show() override;
};

