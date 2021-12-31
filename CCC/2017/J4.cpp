#include <iostream>

int main(){
   int d;
   std::cin >> d;
   int dig[4] = {1,2,0,0};
   int dif;
   int yes = 0;
   for(int i = 0; i < d % 1440; i++){
        dig[3]++;
        if(dig[3] == 10){
            dig[2]++;
            dig[3] = 0;
        }
        if(dig[2] == 6){
            dig[2] = 0;
            dig[3] = 0;
            dig[1]++;
        }
        if(dig[1] == 10){
            dig[1] = 0;
            dig[0] = 1;
        }
        if(dig[0] == 1 && dig[1] == 3){
            dig[0] = 0;
            dig[1] = 1;
            dig[2] = 0;
            dig[3] = 0;
        }
        dif = dig[2] - dig[3];
        for(int j = 0; j < 3; j++){
            if(j == 0 && dig[0] == 0) {
                continue;
            }
            if(dig[j] - dig[j + 1] != dif){
             goto no;
            }
        }
        yes++;
        no:
        1;
   }
   yes += 62 * (d / 1440);
   std::cout << yes;
}