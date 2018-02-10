#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int lo = 4, hi = 1e5 + 5;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    while(lo <= hi){
        int mid = (lo + hi) / 2;
        int zeros = 0;

        for(int a = 5; a < 200000; a *= 5){
            zeros += mid / a;
        }
        cout << "Q " << zeros << endl;

        int tmp;
        cin >> tmp;
        if(tmp){
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << "A " << lo - 5 << endl;
}
