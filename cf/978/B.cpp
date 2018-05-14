#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
string str;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> str;

    int ans = 0, cnt = 0;
    for(char c : str){
        if(c == 'x'){
            cnt++;
            if(cnt == 3){
                ans++;
                cnt = 2;
            }
        } else {
            cnt = 0;
        }
    }
    cout << ans;
}
