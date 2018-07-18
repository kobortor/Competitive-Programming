#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N;
ll tot = 0;
ll arr[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    for(int a = 1; a <= N; a++){
        cin >> arr[a];
        tot += arr[a];
    }

    if(tot & 1){
        cout << -1;
    } else {
        vector<pii> soln;

        ll prvlen = 0;
        for(int a = 1; a <= N; a++){
            if(prvlen == 0){
                prvlen = arr[a];
            } else if (prvlen == arr[a]){
                prvlen = 0;
            } else {
                soln.push_back({max(arr[a], prvlen), max(arr[a], prvlen) - min(arr[a], prvlen)});
                prvlen = soln.back().second;
            }
        }

        if(prvlen != 0 && prvlen % 2 == 0){
            soln.push_back({prvlen, prvlen / 2});
        }

        cout << soln.size() << "\n";
        for(pii p : soln){
            cout << p.first << " " << p.second << "\n";
        }
    }
}
