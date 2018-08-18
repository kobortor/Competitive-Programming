#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int N, X;
int T[MAXN];
int rhs[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> X;

    for(int a = 1; a <= N; a++){
        cin >> T[a];
    }

    vector<int> LIS = {0x3f3f3f3f};
    for(int a = N; a >= 1; a--){
        int prv = lower_bound(allof(LIS), T[a], greater<int>()) - LIS.begin();
        if(prv == (int)LIS.size()){
            LIS.push_back(T[a]);
        } else {
            LIS[prv] = T[a];
        }
        rhs[a] = prv;
    }

    int ans = 0;
    LIS = {-0x3f3f3f3f};
    for(int a = 1; a <= N; a++){
        ans = max(ans, (int)(lower_bound(allof(LIS), T[a] + X) - LIS.begin() - 1) + rhs[a]);
        int prv = lower_bound(allof(LIS), T[a]) - LIS.begin();

        if(prv == (int)LIS.size()){
            LIS.push_back(T[a]);
        } else {
            LIS[prv] = T[a];
        }
    }

    cout << ans;
}
