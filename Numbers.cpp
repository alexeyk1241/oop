#include "Numbers.h"
#include <iostream>
#include <fstream>
using namespace std;

float simple::numbers_s()
{
	float time;
	time = numerator / denominator;
	return time;
}

float complex::numbers_s()
{
	float time1;
	time1 = sqrt(pow(real, 2) + pow(imaginary, 2));
	return time1;
}

bool number::Compare(number &other)
{
	return numbers_s() < other.numbers_s();
}
void container::Sort()
{
	Node* current;
	current = Top;
	Node* currentnext = current->Next;
	for (int i = 0; i < count-1; i++)
	{
		if (current->data->Compare(*current->Next->data))
		{
			Node p;
			p.data = current->data;
			current->data = current->Next->data;
			current->Next->data = p.data;
			i = 0;
			current = Top;
		}
		else
		{
			current = current->Next;
		}
	}
}
void container::Node::Processsort(Node *& Top)
{
	Node* currentnext = this->Next;
	if (this == Top)//���������� ��������� �� �� ������
	{
		if (this->Next->Next == this)
		{
			Top = this->Next;
		}
		else
		{
			this->castl();
			Top = this;
		}
	}
	else
	{
		if (this->Next->Next == this)
		{
			Top = this->Next;
		}
		else
			this->castl();
	}
}
void container::Node::castl()
{
	Node* currentnext = this->Next;//������� �����, ��� ����� �������
	number* q1 = this->data;
	number* q2 = currentnext->data;
	this->data = q2;
	currentnext->data = q1;
}

void complex::InData(ifstream &ifst)
{
	ifst >> imaginary >> real;
}
void simple::InData(ifstream &ifst)
{
	ifst >> numerator >> denominator;
}
void complex::Out(ofstream &ofst)
{
	if (real < 0)
	{
		ofst << "It is complex: �������������� ����� = " << imaginary
			<< ", ������ ����� = " << real << endl << imaginary << real << "i" << endl;
	}
	else
	{
		ofst << "It is complex: �������������� ����� = " << imaginary
			<< ", ������ ����� = " << real << endl << imaginary << "+" << real << "i" << endl;
	}
}
void simple::Out(ofstream &ofst)
{
	ofst << "It is Simple: ��������� = " << numerator
		<< ", ����������� = " << denominator << endl << numerator << "/" << denominator << endl;
}
number* number::In(ifstream &ifst)
{
	number *s;
	int key;
	ifst >> key;
	if (key == 1) {
		s = new complex;
	}
	else if (key == 2)
	{
		s = new simple;
	}
	else
		return 0;
	s->InData(ifst);
	return s;
}
container::Node::Node()
{
	this->Next = nullptr;
	this->Prev = nullptr;
	this->data = nullptr;
}

container::container()
{
	Top = nullptr;
	count = 0;
}
void container::Clear()
{
	Node* current = Top;
	for (int i = 1; i < count; i++)
	{
		current = current->Next;
		delete current->Prev;
	}
	delete current;
	count = 0;
}
void container::In(ifstream & ifst)
{
	int flag;
	while (!ifst.eof()) {
		if (count == 0)
		{
			Top = new Node;
			Top->Next = Top;
			Top->Prev = Top;
			if ((Top->data = number::In(ifst)) != 0)
				flag = 1;
			else
				flag = 0;

		}
		else
		{
			Node *current = Top;
			for (int j = 1; j < count; j++)
			{
				current = current->Next;
			}
			current->Next = new Node;
			if ((current->Next->data = number::In(ifst)) != 0)
			{
				Top->Prev = current->Next;
				current->Next->Prev = current;
				current->Next->Next = Top;
				flag = 1;
			}
			else
			{
				flag = 0;
			}
		}
		if (flag != 0)
			count++;
	}
}

void container::Out(ofstream & ofst)
{
	Node* current = Top;
	ofst << " Container contains " << count
		<< " elements." << endl;
	for (int j = 0; j < count; j++) {
		ofst << j << ": ";
		current->data->Out(ofst);
		ofst << "�������� = " <<
			current->data->numbers_s() << endl;
		current = current->Next;
	}
}
