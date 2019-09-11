#include<bits/stdc++.h>
 
using namespace std;
 
#define allof(x) (x).begin(), (x).end()
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
 
 
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
 
    int T;
    cin >> T;
 
    while (T--) {
        // S + x > I + (E - x)
        // 2x > I + E - S
        // 2x >= I + E - S + 1
        int S, I, E;
        cin >> S >> I >> E;
        int geq_2 = I + E - S + 1;
        int min_x = max(0, (geq_2 + 1) / 2);
        cout << max(0, E - min_x + 1) << endl;
    }
}
