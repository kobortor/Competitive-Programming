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
    int vk = 0;
    for (int i = 0; i + 1 < (int)s.size(); i++) {
        if (s[i] == 'V' && s[i + 1] == 'K') {
            vk++;
        }
    }

    if (s.substr(0, 2) == "KK" || ((int)s.size() >= 2 && s.substr(s.size() - 2, 2) == "VV")) {
        cout << vk + 1;
        return 0;
    }

    for (int i = 0; i + 2 < (int)s.size(); i++) {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
            cout << vk + 1;
            return 0;
        }
    }

    cout << vk;
}
