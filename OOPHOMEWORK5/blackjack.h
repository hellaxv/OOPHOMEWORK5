#pragma once
#include <iostream>
#include <vector>

using namespace std;

/*HOMEWORK3
Реализовать класс Hand, который представляет собой коллекцию карт.
В классе будет одно поле: вектор указателей карт (удобно использовать вектор, т.к. это по сути динамический массив,
а тип его элементов должен быть - указатель на объекты класса Card).
Также в классе Hand должно быть 3 метода:
метод Add, который добавляет в коллекцию карт новую карту, соответственно он принимает в качестве параметра указатель на новую карту
метод Clear, который очищает руку от карт
метод GetValue, который возвращает сумму очков карт руки (здесь предусмотреть возможность того, что туз может быть равен 11).
*/
/*HOMRWORK4
Согласно иерархии классов, которая представлена в методичке к уроку 3, от класса Hand наследует класс GenericPlayer, 
который обобщенно представляет игрока, ведь у нас будет два типа игроков - человек и компьютер. Создать класс GenericPlayer, 
в который добавить поле name - имя игрока. Также добавить 3 метода:
IsHitting() - чисто виртуальная функция, возвращает информацию, нужна ли игроку еще одна карта.
IsBoosted() - возвращает bool значение, есть ли у игрока перебор
Bust() - выводит на экран имя игрока и объявляет, что у него перебор.
*/
class Card
{
public:
	enum rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
	enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };

	Card(suit s, bool ifu = true, rank r = ACE) : m_Rank(r), m_Suit(s), m_IsFaceUp(ifu) { }

	int GetValue() const
	{
		int value = 0;
		if (m_IsFaceUp)
		{
			value = m_Rank;
			if (value > 10)
				value = 10;
		}
		return value;
	}

	void Flip()
	{
		m_IsFaceUp = !m_IsFaceUp;
	}

	friend ostream& operator<<(ostream& s, const Card& aCard);

private:
	rank m_Rank;
	suit m_Suit;
	bool m_IsFaceUp;
};

class Hand
{
public:
	Hand()
	{
		m_Cards.reserve(7);
	}

	virtual ~Hand()
	{
		Clear();
	}

	void Add(Card* pCard)
	{
		m_Cards.push_back(pCard);
	}

	void Clear()
	{
		vector<Card*>::iterator iter = m_Cards.begin();
		for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
		{
			delete* iter;
			*iter = nullptr;
		}

		m_Cards.clear();
	}

	int GetTotal() const
	{
		if (m_Cards.empty() || m_Cards[0]->GetValue() == 0)
			return 0;

		int total = 0;
		vector<Card*>::const_iterator iter;

		for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
			total += (*iter)->GetValue();

		bool containsAce = false;
		for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
			if ((*iter)->GetValue() == Card::ACE)
				containsAce = true;

		if (containsAce && total <= 11) total += 10;

		return total;
	}

protected:
	vector<Card*> m_Cards;
};

class GenericPlayer : public Hand
{
private:
	friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);
protected:
	string m_Name;
public:
	GenericPlayer(const string& name = "") : m_Name(name) { }

	virtual ~GenericPlayer();

	virtual bool IsHitting() const = 0;

	bool IsBusted() const
	{
		return (GetTotal() > 21);
	}

	void Bust() const
	{
		cout << m_Name << " перебор.\n";
	}
};
