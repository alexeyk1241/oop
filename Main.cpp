#include "Numbers.h"
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char* argv[])
{
	int a;
	if (argc != 3) {
		cout << "incorrect command line! "
			"Waited: command in_file out_file"
			<< endl;
		system("pause");
		exit(1);
	}
	ifstream ifst(argv[1]);

	if (!ifst)
	{
		cout << "No input file found!" << endl;
		system("pause");
		exit(1);
		return 0;
	}

	ofstream ofst(argv[2]);
	cout << "Start" << endl;
	setlocale(LC_ALL, "Russian");
	container c;
	c.In(ifst);
	ofst << "Filled container. " << endl;

	c.Out(ofst);
	c.Sort();
	ofst << endl;
	c.Out(ofst);
	ofst << endl;
	c.OutComp(ofst);
	c.Clear();

	ofst << "Empty container. " << endl;
	c.Out(ofst);
	cout << "Stop" << endl;
	system("pause");
	cin >> a;
	return 0;
}