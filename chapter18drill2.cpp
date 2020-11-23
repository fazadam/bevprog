#include "std_lib_facilities.h"

const int size = 10;

vector<int> gv = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(vector<int>v)
{
	cout << "elements of lv: " << '\n';
	vector<int> lv(size);
	lv = v;
	for(int i = 0; i < lv.size(); ++i){
		lv[i] = v[i];
		cout << lv[i] << '\n';
		}

	cout << "elements of lv2: " << '\n';
	vector<int> lv2(v);
	lv2=v;
	for(int i = 0; i < lv2.size(); ++i){
		cout << lv2[i] << '\n';
	}

}


int factorial(int n){
	if(n>1)
		return n * factorial(n-1);
	else 
		return 1;
}


int main()
try{

cout << "Global vector: " << '\n';
f(gv);

vector<int> vv(size);
for(int i = 0; i < vv.size(); ++i)
	vv[i] = factorial(i+1);

cout << "factorial values: " << '\n';
f(vv);




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