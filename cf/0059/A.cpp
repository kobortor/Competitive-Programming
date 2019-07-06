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

    int diff = 0;
    for (char c : s) {
        if (isupper(c)) diff++;
        else diff--;
    }

    if (diff > 0) {
        for (char c : s) {
            cout << (char)toupper(c);
        }
    } else {
        for (char c : s) {
            cout << (char)tolower(c);
        }
    }
}
