#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string s;
    cin >> s;

    int ans = 9999;
    for(int a = 0; a * 2 < (int)s.size(); a++){
        bool good = true;
        for(int b = 0; a - b >= 0; b++){
            if(s[a - b] != s[a + b]){
                good = false;
                break;
            }
        }
        if(good) ans = min(ans, (int)s.size() - a * 2 - 1);
    }

    for(int a = 0; a * 2 + 1 < (int)s.size(); a++){
        bool good = true;
        for(int b = 0; a - b >= 0; b++){
            if(s[a - b] != s[a + b + 1]){
                good = false;
                break;
            }
        }
        if(good) ans = min(ans, (int)s.size() - a * 2 - 2);
    }

    cout << ans + s.size();
}
