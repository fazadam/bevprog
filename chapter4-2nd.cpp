#include "std_lib_facilities.h"

    double converter(double x, string unit_x){
        double y=0;
        if (unit_x =="cm"){
            y=x/100;
        }
        if (unit_x =="in"){
            y=x*2.54/100;
        }
        if (unit_x =="ft"){
            y=x*12*2.54/100;
        }
        if (unit_x =="m"){
            y=x;
        }
        return y;
    }




int main() 
{



    double a = 0;
    double smallest = 0;
    double largest = 0;
    int counter = 0;
    string unit = "";
    double sum = 0;
    vector<double> values;


    cout << "Enter a number followed by a unit(cm/m/in/ft)";




    while (cin >> a >> unit){

       if (unit != "cm" && unit !="m" && unit!="in" && unit!="ft"){
        error("invalid units");
       }

        else if (counter == 0){
            cout << "first number\n";
            a = converter(a,unit);
        smallest = a;
        largest = a;
        ++counter;
        values.push_back(a);
        }

        else if (a < smallest){
            cout << "this is the smallest so far\n";
        smallest = a;
        }

        else if (a > largest){
            cout << "this is the largest so far\n";
        largest = a;
        }
        else if (smallest < a < largest)
            cout << '\n';
        
        sum += a;
        

        }


    cout << "Smallest value: " << smallest  << "meter" << endl;
    cout << "Largest value: " << largest << "meter" << endl;
    cout << "Number of values: " << counter << endl;
    cout << "Sum of values: " << sum << "meter" << endl;

    cout << "sorted values: \n";
    sort(values);
    for(counter=0;counter<values.size();counter++){
        cout << values[counter] << "m";
    }



    return 0;
    
}