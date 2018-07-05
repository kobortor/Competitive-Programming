#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    char prv = '?';

    string str;
    cin >> str;

    ll ans = 1;
    for(char c : str){
        if(c == 'd'){
            ans *= 9 + (prv != 'd');
        } else {
            ans *= 25 + (prv != 'c');
        }

        prv = c;
    }
    cout << ans;
}
