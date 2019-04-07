#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    map<string, int> substr;

    string str;
    cin >> str;

    int ans = str.size();
    for (int a = 0; a < (int)str.size(); a++) {
        string tmp = "";
        for (int b = a; b < (int)str.size(); b++) {
            tmp += str[b];

            int cost = tmp.size();
            for (int i = 0; i < (int)str.size(); ) {
                if (str.substr(i, tmp.size()) == tmp) {
                    i += tmp.size();
                } else {
                    i++;
                }
                cost++;
            }
            ans = min(ans, cost);
        }
    }
    cout << ans;
}
