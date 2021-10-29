#include <iostream>

using namespace std;

void obzac()
{
    cout << "\n\n//====================================HomeWork====================================//\n\n";
}
void obzac1()
{
    cout << "\n\n//======================================END======================================//\n\n";
}
void obzac2()
{
    cout << "\n\n//-------------------------------------------------------------------------------//\n\n";
}

/*HOMEWORK1
Реализовать шаблон класса Pair1, 
который позволяет пользователю передавать данные одного типа парами.
int main()
{
    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    return 0;

	… должен производить результат:
    Pair: 6 9
    Pair: 3.4 7.8
}
*/
template <class T>
class Pair1
{
private:
	T m_a;
	T m_b;

public:
	Pair1(const T& a, const T& b): m_a(a), m_b(b){}

	T& first() { return m_a; }
	const T& first() const { return m_a; }
	T& second() { return m_b; }
	const T& second() const { return m_b; }
};

/*HOMEWORK2
Реализовать класс Pair, который позволяет использовать разные типы данных в передаваемых парах.
Следующий код:
int main()
{
	Pair<int, double> p1(6, 7.8);
	cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair<double, int> p2(3.4, 5);
	cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	return 0;
}
… должен производить следующий результат:
Pair: 6 7.8
Pair: 3.4 5
Подсказка: чтобы определить шаблон с использованием двух разных типов, просто разделите параметры типа шаблона запятой.
*/
template <class T, class S>
class Pair
{
private:
	T m_a;
	S m_b;

public:
	Pair(const T& a, const S& b): m_a(a), m_b(b){}

	T& first() { return m_a; }
	const T& first() const { return m_a; }
	S& second() { return m_b; }
	const S& second() const { return m_b; }
};

/*Написать шаблон класса StringValuePair, в котором первое значение всегда типа string, а второе — любого типа. 
Этот шаблон класса должен наследовать частично специализированный класс Pair, в котором первый параметр — string, а второй — любого типа данных.
Следующий код:
int main()
{
	StringValuePair<int> svp("Amazing", 7);
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
	return 0;
}
… должен производить следующий результат:
Pair: Amazing 7
Подсказка: при вызове конструктора класса Pair из конструктора класса StringValuePair не забудьте указать, что параметры относятся к классу Pair.


*/
template <class S>
class StringValuePair : public Pair<string, S>
{
public:
	StringValuePair(const string& key, const S& value): Pair<string, S>(key, value){}
};



int main()
{
	{
		//HOMEWORK1
		obzac();
		Pair1<int> p1(6, 9);
		cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
		const Pair1<double> p2(3.4, 7.8);
		cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
		obzac2();
	}

	{
		//HOMEWORK2
		obzac();
		Pair<int, double> p1(6, 7.8);
		cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

		const Pair<double, int> p2(3.4, 5);
		cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
		obzac2();
	}

	{
		//HOMEWORK3
		obzac();
		StringValuePair<int> svp("Amazing", 7);
		cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
		obzac1();
	}
	return 0;
};
