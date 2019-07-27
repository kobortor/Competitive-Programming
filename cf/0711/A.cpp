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
    cin >> n;

    bool found = false;
    vector<pair<string, string>> vec(n);
    for (auto &ps : vec) {
        string s;
        cin >> s;

        string a = s.substr(0, 2), b = s.substr(3, 2);

        if (!found && a == "OO") {
            found = true;
            a = "++";
        }
        
        if (!found && b == "OO") {
            found = true;
            b = "++";
        }
        ps = {a, b};
    }

    if (found) {
        cout << "YES\n";
        for (auto ps : vec) {
            cout << ps.first << "|" << ps.second << "\n";
        }
    } else {
        cout << "NO";
    }
}
