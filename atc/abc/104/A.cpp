#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int x;
    cin >> x;
    if(x < 1200){
        cout << "ABC";
    } else if (x < 2800){
        cout << "ARC";
    } else {
        cout << "AGC";
    }
}
