#include <iostream>
#include "CustomVektorius.h"
#include <iomanip>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int main()
{
	Customvector<int> x;
	x.PushBack(12);
	cout << x.Size() << " " << x[0]<<endl;
	x.Clear();
	cout << x.Size() << endl;
	x.PushBack(2);
	x.PopBack();
	cout << x.Size() << endl;

	x.PushBack(15);
	x.PushBack(5);
	x.PushBack(13);
	x.PushBack(4);
	x.PushBack(99);
	Customvector<int> y(x);
	cout <<"Y dydis = "<< y.Size() << " jo elementas indexe 0 yra " << y[1] << endl;

	cout << "ar bandyti bandymus su dyziais? (1- taip , kita- ne)"<<endl;
	int f;
	cin >> f;
	if (f == 1)
	{
		std::vector<int> senasis;
		x.Clear();
		int l = 10000;
		for (int j = 0; j < 4; j++)
		{
			auto start = chrono::steady_clock::now();
			for (int i = 0; i < l; i++)
			{
				x.PushBack(i);
			}
			auto end = chrono::steady_clock::now();
			cout << "uzpildyti custom vektoriu uztruko: " << chrono::duration_cast<chrono::milliseconds>(end - start).count()
				<< " ms" << " su " << l << " duomenu"<< endl;

			start = chrono::steady_clock::now();
			for (int i = 0; i < l; i++)
			{
				senasis.push_back(i);
			}
			end = chrono::steady_clock::now();
			cout << "uzpildyti std vektoriu uztruko: " << chrono::duration_cast<chrono::milliseconds>(end - start).count()
				<< " ms" << " su " << l << " duomenu"<< endl;
			l = l * 10;
			x.Clear();
			senasis.clear();
		}
	}
}