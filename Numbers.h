#include <fstream>
using namespace std;
class number {
public:
	static number* In(ifstream &ifst);
	virtual void InData(ifstream &ifst) = 0; // ввод
	virtual void Out(ofstream &ofst) = 0; // вывод
	virtual float numbers_s() = 0;
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
	};
	Node* Top;
	int count;
public:
	void In(ifstream &ifst); // ввод
	void Out(ofstream &ofst); // вывод
	void Clear(); // очистка контейнера от фигур
	container(); // инициализация контейнера
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
	int numerator;
	int denominator;

public:
	void InData(ifstream &ifst); // ввод
	void Out(ofstream &ofst); // вывод
	float numbers_s();
	simple() {} // создание без инициализации.
};
