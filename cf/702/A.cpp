#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;


int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;

    int idx = 1;
    int prv;
    int ans = 1;

    cin >> prv;

    while(idx <= N){
        int input;
        int tmpidx = idx;
        while(tmpidx++ <= N && cin >> input && input > prv){ prv = input; }
        prv = input;
        ans = max(ans, tmpidx - idx);
        idx = tmpidx;
    }
    cout << ans;
}
