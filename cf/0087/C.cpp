#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int sprague[MAXN];
int ans = -1;
int N;

int solve(int val){
    if(sprague[val] != -1){
        return sprague[val];
    }

    set<int> incl;
    for(int k = 2;; k++){
        int extra = k * (k - 1) / 2;
        int remain = val - extra;

        if(remain <= 0){
            break;
        }

        if(remain % k == 0){
            int init = remain / k;
            int xorv = 0;
            for(int a = 0; a < k; a++){
                xorv ^= solve(init + a);
            }
            incl.insert(xorv);

            if(val == N && xorv == 0){
                ans = k;
                return 0;
            }
        }
    }

    int mex = 0;
    while(incl.count(mex)){
        mex++;
    }
    return sprague[val] = mex;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    memset(sprague, -1, sizeof sprague);
    sprague[1] = 0;
    sprague[2] = 0;

    cin >> N;

    solve(N);
    cout << ans;
}
