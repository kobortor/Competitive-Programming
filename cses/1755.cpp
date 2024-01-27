#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string s;
    cin >> s;
    map<char, int> cnt;
    for (char ch : s) cnt[ch]++;
    int n_odd = 0;
    for (auto au : cnt) {
        if (au.second % 2) n_odd++;
    }
    if (n_odd > 1) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    string pre;
    for (auto au : cnt) {
        while (au.second >= 2) {
            au.second -= 2;
            pre += au.first;
        }
    }
    cout << pre;
    for (auto au : cnt) {
        if (au.second % 2 == 1) {
            cout << au.first;
        }
    }
    reverse(pre.begin(), pre.end());
    cout << pre;
}

