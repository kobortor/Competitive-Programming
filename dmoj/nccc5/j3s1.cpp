#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, X;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> X;
    int less = 0;
    int more = 0;
    int equal = 0;
    for(int a = 0; a < N; a++){
        int x;
        cin >> x;
        if(x < X){
            less++;
        }
        if(x == X){
            equal++;
        }
        if(x > X){
            more++;
        }
    }
    int ans = 0;
    ans += equal * less * more;
    ans += equal * (equal - 1) * more / 2;
    ans += equal * less * (equal - 1) / 2;
    ans += equal * (equal - 1) * (equal - 2) / 6;
    cout << ans;
}
