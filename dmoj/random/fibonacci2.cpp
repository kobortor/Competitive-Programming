#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;

struct mat {
    ll val[2][2];

    mat(){
        memset(val, 0, sizeof val);
    }

    mat operator*(const mat &m) const {
        mat ans;
        for(int a = 0; a < 2; a++){
            for(int b = 0; b < 2; b++){
                for(int c = 0; c < 2; c++){
                    ans.val[a][b] += val[a][c] * m.val[c][b];
                    ans.val[a][b] %= mod;
                }
            }
        }
        return ans;
    }

};

ll solve(string &str){
    reverse(allof(str));
    mat ans;
    ans.val[0][0] = 0;
    ans.val[0][1] = 1;
    ans.val[1][0] = 1;
    ans.val[1][1] = -1;

    mat mult;
    mult.val[0][0] = 1;
    mult.val[0][1] = 1;
    mult.val[1][0] = 1;

    for(int a = 0; a < (int)str.size(); a++){
        int cnt = str[a] - '0';
        while(cnt--){
            ans = ans * mult;
        }

        mat tmp;
        tmp.val[0][0] = 1;
        tmp.val[1][1] = 1;


        for(int b = 0; b < 10; b++){
            tmp = tmp * mult;
        }

        mult = tmp;
    }
    return ans.val[0][0];
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string str;
    cin >> str;
    cout << solve(str);
}
