#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, Q;

int dsu[MAXN];
int find(int x){
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> Q;

    for(int a = 1; a <= N; a++){
        dsu[a] = a;
    }

    while(Q--){
        char ch;
        int x, y;
        cin >> ch >> x >> y;
        if(ch == 'A'){
            dsu[find(x)] = find(y);
        } else {
            cout << (find(x) == find(y) ? "Y\n" : "N\n");
        }
    }
}
