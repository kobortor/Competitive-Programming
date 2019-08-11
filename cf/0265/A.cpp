#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int idx = 0;
    string s, t;
    cin >> s >> t;
    for (char c : t) {
        if (s[idx] == c) idx++;
    }

    cout << idx + 1;
}
