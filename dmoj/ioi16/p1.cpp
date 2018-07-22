#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;
pii W[MAXN];
int find_subset(int l, int u, int *w, int n, int *result){
    for(int a = 0; a < n; a++){
        W[a] = {w[a], a};
    }
    sort(W, W + n);

    ll tot = 0;
    for(int a = 0, b = 0; a < n; a++){
        tot += W[a].first;
        while(tot > u){
            tot -= W[b++].first;
        }

        if(tot >= l){
            for(int i = b; i <= a; i++){
                result[i - b] = W[i].second;
            }
            return a - b + 1;
        }
    }
    return 0;
}

#ifndef ONLINE_JUDGE
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int l, u, *w, n, *result;

    cin >> l >> u >> n;
    w = new int[n];
    for(int a = 0; a < n; a++){
        cin >> w[a];
    }
    result = new int[n];
    int sz = find_subset(l, u, w, n, result);
    cout << sz << "\n";
    for(int a = 0; a < sz; a++){
        cout << result[a] << " ";
    }

    delete[] w;
    delete[] result;
}
#endif
