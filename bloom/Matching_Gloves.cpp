#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

map<string, pii> mp;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;

    for(int a = 0; a < N; a++){
        string s;
        cin >> s;
        string r = s;
        reverse(allof(r));

        if(r == s){
            //continue
        } else if (r < s){
            mp[r].second++;
        } else {
            mp[s].first++;
        }
    }

    int ans = 0;
    for(pair<string, pii> p : mp){
        if(p.second.first != p.second.second){
            cout << -1;
            return 0;
        } else {
            ans += p.second.first;
        }
    }

    cout << ans;
}
