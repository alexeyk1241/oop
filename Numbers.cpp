#include "Numbers.h"
#include <iostream>
#include <fstream>
using namespace std;

void complex::InData(ifstream &ifst)
{
	ifst >> imaginary >> real;
}

void simple::InData(ifstream &ifst)
{
	ifst >> numerator >> denominator;
}

void complex::MultiMethod(number * other, ofstream & ofst)
{
	other->MMcomplex(ofst);
}
void complex::MMcomplex(ofstream & ofst)
{
	ofst << "Complex and Complex" << endl;
}
void complex::MMsimple(ofstream & ofst)
{
	ofst << "Simple and Complex" << endl;
}
void simple::MultiMethod(number*other, ofstream & ofst)
{
	other->MMsimple(ofst);
}
void simple::MMcomplex(ofstream & ofst)
{
	ofst << "Complex and Simple" << endl;
}
void simple::MMsimple(ofstream & ofst)
{
	ofst << "Simple and Simple" << endl;
}

void complex::Out(ofstream &ofst)
{
	if (real < 0)
	{
		ofst << "It is Complex: �������������� ����� = " << imaginary
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

void container::MultiMethod(ofstream & ofst)
{
	ofst << endl << "Multimethod." << endl;
	Node* current_i = Top;
	for (int i = 0; i < count - 1; i++) {
		Node* current_j = current_i->Next;
		for (int j = i + 1; j < count; j++) {
			current_i->data->MultiMethod(current_j->data, ofst);
			current_i->data->Out(ofst);
			current_j->data->Out(ofst);
			current_j = current_j->Next;
		}
		current_i = current_i->Next;
	}
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
		current = current->Next;
	}
}
