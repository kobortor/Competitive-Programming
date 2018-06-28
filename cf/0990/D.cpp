#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;

int N, A, B;
int adj[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> A >> B;

    if((N == 2 || N == 3) && A == 1 && B == 1){
        cout << "NO\n";
        return 0;
    }

    if(A > 1 && B > 1){
        cout << "NO\n";
        return 0;
    }

    bool swapped = false;

    if(B > 1){
        swap(A, B);
        swapped = true;
    }

    for(int a = A; a < N; a++){
        adj[a - 1][a] = true;
        adj[a][a - 1] = true;
    }

    if(swapped){
        for(int a = 0; a < N; a++){
            for(int b = 0; b < N; b++){
                adj[a][b] ^= a != b;
            }
        }
    }

    cout << "YES\n";
    for(int a = 0; a < N; a++){
        for(int b = 0; b < N; b++){
            cout << adj[a][b];
        }
        cout << "\n";
    }
}
