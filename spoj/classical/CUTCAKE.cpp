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
    while(T--){
        ll N;
        cin >> N;

        //1+(1+2+3+...+x) = N
        //x(x+1)/2 = N-1;
        //x^2 + x - 2(N-1) = 0

        int ans = (int)ceil((-1 + sqrt(1 + 8 * (N - 1))) / 2.0 - 0.00000001);

        cout << ans << endl;
    }
}
