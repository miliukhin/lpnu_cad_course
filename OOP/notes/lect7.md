---
title: Віртуальні функції
---

```
class Gun
{
	public:
	virtual void Shoot()
	{
		cout << "wqorqwur" << endl;
	}

}

class Mgun:public Gun
{
	public:
	void Shoot() override
	{
		cout << "uirqw" << endl;
	}

}
```

# override

...override

Вказівник базового класу Gun може посилатисль на об'єкт того ж класу або на об'єкт будь-якого класу-нащадка.

```
Gun gun;
Gun *weapon = &gun
```

```
Gun gun;
Submachinegun machinegun;

Gun *weapon = &machinegun;
```

# Зв'язування

раннє --- до запуску проограми
пізнє --- потім

## Раннє

```cpp
class Base
{
public:
virtual void virt () // віртуальний метод
{
cout << "In class Base" << endl;
}
};
class SubBase : public Base
{
public :
//віртуальний метод заміщається у похідному класі
//слово virtual у похідному класі – не обов’язкове
virtual void virt ()
{
cout << "In class SubBase" << endl;
}
};
```

## Пізнє

```cpp
void fun (Base & b)
{
b.virt();
}
int main (void)
{
Base    b;
SubBase sb;
fun (b); // виклик методу virt()базового класу
fun (sb);// виклик методу virt()похідного класу
return 0;
}

```

Рішення про те, який саме метод virt() базового чи
похідного класу має бути викликаний, приймається під час
виконання програми – це пізнє зв’язування.

**Якщо є хоча б одна віртуальна функція, то всі деструктори класу мають бути віртуальними**

```cpp
class Base
{
public:          // раніше визначені члени класу
~Base ()        // звичайний деструктор
{cout << "Destructor Base" << endl;}
};
class SubBase : public Base
{
public :         // раніше визначені члени класу
~SubBase ()     // звичайний деструктор
{cout << "Destructor SubBase" << endl;}
};
int main (void)
{
Base *p = new SubBase ();
delete p;
return 0;
}
```

При виконанні цього прикладу можна побачити, що
екземпляр класу, що адресується вказівником p,
створюється цілком коректно – спочатку працює
конструктор базового класу, а потім конструктор
похідного. Таким чином, створений через вказівник
екземпляр похідного класу SubBase потім
приводиться до типу вказівника на базовий клас
Base.
Але – при знищенні цього екземпляру операцією
delete спрацьовує лише деструктор базового класу!
Це означає втрати пам’яті (memory leaks), адже не
була коректно знищена частина екземпляру, яка
відповідає похідному класу.  Причина в тому, що
об’єкт знищується через вказівник на базовий клас, а
базовому класу нічого невідомо про похідний, адже
працює раннє зв’язування. Щоб позбутись цього
ефекту, конструктор в базовому класі слід визначити
як віртуальний. Тоді і знищення екземпляру,
адресованого вказівником відбудеться коректно:

```
class Base
{
public:          // раніше визначені члени класу
virtual
~Base ()    // віртуальний деструктор
{cout << "Destructor Base" << endl;}
};
class SubBase : public Base
{
public :         // раніше визначені члени класу
~SubBase () // віртуальний деструктор
{cout << "Destructor SubBase" << endl;}
};
int main (void)
{
Base *p = new SubBase ();
delete p;
return 0;
}
```

# Abstract base class

Якщо ви н можете об'єднати класи, або створити базовий для похідних, то