#include "std_lib_facilities.h"

int main()
try{

	//1. 	Cout -> cout
	cout << "1. Success!\n";

	//2.	missing "" after \n
	cout <<"2. success!\n";
	
	//3.	missing "" before !\n + ;
	cout << "3. Success" << "!\n"; 
	
	//	4.	missing "" in succcess
	cout << "4. Success!" << '\n'; 
	
	// 5. bad input in string
	int res = 7; 
	vector <int> v(10); 
	v[5] = 0;
	cout << "5. Success!\n";

	//6. v() -> v[] vector element + logical = if v[5] not equal 7 = sucess -> v[5] == 7
	vector <int> v6(10);
	v6[5] = 7;
	if (v6[5]==7)
		cout << "6. Success!\n";

	//7. cond not declared
	bool cond = true;
	if (cond)
		cout << "7. Success!\n";
	else 
		cout << "Fail!\n";

	//8. logical error -> !c or bool c= true
	bool c8 = false;
	if (!c8)
		cout << "8. Success!\n";
	else 
		cout <<"Fail!\n";
	
	//9. boo -> bool, + fool<s = false --> !c = success

	string s ="ape";
	bool c9 = "fool" < s;
	if (!c9)
		cout <<"9. Success!\n";
	
	//10. logical error -> ape != fool
	string s10 ="ape";
	if (s10!="fool")
		cout << "10. Success!\n";

	//11. same as 10, + cout << missing
	string s11 ="ape"; 
	if (s11!="fool")
		cout << "11. Success!\n";

	//12. < missing + logical error s4 not equal true
	string s12="ape";
	if (s12 != "fool")
		cout << "12. Success!\n";

	//13.  0-> i in for , i < v4.size() --> i <= get the last element
	// + not to print 5 times -- > if i reaches last element print 1 time success
	vector<char> v13(5);
	for (int i = 0; i <= v13.size(); ++i)
		if (i == v13.size())
			cout << "13. Success!\n";

	//14.not to print 5 times -- > if i reaches last element print 1 time success
	vector<char> v14(5);
	for (int i = 0; i <= v14.size(); ++i)
		if (i == v14.size())
			cout << "14. Success!\n";

	//15. < --> <= for all the elements. 
	// 6 -- > string.size() --> reads all the elements of the string
	string s15 ="15. Success!\n";
	for(int i=0; i<=s15.size(); ++i)
		cout << s15[i];

	//16. then useless + undeclared
	if(true) 
		cout <<"16. Success!\n";
	else 
		cout <<"Fail!\n";

	//17. 
	int x17 =2000;
	int c17 = x17;
	if(c17==2000)
		cout<< "17. Success!\n";

	// 18. i<10 -> till the end of string
	string s18 = "18. Success!\n";
	for(int i = 0; i<s18.size(); ++i)
		cout << s18[i];

	//19. <int> missed in vector + wrote 5 times the cout
	vector <int> v19(5);
	for ( int i = 0; i<=v19.size();++i)
		if (i == v19.size())
			cout << "19. Success!\n";

	//20. have to ++i, not j
		// <= j --> works w/ any arguments changed
	int i20 = 0;
	int j20 = 9;
	while (i20<=j20) 
		++i20;
	if(j20<i20)
		cout << "20. Success!\n";

	//21. run-time error : cannot /0
	// 4.5 not equal 1.25 so --> d21 != ....)
	int x21 = 2;
	double d21=5/(x21+2);

	if (d21!=2*x21+0.5)
		cout << "21. Success!\n";
		
	//22. string is not a vector --> without <char> 
	//run-time error
	string s22 = "22. Success!\n";
	for(int i = 0; i <=s22.size(); ++i)
		cout << s22[i];

	//23. j is not declared.
	//	++i23
	int i23 = 0;
	int j23 = 0;
	while (i23<10)
		++i23;
	if(j23<i23)
		cout <<"23. Success!\n";

	//24. in if(d23 =) --> assignment -- > ==

	int x24 = 4;
	double d24 = 6/(x24-2);
	if (d24 == 2*x24+0.5)
		cout << "24. Success\n";

	//25. not cin 
	cout << "25. Success!\n";





	return 0;
}
catch ( exception & e) {
	cerr << "error: " << e.what() << '\n';
	return 1;
}

catch (...) {
	cerr << "Oops: unknown exception!\n";
	return 2;
}

