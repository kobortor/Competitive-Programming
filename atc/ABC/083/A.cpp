#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int A, B, C, D;
    cin >> A >> B >> C >> D;
    if(A + B == C + D){
        cout << "Balanced\n";
    } else if (A + B < C + D){
        cout << "Right\n";
    } else if (A + B > C + D){
        cout << "Left\n";
    }
}