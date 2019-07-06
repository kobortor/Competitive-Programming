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

    if (s[0] == '-') {
        string s1 = s;
        s1.erase(s1.end() - 1);

        string s2 = s;
        s2.erase(s2.end() - 2);

        cout << max(stoi(s1), stoi(s2));
    } else {
        cout << s;
    }
}
