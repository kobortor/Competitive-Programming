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

    int cnt = 0;
    for (char c : s) {
        if (c == '1') cnt += 2;
    }

    if (cnt != n) {
        cout << "1\n" << s;
    } else {
        s.insert(1, " ");
        cout << "2\n" << s;
    }
}
