#include "std_lib_facilities.h"

const int size = 10;

int ga[size] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(int array[], int n)
{
	//3.a define a local array
	int la[size];

	//3.b+c copy the elements of the global array + print
	cout<< "Local copy elements: " << '\n';
	for(int i =0; i<size;++i){
		la[i]=array[i];
		cout << la[i] << '\n';
	}

	//3.d+e define a pointer + copy the argument array into the free-store arr
	cout<< "Pointer elements: " << '\n';
	int* p = new int[n];
	for(int i = 0; i < n; ++i){
		p[i] = array[i];
		cout << p[i] << '\n';
	}

	//deallocate free-store array
	delete[] p;
}


int factorial(int n){
	if(n>1)
		return n * factorial(n-1);
	else 
		return 1;
}


int main()
try{


cout<< "f with ga-s argument" << '\n';
f(ga,size);

int aa[size]={};
for (int i = 0; i < size; ++i){
	aa[i] = factorial(i+1);
}

cout<< "Factorial array(aa argument)" << '\n';
f(aa,size);




	return 0;
}
catch(exception& e) {
    cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Unknown exception\n";
    return 2;
}