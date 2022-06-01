#include <iostream>
#include "CustomVektorius.h"
#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
	vector<int> x;
	x.PushBack(12);
	cout << x.Size() << " " << x[0]<<endl;
	x.Clear();
	cout << x.Size() << endl;
	x.PushBack(2);
	x.PopBack();
	cout << x.Size() << endl;

	x.PushBack(15);
	x.PushBack(5);
	vector<int> y(x);
	cout <<"Y dydis = "<< y.Size() << " jo elementas indexe 0 yra " << y[1] << endl;
}