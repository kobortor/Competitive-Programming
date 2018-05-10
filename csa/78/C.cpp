#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool banned[10];

string str;

ll power[20];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int avail = 0;
    for(int a = 0; a < 10; a++){
        cin >> banned[a];
        if(!banned[a]) avail++;
    }
    cin >> str;

    power[0] = 1;
    for(int a = 1; a < 20; a++){
        power[a] = power[a-1] * avail;
    }

    ll ans = !banned[0];
    for(int a = 1; a < (int)str.size(); a++){
        ll tmp = power[1];
        if(!banned[0]){
            tmp--;
        }
        ans += tmp * power[str.size() - a - 1];
    }

    for(int a = 0; a < (int)str.size(); a++){
        int under = 0;
        for(int b = (a == 0) ? 1 : 0; b < str[a] - '0'; b++){
            if(!banned[b]) under++;
        }
        ans += under * power[str.size() - a - 1];
        if(!banned[str[a] - '0']){
            //continue on here
        } else {
            break;
        }
    }
    cout << ans;
}
