#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

int N, K;
char grid[MAXN][MAXN];
int ans[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;
    for(int a = 0; a < N; a++){
        cin >> grid[a];
    }
    for(int a = 0; a < N; a++){
        for(int b = 0; b < N; b++){
            bool goodH = true;
            bool goodV = true;
            for(int c = 0; c < K; c++){
                if(a + c >= N || grid[a + c][b] == '#'){
                    goodV = false;
                }
                if(b + c >= N || grid[a][b + c] == '#'){
                    goodH = false;
                }
            }
            if(goodV){
                for(int c = 0; c < K; c++){
                    ans[a+c][b]++;
                }
            }
            if(goodH){
                for(int c = 0; c < K; c++){
                    ans[a][b+c]++;
                }
            }
        }
    }
    int maxv = 0;
    for(int a = 0; a < N; a++){
        maxv = max(maxv, *max_element(ans[a], ans[a] + N));
    }
    for(int a = 0; a < N; a++){
        for(int b = 0; b < N; b++){
            if(ans[a][b] == maxv){
                cout << a + 1 << " " << b + 1;
                return 0;
            }
        }
    }
}
