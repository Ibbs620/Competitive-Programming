#include <bits/stdc++.h>

using namespace std;

int main(){
   long long int n, m;
   cin >> n >> m;
   long long int s = n + m, d = abs(n - m), p = n * m;
   cout << max(s, max(p, d));
}
