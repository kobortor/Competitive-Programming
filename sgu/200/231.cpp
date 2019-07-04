#include<bits/stdc++.h>
 
using namespace std;
 
#define allof(x) (x).begin(), (x).end()
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
const int MAXN = 1e6 + 6;
bool sieve[MAXN];
 
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
 
    for (int a = 2; a < MAXN; a++) {
        if (!sieve[a]) {
            for (int b = 2 * a; b < MAXN; b += a) {
                sieve[b] = true;
            }
        }
    }
 
    int N;
    cin >> N;
 
    vector<int> ans;
    for (int a = 3; a + 2 <= N; a += 2) {
        if (!sieve[a] && !sieve[a + 2]) {
            ans.push_back(a);
        }
    }
 
    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << 2 << " " << i << "\n";
    }
}
