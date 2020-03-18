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
        int n, m;
        cin >> n >> m;
        int sum = 0;
        while (n--) {
            int ai;
            cin >> ai;
            sum += ai;
        }

        cout << min(m, sum) << "\n";
    }
}
