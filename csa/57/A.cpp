#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string S;
int cost[26];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> S;
    for(int a = 0; a < 26; a++){
        cin >> cost[a];
    }

    int ans = 0;
    for(char c : S){
        ans += cost[c - 'a'];
    }

    cout << ans;
}
