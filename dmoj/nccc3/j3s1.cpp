#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int cnt[26];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string str;
    cin >> str;
    for(char c : str){
        cnt[c - 'a']++;
    }
    sort(cnt, cnt + 26);
    reverse(cnt, cnt + 26);

    int ans = 0;
    for(int a = 2; a < 26; a++){
        ans += cnt[a];
    }
    cout << ans;
}
