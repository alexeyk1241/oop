#include "Numbers.h"
#include <iostream>
#include <fstream>
using namespace std;
void complex::InData(ifstream &ifst)
{
	ifst >> imaginary >> real;
	number::InData(ifst);
}
void simple::InData(ifstream &ifst)
{
	ifst >> numerator >> denominator;
	number::InData(ifst);
}

void number::InData(ifstream &ifst)
{
	ifst >> units;
}
void number::Out(ofstream &ofst)
{
	ofst << ", еденица измерения = " << units;
}

void complex::Out(ofstream &ofst)
{
	if (real < 0)
	{
		ofst << "It is complex: действительная часть = " << imaginary
			<< ", мнимая часть = " << real << endl << imaginary << real << "i";
		number::Out(ofst);
		ofst << endl;
	}
	else
	{
		ofst << "It is complex: действительная часть = " << imaginary
			<< ", мнимая часть = " << real << endl << imaginary << "+" << real << "i";
		number::Out(ofst);
		ofst << endl;
	}
}
void simple::Out(ofstream &ofst)
{
	ofst << "It is Simple: числитель = " << numerator
		<< ", знаменатель = " << denominator << endl << numerator << "/" << denominator;
	number::Out(ofst);
	ofst << endl;
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
		current = current->Next;
	}
}
