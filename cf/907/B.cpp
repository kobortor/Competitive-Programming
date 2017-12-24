#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

char grid[9][9];

int main(){
    for(int a = 0; a < 9; a++){
        for(int b = 0; b < 9; b++){
            cin >> grid[a][b];
        }
    }

    int R, C;
    cin >> R >> C;
    R--, C--;

    //sub grid starting points
    int gr = R % 3 * 3, gc = C % 3 * 3;

    bool all_filled = true;
    for(int a = 0; a < 3; a++){
        for(int b = 0; b < 3; b++){
            if(grid[a + gr][b + gc] == '.'){
                grid[a + gr][b + gc] = '!';
                all_filled = false;
            }
        }
    }
    if(all_filled){
        for(int a = 0; a < 9; a++){
            for(int b = 0; b < 9; b++){
                if(grid[a][b] == '.'){
                    grid[a][b] = '!';
                }
            }
        }
    }
    for(int a = 0; a < 9; a++){
        for(int b = 0; b < 9; b++){
            cout << grid[a][b];
            if(b % 3 == 2){
                cout << " ";
            }
        }
        cout << "\n";
        if(a % 3 == 2){
            cout << "\n";
        }
    }
}