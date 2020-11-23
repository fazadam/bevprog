#include "std_lib_facilities.h"

const int size1 = 10;
const int size2 = 11;
const int size3 = 20;

ostream& print_array(ostream& os,int* a,int n)
{
	for( int i = 0; i < n; ++i)
		os << a[i] << '\n';
		return os;
}

ostream& print_vector(ostream& os,vector<int>& v)
{
	for( int i = 0; i < v.size(); ++i)
		os << v[i] << '\n';
		return os;

}




int main()
try{

int* array1 = new int[size1];
	for(int i = 0; i <size1; ++i)
		array1[i] = i;
	for(int i = 0; i <size1; ++i)
		cout << "array1 elements:" << array1[i] << endl;

int* array2 = new int[size1]{101,102,103,104,105,106,107,108,109,110};
	for(int i = 0; i <size1; ++i)
		cout << "array2 elements:" << array2[i] << endl;

int* array3 = new int[size2]{100,101,102,103,104,105,106,107,108,109,110,};
	for(int i = 0; i <size2; ++i)
		cout << "array3 elements:" << array3[i] << endl;

int* array4 = new int[size3];
	for(int i = 0; i< size3; ++i)
		array4[i]=100+i;
	for(int i = 0; i <size3; ++i)
		cout << "array4 elements:" << array4[i] << endl;

vector<int> v1(size1);
	for(int i = 0; i< size1; ++i)
		v1[i]=100+i;
	for(int i = 0; i <size1; ++i)
		cout << "v1 elements:" << v1[i] << endl;


vector<int> v2(size2);
	for(int i = 0; i< size2; ++i)
		v2[i]=100+i;
	for(int i = 0; i <size2; ++i)
		cout <<"v2 elements:" <<  v2[i] << endl;

vector<int> v3(size3);
	for(int i = 0; i< size3; ++i)
		v3[i]=100+i;
	for(int i = 0; i <size3; ++i)
		cout << "v3 elements:" << v3[i] << endl;








print_vector(cout, v3);
print_array(cout, array4 ,20);

	delete[] array1;
	delete[] array2;
	delete[] array3;
	delete[] array4;
	

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