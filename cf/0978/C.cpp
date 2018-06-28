#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int N, M;
ll dorm[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for(int a = 0; a < N; a++){
        cin >> dorm[a];
    }
    ll base = 0;
    int idx = 0;
    for(int a = 0; a < M; a++){
        ll x;
        cin >> x;
        x -= base;
        while(x > dorm[idx]){
            base += dorm[idx];
            x -= dorm[idx];
            idx++;
        }
        cout << idx + 1 << " " << x << "\n";
    }
}
