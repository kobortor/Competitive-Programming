#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

int N;
map<string, int> mp;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a < N; a++){
        string str;
        cin >> str;
        mp[str]++;
    }

    int ans = 0;
    for(int a = 0; a < N; a++){
        string str;
        cin >> str;
        if(mp[str]){
            mp[str]--;
        } else {
            ans++;
        }
    }

    cout << ans << "\n";
}
