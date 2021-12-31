#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    double x[n];
    double y[n];
    double maxp = 0;
    double dist;
    int it;
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        dist = x[i] * x[i] + y[i] * y[i];
        if(maxp < dist){
            maxp = dist;
            it = i;
        }
    }
    cout << x[it] << " " << y[it];
}
