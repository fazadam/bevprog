#include "std_lib_facilities.h"

int main()
{
	double a = 0, b = 0;
	
	while (cin >> a >> b)
	{
		cout << "a=" << a << "b=" << b << '\n';

		if (a == b)
			cout << "The numbers are equal" << '\n';

		if (a < b)
			cout << "The smaller value is " << "a=" << a << '\n';
		else 
			cout << "The smaller value is " << "b=" << b << '\n';


		if (a > b)
			cout << "The larger value is " << "a=" << a << '\n';
		else
			cout << "The larger value is " << "b=" << b << '\n';

		if (abs(a-b) <= 0.01)
			cout << "Majdnem egyenlőek\n";
	}


	return 0;
}