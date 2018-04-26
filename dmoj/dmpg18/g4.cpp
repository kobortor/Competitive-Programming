#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 5005;

ll N, A, B;

map<ll, ll> mp;
vector<ll> avail;
vector<ll> nums;

ll best[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> A >> B;
    for(ll a = 1; a <= N; a++){
        ll x;
        cin >> x;
        mp[x]++;
        nums.push_back(x);
    }
    sort(allof(nums));

    ll id = 0;
    ll cnt = 0;
    while(true){
        if(!cnt){
            auto iter = mp.lower_bound(id);
            if(iter == mp.end()){
                break;
            } else {
                id = iter->first;
            }
        }
        if(mp.count(id)){
            cnt += mp[id];
        }
        cnt--;
        avail.push_back(id);
        id++;
    }
    
    while(true){
        if(!cnt){
            auto iter = mp.upper_bound(id);
            if(iter == mp.begin()){
                break;
            } else {
                iter--;
                id = iter->first;
            }
        }
        if(mp.count(id)){
            cnt += mp[id];
        }
        cnt--;
        avail.push_back(id);
        id--;
    }   

    sort(allof(avail));
    avail.erase(unique(allof(avail)), avail.end());

    memset(best, 0x3f, sizeof best);
    best[0] = 0;
    for(int a = 0; a < (int)avail.size(); a++){
        for(int b = (int)nums.size() - 1; b >= 0; b--){
            ll cost = nums[b] < avail[a] ? (avail[a] - nums[b]) * A : (nums[b] - avail[a]) * B;
            best[b+1] = min(best[b+1], best[b] + cost);
        }
    }
    cout << best[nums.size()];
}
