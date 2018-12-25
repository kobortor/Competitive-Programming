#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int intlen(int x){
    int ans = 0;
    while(x){
        ans++;
        x /= 10;
    }
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int K, cur = 1;
    cin >> K;

    while(true){
        int len = intlen(cur) + (cur % 4 != 0);
        if(K <= len){
            string s = to_string(cur);
            if(cur % 4 == 0){
                //nothing
            } else if (cur % 2 == 0){
                cur += '0';
            } else {
                cur += '2';
            }
            cout << s[K - 1];
            break;
        } else {
            K -= len;
            cur++;
        }
    }
}
