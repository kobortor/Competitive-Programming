#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int P, Y;

int small_factor(int x){
    for(int a = 2; a * a <= x; a++){
        if(x % a == 0){
            return a;
        }
    }
    return x;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> P >> Y;

    for(int a = Y; a >= P; a--) {
        if(small_factor(a) > P){
            cout << a;
            return 0;
        }
    }
    cout << -1;
}
