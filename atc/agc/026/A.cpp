#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

int N;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    int prv = -1;
    int len = 0;
    int ans = 0;

    for(int a = 1; a <= N; a++){
        int x;
        cin >> x;
        if(x != prv){
            prv = x;
            ans += len / 2;
            len = 0;
        }

        len++;
    }

    ans += len / 2;
    cout << ans;
}
