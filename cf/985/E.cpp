#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 5e5 + 5;

int N, K, D;
int color[MAXN];
set<int> good;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K >> D;
    for(int a = 0; a < N; a++){
        cin >> color[a];
    }
    sort(color, color + N);

    good.insert(-1);
    for(int a = 0; a < N; a++){
        auto bck = good.upper_bound(a - K);
        if(bck != good.begin() && color[a] - color[*prev(bck) + 1] <= D){
            good.insert(a);
        }
    }
    cout << (good.count(N - 1) ? "YES" : "NO");
}
