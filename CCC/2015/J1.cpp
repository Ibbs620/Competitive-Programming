#include <iostream>

using namespace std;

int main()
{
    int day;
    int month;
    cin >> month;
    cin >> day;
    cout << endl;
    if(month < 2){
        cout << "Before";
    } else if (month > 2){
        cout << "After";
    } else {
        if(day > 18){
            cout << "After";
        } else if(day < 18){
            cout << "Before";
        } else {
            cout << "Special";
        }
    }
}