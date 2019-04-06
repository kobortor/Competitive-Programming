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

    while (n--) {
        string s;
        cin >> s;

        sort(allof(s));

        bool good = true;
        for (int a = 0; a + 1 < (int) s.size(); a++){
            good &= s[a] + 1 == s[a + 1];
        }

        cout << (good ? "Yes\n" : "No\n");
    }
}
