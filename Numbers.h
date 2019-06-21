#include <fstream>
using namespace std;
class number {
public:
	static number* In(ifstream &ifst);
	virtual void InData(ifstream &ifst) = 0; // ввод
	virtual void Out(ofstream &ofst) = 0; // вывод
	virtual float numbers_s() = 0;
	bool Compare(number &others);
};
class container
{
private:
	class Node {
	public:
		Node();
		Node* Next;
		Node* Prev;
		number* data;
		void Processsort(Node* &Top);//меняет местами 2 элемента и изменяет верхушку списка
		void castl();
	};
	Node* Top;
	int count;
public:
	void In(ifstream &ifst); // ввод
	void Out(ofstream &ofst); // вывод
	void Clear(); // очистка контейнера от фигур
	container(); // инициализация контейнера
	void Sort();
	~container() { Clear(); }
};


class complex : public number {
	float real;
	float imaginary;

public:
	void InData(ifstream &ifst); // ввод
	void Out(ofstream &ofst); // вывод
	float numbers_s();
	complex() {} // создание без инициализации.
};
class simple : public number {
	float numerator;
	float denominator;

public:
	void InData(ifstream &ifst); // ввод
	void Out(ofstream &ofst); // вывод
	float numbers_s();
	simple() {} // создание без инициализации.
};

