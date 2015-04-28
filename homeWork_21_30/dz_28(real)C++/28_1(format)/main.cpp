#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //TIME
    int hours,minut,sec;
    cout << "Hello world!" << endl;
    cout << "Please, enter the time ((Hours, minutes, seconds)" << endl;
    cin>>hours>>minut>>sec;
    cout.fill('0');
    cout.width(2);
    cout<<hours<<":";
    cout.width(2);
    cout<<minut<<":";
    cout.width(2);
    cout<<sec<<endl;
    //TABLE
    char R[]="Alex",Y[]="Garry",J[]="Habib",G[]="Frank";
    double a=2.321 ,b=-1.45 ,c=-2.412 ,d=7.123;
    cout.setf(ios::right);
    cout.fill(' ');
    cout<<setw(15)<<R<<setw(10)<<setprecision(3)<<a<<endl;
    cout<<setw(15)<<Y<<setw(10)<<setprecision(3)<<b<<endl;
    cout<<setw(15)<<J<<setw(10)<<setprecision(3)<<c<<endl;
    cout<<setw(15)<<G<<setw(10)<<setprecision(3)<<d<<endl;
    return 0;
}
