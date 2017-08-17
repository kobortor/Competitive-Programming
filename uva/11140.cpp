#include<iostream>
#include<random>
#include<ctime>
#include<cassert>
#include<chrono>

using namespace std;

const int MAXN = 51;
int N, M, S;
string grid[MAXN];
string search[MAXN];

void testcase(){
    cin >> N >> M >> S;
    for(int a = 0; a < N; a++){
        cin >> grid[a];
    }
    while(S--){
        int R, C;
        cin >> R >> C;
        for(int a = 0; a < R; a++){
            cin >> search[a];
        }

        bool found = false;
        for(int a = -MAXN; a < MAXN; a++){
            for(int b = -MAXN; b < MAXN; b++){
                bool can_fit = true;
                for(int i = 0; i < R; i++){
                    for(int j = 0; j < C; j++){
                        if(search[i][j] == '*' && (a + i < 0 || N <= a + i || b + j < 0 || M <= b + j || grid[a + i][b + j] == '.')){
                            can_fit = false;
                        }
                    }
                }
                // if(can_fit){
                //     printf("Fits at %i %i\n", a, b);
                // }
                found |= can_fit;
            }
        }
        cout << (found ? "Yes\n" : "No\n");
    }
}

int main(){
    int T;
    cin >> T;
    while(T--){
        testcase();
        printf("\n");
    }
}