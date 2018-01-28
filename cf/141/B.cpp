#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int a, x, y;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> a >> x >> y;

    if(y % a == 0){
        cout << -1;
        return 0;
    }
    int row = y / a;
    if(row == 0){
        if(-a < x * 2 && x * 2 < a){
            cout << 1;
        } else {
            cout << -1;
        }
    } else if(row % 2 == 1){
        if(-a < x * 2 && x * 2 < a){
            cout << 3 * (row / 2) + 2;
        } else {
            cout << -1;
        }
    } else {
        if(-a < x && x < 0){
            cout << 3 * (row / 2);
        } else if (0 < x && x < a){
            cout << 3 * (row / 2) + 1;
        } else {
            cout << -1;
        }
    }
}
