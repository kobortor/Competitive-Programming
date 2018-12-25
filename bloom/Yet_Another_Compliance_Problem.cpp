#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 505;

int cnt[26];

ll nck[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    for(int a = 0; a < MAXN; a++){
        nck[a][0] = 1;
        for(int b = 1; b <= a; b++){
            nck[a][b] = nck[a - 1][b] + nck[a - 1][b - 1];
        }
    }

    string s;
    cin >> s;

    for(char c : s) cnt[c - 'a']++;

    if(count_if(cnt, cnt + 26, [](int x){return x % 2;}) > 1){
        cout << 0;
    } else {
        int totlen = s.size() / 2;

        ll ways = 1;
        for(int a = 0; a < 26; a++){
            int num = cnt[a] / 2;
            ways *= nck[totlen][num];
            totlen -= num;
        }

        cout << ways;
    }
}
