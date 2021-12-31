#include <iostream>

using namespace std;

int main()
{
    int l;
    cin >> l;
    int num[l];
    char message[l];

    for(int i = 0; i < l; i++){
        cin >> num[i];
        cin >> message[i];
    }
    for(int i = 0; i < l; i++){
        for(int j = 0; j < num[i]; j++){
            cout << message[i];
        }
        cout << endl;
    }
}