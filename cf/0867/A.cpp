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

    int SF = 0;
    int FS = 0;

    for (int a = 1; a < n; a++) {
        if (s[a - 1] == 'S' && s[a] == 'F') {
            SF++;
        }
        if (s[a - 1] == 'F' && s[a] == 'S') {
            FS++;
        }
    }

    if (SF > FS) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}
