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

    int n;
    string s;
    cin >> n >> s;

    for (char c : s) cnt[c - 'a']++;

    if (n == 1 || *max_element(cnt, cnt + 26) > 1) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}
