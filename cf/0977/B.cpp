#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int cnt[26*26];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    string str;
    cin >> N >> str;
    for(int a = 1; a < (int)str.size(); a++){
        int id = int(str[a-1]-'A')*26 + int(str[a]-'A');
        cnt[id]++;
    }
    int maxv = max_element(cnt, cnt + 26 * 26) - cnt;
    cout << char('A' + maxv / 26) << char('A' + maxv % 26);
}
