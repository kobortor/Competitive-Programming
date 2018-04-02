#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 3e5 + 5;

ll arr[MAXN];

multiset<ll> lft, rht;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;

    for(int a = 1; a <= N; a++){
        cin >> arr[a];
        rht.insert(arr[a]);
    }

    bool found = false;
    ll ans = -2e18;
    for(int a = 1; a <= N; a++){
        rht.erase(rht.find(arr[a]));

        if(!lft.empty() && !rht.empty()){
            auto rlow = rht.upper_bound(arr[a]);
            auto rhigh = prev(rht.end());

            auto llow = lft.begin();
            auto lhigh = lft.lower_bound(arr[a]);

            vector<ll> lhs, rhs;

            if(rlow != rht.end()){
                rhs.push_back(*rlow);
            }
            if(*rhigh > arr[a]){
                rhs.push_back(*rhigh);
            }

            if(*llow < arr[a]) {
                lhs.push_back(*llow);
            }
            if(lhigh != lft.begin()){
                lhs.push_back(*prev(lhigh));
            }
            for(ll L : lhs){
                for(ll R : rhs){
                    found = true;
                    ans = max(ans, L * R * arr[a]);
                }
            }
        }

        lft.insert(arr[a]);
    }
    if(found){
        cout << ans;
    } else {
        cout << -1;
    }
}
