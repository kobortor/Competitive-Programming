#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int a, b, p;
        string s;
        cin >> a >> b >> p >> s;


        int i = s.size() - 1;
        while (i - 1 >= 0) {
            if (s[i - 1] == 'A') p -= a;
            else p -= b;

            if (p < 0) break;

            i--;

            while (i - 1 >= 0 && s[i - 1] == s[i]) {
                i--;
            }
        }

        cout << i + 1 << "\n";
    }
}
