#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, X, Y;
    cin >> N >> X >> Y;

    if(X > Y) {
        cout << N;
        return 0;
    }

    int tmp = 0;
    while(N--){
        int x;
        cin >> x;
        if(x <= X){
            tmp++;
        }
    }

    cout << (tmp + 1) / 2;
}
