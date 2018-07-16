#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, A, B, C;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> A >> B >> C;

    int ans = 0;
    for(int a = 0; a <= A; a++){
        for(int b = 0; b <= B; b++){
            int rem = 2 * N - a - 2 * b;
            if(rem >= 0 && rem % 4 == 0 && C * 4 >= rem){
                ans++;
            }
        }
    }

    cout << ans;
}
