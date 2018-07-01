#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 3e5 + 5;

ll N, X, Y;
char str[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> X >> Y;
    cin >> (str + 1);

    int zeros = 0;
    int ones = 0;

    for(int a = 1; a <= N; a++){
        int b = a;
        while(b + 1 <= N && str[b + 1] == str[a]){
            b++;
        }
        a = b;

        if(str[a] == '0'){
            zeros++;
        } else {
            ones++;
        }
    }

    if(zeros == 0){
        cout << 0;
        return 0;
    }

    /*
    op1 : 
    zero--
    ones--

    op2:
    swap(zeros, ones)
    */

    ll ans = min((ones - 1) * min(X, Y) + 2 * Y, (zeros - 1) * min(X, Y) + Y);
    cout << ans;
}
