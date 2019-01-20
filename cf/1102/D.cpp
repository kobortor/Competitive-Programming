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
    string s;
    cin >> N >> s;

    int c0 = 0, c1 = 0, c2 = 0;
    for(char c : s){
        if(c == '0') c0++;
        if(c == '1') c1++;
        if(c == '2') c2++;
    }

    int targ = N / 3;
    for(int i = 0; i < N; i++){
        if(s[i] == '2' && c2 > targ){
            if(c0 < targ) s[i] = '0', c2--, c0++;
            else s[i] = '1', c2--, c1++;
        } else if (s[i] == '1' && c1 > targ){
            if(c0 < targ) s[i] = '0', c1--, c0++;
        }
    }

    for(int i = N - 1; i >= 0; i--){
        if(s[i] == '0' && c0 > targ){
            if(c2 < targ) s[i] = '2', c0--, c2++;
            else s[i] = '1', c0--, c1++;
        } else if (s[i] == '1' && c1 > targ){
            if(c2 < targ) s[i] = '2', c1--, c2++;
        }
    }

    cout << s;
}
