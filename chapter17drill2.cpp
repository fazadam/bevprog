#include "std_lib_facilities.h"



int main()
try{

//not allocated in free store --> no memory leak 
int x = 7;
int* p1 = &x;

cout << "pointer to x: " << p1 << " points to: " << *p1 << endl;

//this was allocated
int* p2 = new int[7]{1,2,4,8,16,32,64};

cout <<"address of: " << p2 << " array it points to " << *p2 << endl;


int* p3 = p2;
p2=p1;
p2=p3;

cout << "pointer p1: " << p1 << " points to " << *p1 << '\n';
cout << "pointer p2: " << p2 << " points to " << *p2 << '\n';

//already initialized -> assign 
p1 = new int[10] {1, 2, 4, 8, 16 , 32, 64, 128, 256, 512};
p2 = new int[10];


/*SHALLOW COPY !!
p2=p1;
for(int i = 0; i < 10; ++i)
		cout << "p2 elements:" << p2[i] << endl;
*/

//Deep copy
for(int i =0; i<10;++i){
	p2[i]=p1[i];
	cout << "p2 new elements " << p2[i] << endl;
}


cout << "pointer p1: " << p1 << " points to " << *p1 << '\n';
cout << "pointer p2: " << p2 << " points to " << *p2 << '\n';

if(p1!=p2)
cout << "p1-p2 points to different places!"<< endl;



vector<int> v1 {1, 2, 4, 8, 16 , 32, 64, 128, 256, 512};
vector<int> v2;

v2 = v1;
for(int i=0; i < 10; ++i)
	cout << "v2 copied elements: " <<v2[i] << endl;

int* k1 = &v1[0];
int* k2 = &v2[0];
cout << "pointer k1: " << k1 << endl;
cout << "pointer k2: " << k2 << endl;

if(k1 != k2)
	cout << "k1-k2 points to different places!"<< endl;


	delete[] p1;
	delete[] p2;
	delete[] p3;
	
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