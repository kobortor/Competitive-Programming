#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int X, Y;
    cin >> X >> Y;
    
    double v1 = Y * log(X);
    double v2 = X * log(Y);

    if(X == Y || (min(X, Y) == 2 && max(X, Y) == 4)){
        cout << "=";
    } else if (v1 < v2){
        cout << "<";
    } else {
        cout << ">";
    }
}
