#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 3e5 + 5;

int N;

int lft[MAXN], rht[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll ans = 0;

    cin >> N;
    for(int a = 0; a < N; a++){
        string str;
        cin >> str;

        int L = 0, R = 0;
        for(int i = 0; i < (int)str.size(); i++){
            if(str[i] == '('){
                L++;
            } else {
                L--;
            }
            if(L < 0){
                break;
            }
        }
        
        for(int i = (int)str.size() - 1; i >= 0; i--){
            if(str[i] == ')'){
                R++;
            } else {
                R--;
            }
            if(R < 0){
                break;
            }
        }

        if(L != -1){
            ans += rht[L];
            lft[L]++;
        }
        if(R != -1){
            ans += lft[R];
            rht[R]++;
        }
    }
    cout << ans;
}
