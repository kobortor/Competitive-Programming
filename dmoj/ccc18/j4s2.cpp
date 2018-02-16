#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

int N;
int arr[MAXN][MAXN];
int tmp[MAXN][MAXN];

void rot90(){
    for(int a = 0; a < N; a++) {
        for(int b = 0; b < N; b++){
            tmp[b][N - a - 1] = arr[a][b];
        }
    }
    for(int a = 0; a < N; a++) {
        for(int b = 0; b < N; b++){
            arr[a][b] = tmp[a][b];
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    int mn = 2e9;
    for(int a = 0; a < N; a++){
        for(int b = 0; b < N; b++){
            cin >> arr[a][b];
            mn = min(mn, arr[a][b]);
        }
    }
    while(arr[0][0] != mn){
        rot90();
    }
    for(int a = 0; a < N; a++){
        for(int b = 0; b < N; b++){
            cout << arr[a][b] << " ";
        }
        cout << "\n";
    }
}
