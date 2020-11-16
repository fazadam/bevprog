#include "std_lib_facilities.h"

int main()
{

	string first_name;
	cout << "Enter the name of the person you want to write to\n";
	cin >> first_name;
	cout << "Dear " << first_name << ","<< endl;

	cout << "How are you ?\n" << "I am fine.\n" << "I miss you.\n" << "Haven't heard of you for a while\n";

	string friend_name;
	cout << "Write a name of another friend\n";
	cin >> friend_name;
	cout << "Have you seen " << friend_name << " lately ?\n";

	char friend_sex=0;
	cout << "Write m for male, f for female\n";
	cin >> friend_sex;
	if (friend_sex == 'm')
		cout << "If you see " << friend_name << " please ask him to call me\n";
	if (friend_sex == 'f')
		cout << "If you see " << friend_name << " please ask her to call me\n";

	int age;
	cout << "Please enter your age\n";
	cin >> age;

	if (age < 0 || age > 110)
        simple_error("you're kidding!");

	if (age > 0 || age < 110)
		cout << "I hear you just had a birthday and you are " << age << " years old.\n";
	
	if(age<=12)
		cout << "Next year you will be " << age+1 << endl;
	if(age==17)
		cout << "Next year you will be able to vote.\n";
	if(age>=70)
		cout <<"I hope you are enjoying retirement.\n";
		
	cout << "Yours sincerely, \n \n" << first_name << endl;

	return 0;
}