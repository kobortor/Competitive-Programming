#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string ord1, ord2, str;
    cin >> ord1 >> ord2 >> str;

    for (char c : str) {
        if (isdigit(c)) {
            cout << c;
        } else {
            for (int i = 0; i < 26; i++) {
                if (ord1[i] == tolower(c)) {
                    if (isupper(c)) {
                        cout << (char)toupper(ord2[i]);
                    } else {
                        cout << ord2[i];
                    }
                }
            }
        }
    }
}
