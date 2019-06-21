#include <fstream>
using namespace std;
class number {
public:
	static number* In(ifstream &ifst);
	virtual void InData(ifstream &ifst) = 0; // ����
	virtual void Out(ofstream &ofst) = 0; // �����
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
	void In(ifstream &ifst); // ����
	void Out(ofstream &ofst); // �����
	void Clear(); // ������� ���������� �� �����
	container(); // ������������� ����������
	~container() { Clear(); }
};


class complex : public number {
	float real;
	float imaginary;

public:
	void InData(ifstream &ifst); // ����
	void Out(ofstream &ofst); // �����
	float numbers_s();
	complex() {} // �������� ��� �������������.
};
class simple : public number {
	int numerator;
	int denominator;

public:
	void InData(ifstream &ifst); // ����
	void Out(ofstream &ofst); // �����
	float numbers_s();
	simple() {} // �������� ��� �������������.
};
