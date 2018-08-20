#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, M;
int row, col;
bool R[MAXN], C[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    row = col = N;
    while(M--){
        int r, c;
        cin >> r >> c;
        row -= !R[r];
        col -= !C[c];
        R[r] = C[c] = true;
        cout << (ll)row * col << "\n";
    }
}
