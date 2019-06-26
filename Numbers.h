#include <fstream>
using namespace std;
class number {
	char units[100];
public:
	static number* In(ifstream &ifst);
	virtual void InData(ifstream &ifst) = 0; // ����
	virtual void Out(ofstream &ofst) = 0; // �����
	virtual float numbers_s() = 0;
	bool Compare(number &others);
	virtual void OutComp(ofstream &ofst);
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
		void Processsort(Node* &Top);//������ ������� 2 �������� � �������� �������� ������
		void castl();
	};
	Node* Top;
	int count;
public:
	void OutComp(ofstream &ofst);
	void In(ifstream &ifst); // ����
	void Out(ofstream &ofst); // �����
	void Clear(); // ������� ���������� �� �����
	container(); // ������������� ����������
	void Sort();
	~container() { Clear(); }
};


class complex : public number {
	float real;
	float imaginary;

public:
	void OutComp(ofstream &ofst);
	void InData(ifstream &ifst); // ����
	void Out(ofstream &ofst); // �����
	float numbers_s();
	complex() {} // �������� ��� �������������.
};
class simple : public number {
	float numerator;
	float denominator;

public:
	void InData(ifstream &ifst); // ����
	void Out(ofstream &ofst); // �����
	float numbers_s();
	simple() {} // �������� ��� �������������.
};
class polcoor : public number
{
	float distance;
	float corner;

public:
	void InData(ifstream &ifst);
	void Out(ofstream &ofst);
	float numbers_s();
	polcoor() {}
};
