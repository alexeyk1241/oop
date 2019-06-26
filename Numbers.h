#include <fstream>
using namespace std;
class number {
	char units[100];
public:
	static number* In(ifstream &ifst);
	virtual void InData(ifstream &ifst) = 0; // ввод
	virtual void Out(ofstream &ofst) = 0; // вывод
	virtual float numbers_s() = 0;
	bool Compare(number &others);
	virtual void OutComp(ofstream &ofst);
	virtual void MultiMethod(number *other, ofstream &ofst) = 0;//мультиметоды
	virtual void MMcomplex(ofstream &ofst) = 0;//мультиметоды
	virtual void MMsimple(ofstream &ofst) = 0;//мультиметоды
	virtual void MMpolcoor(ofstream &ofst) = 0;//мультиметоды
	number() {};
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
	void OutComp(ofstream &ofst);
	void In(ifstream &ifst); // ввод
	void Out(ofstream &ofst); // вывод
	void Clear(); // очистка контейнера от фигур
	void MultiMethod(ofstream &ofst);//мультиметод
	container(); // инициализация контейнера
	void Sort();
	~container() { Clear(); }
};


class complex : public number {
	float real;
	float imaginary;

public:
	void OutComp(ofstream &ofst);
	void InData(ifstream &ifst); // ввод
	void Out(ofstream &ofst); // вывод
	float numbers_s();
	void MultiMethod(number *other, ofstream &ofst);//мультиметоды
	void MMcomplex(ofstream &ofst);//мультиметоды
	void MMsimple(ofstream &ofst);//мультиметоды
	void MMpolcoor(ofstream &ofst);//мультиметоды
	complex() {} // создание без инициализации.
};
class simple : public number {
	float numerator;
	float denominator;

public:
	void InData(ifstream &ifst); // ввод
	void Out(ofstream &ofst); // вывод
	float numbers_s();
	void MultiMethod(number *other, ofstream &ofst);//мультиметоды
	void MMcomplex(ofstream &ofst);//мультиметоды
	void MMsimple(ofstream &ofst);//мультиметоды
	void MMpolcoor(ofstream &ofst);//мультиметоды
	simple() {} // создание без инициализации.
};
class polcoor : public number
{
	float distance;
	float corner;

public:
	void InData(ifstream &ifst);
	void Out(ofstream &ofst);
	float numbers_s();
	void MultiMethod(number *other, ofstream &ofst);//мультиметоды
	void MMcomplex(ofstream &ofst);//мультиметоды
	void MMsimple(ofstream &ofst);//мультиметоды
	void MMpolcoor(ofstream &ofst);//мультиметоды
	polcoor() {}
};
