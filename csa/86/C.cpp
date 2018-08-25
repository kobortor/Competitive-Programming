#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string str;
    cin >> str;

    int ans = 0;
    for(int a = 0; a < (int)str.size(); a++){
        if(a + 1 < (int)str.size() && str[a] != '?' && str[a] == str[a + 1]){
            ans++;
            str[a + 1] = '?';
        }
        if(a != 0 && a + 1 < (int)str.size() && str[a - 1] != '?' && str[a - 1] == str[a + 1]){
            ans++;
            str[a + 1] = '?';
        }
    }
    cout << ans;
}
