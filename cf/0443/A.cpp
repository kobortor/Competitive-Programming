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
    getline(cin, s);

    if (s == "{}") {
        cout << 0;
        return 0;
    }

    set<char> uniq;
    for (int a = 1; a < (int)s.size(); a += 3) {
        uniq.insert(s[a]);
    }

    cout << uniq.size();
}
