#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    string s;
    cin >> n >> s;

    s = s + 'W';

    vector<int> ans;

    int cnt = 0;
    for (char c : s) {
        if (c == 'W') {
            if (cnt) ans.push_back(cnt);
            cnt = 0;
        } else {
            cnt++;
        }
    }

    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i << " ";
    }
}
