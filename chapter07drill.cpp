#include "std_lib_facilities.h"

const char let = '#';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const string prompt = "> ";
const string result = "= ";
const char square_root = '@'; 
const string sqrtkey = "sqrt";
const string quitkey = "exit";
const char pow_root = '$';
const string powkey = "pow";


class Token { //class Token
public:			//public
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, string n): kind(ch), name(n) {}
};

class Token_stream {
public:
	Token_stream() :full(0), buffer(0) { }
	Token get();
	void putback(Token t) { buffer = t; full = true; }
	void ignore(char c);

private: 			//buffer in private
	bool full;
	Token buffer;
};

class Variable { //struct not secure and cant hide implementation&desing details from user like the class
public: //has to be public for users!
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names;

double get_value(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s);
	return 0;
}

void set_value(string s, double d)
{
	for (int i = 0; i <= names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool is_declared(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

double define_name(string var, double val){
	if(is_declared(var)) error (var, "declared twice");
	names.push_back(Variable{var,val});
	return val;
}


Token Token_stream::get()
{
	if (full) { 
		full = false; 
		return buffer; 
	}
	
	char ch;
	cin >> ch;
	
	switch (ch) { 
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case ',':
		case print:
		case quit:			
		case '=':
		case let:
			return Token(ch);
		case '.':
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
	{	
		cin.putback(ch);
		double val;
		cin >> val;
		return Token(number, val);
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch; // add it +=
			cin.putback(ch); //needs ch to put back tha vharacters into the stream
			if(s == sqrtkey) return Token{square_root};
			//else if (s == "quit") return Token(name); //same here
			else if (s == quitkey) return Token{quit};
			else if (s == powkey) return Token{pow_root};

			else if(is_declared(s))
				return Token(number, get_value(s));
			
			return Token {name, s}; //same here
		}
		error("Bad token");
	}
	return 0;
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) { //look in the buffer
		full = false;
		return;
	}
	full = false;

	char ch ; 
	while (cin >> ch)			//search for input
		if (ch == c) return;
}



Token_stream ts;

double expression();

double calc_pow ()
{
	Token t = ts.get();
	if(t.kind != '(') error ("'(' expected");
	
	double d1 = expression();
	
	t = ts.get();
	if(t.kind != ',') error ("',' expected");
	
	
	double d2 = expression();
	
	t = ts.get();
	if(t.kind != ')') error ( "')' expected");
	
	return pow(d1,d2);

} 
	

double calc_sqrt(){
	char ch;
	if(cin.get(ch) && ch != '(') error ("'(' expected");
	cin.putback(ch);
	double d = expression();
	return sqrt(d);
}


double primary()
{
	Token t = ts.get();
	switch (t.kind) {
		case '(':
			{	
				double d = expression();
				t = ts.get();
				if (t.kind != ')') error("'(' expected");
				return d;
			}

		case '-':
			return - primary(); 
					

		case number:
			return t.value;
			

		case name:
			return get_value(t.name);
			
		case square_root:
			return calc_sqrt();

		
		case pow_root:
			return	calc_pow ();
		
			
		default:
			error("primary expected");
			return 0;
	}
}

double term()
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
			case '*':
				left *= primary();
				break;
			case '/':
				{	
					double d = primary();
					if (d == 0) error("divide by zero");
					left /= d;
					break;
				}
			default:
				ts.putback(t);
				return left;
		}
	}
}

double expression()
{
	double left = term();
	
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
			case '+':
				left += term();
				break;
			case '-':
				left -= term();
				break;
			default:
				ts.putback(t);
				return left;
		}
	}
}

double declaration()
{
	Token t = ts.get();
	
	if (t.kind != 'a') error("name expected in declaration");
	string name = t.name;
	
	if (is_declared(name)) error(name, " declared twice");
	
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	
	double d = expression();
	names.push_back(Variable(name, d));
	return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
		case let:
			return declaration();
		default:
			ts.putback(t);
			return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}


void calculate()
{
	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.putback(t);
		cout << result << statement() << endl;
	}
	catch (exception& e) {						//exception & e
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()

try {

	define_name("k", 1000);
	calculate();
	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}
