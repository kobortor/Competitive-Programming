#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;

    int tot = 0;
    int minv = 0;
    int best = -1;
    int sum = 0;
    while(N--){
        int x;
        cin >> x;
        sum += x;
        
        tot += 1 - 2 * x;
        best = max(best, tot - minv);

        minv = min(minv, tot);
    }
    cout << sum + best;
}
