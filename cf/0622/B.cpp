#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string tm;
    cin >> tm;
    
    int hr = (tm[0] - '0') * 10 + (tm[1] - '0');
    int mn = (tm[3] - '0') * 10 + (tm[4] - '0');

    int A;
    cin >> A;
    while(A--){
        mn++;
        if(mn == 60){
            mn = 0;
            hr++;
        }
        if(hr == 24){
            hr = 0;
        }
    }

    if(hr < 10){
        cout << 0;
    }
    cout << hr << ":";
    if(mn < 10){
        cout << 0;
    }
    cout << mn;
}
