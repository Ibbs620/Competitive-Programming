#include <iostream>

using namespace std;

int main()
{
    char grid[2][2]= {{'1' , '2'},
                      {'3' , '4'}};
    int bufferGrid[2][2];
    string flips;
    cin >> flips;
    int noOfFlips = flips.length();
    for(int i = 0; i < noOfFlips; i++){
        if(flips[i] == 'H'){
            bufferGrid[0][0] = grid[1][0];
            bufferGrid[0][1] = grid[1][1];
            bufferGrid[1][0] = grid[0][0];
            bufferGrid[1][1] = grid[0][1];
            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 2; j++){
                    grid[i][j] = bufferGrid[i][j];
                }
            }
        } else if(flips[i] == 'V'){
            bufferGrid[0][0] = grid[0][1];
            bufferGrid[0][1] = grid[0][0];
            bufferGrid[1][0] = grid[1][1];
            bufferGrid[1][1] = grid[1][0];
            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 2; j++){
                    grid[i][j] = bufferGrid[i][j];
                }
            }
        }
    }

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
