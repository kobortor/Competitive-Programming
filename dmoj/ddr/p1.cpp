#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, M, P;
    cin >> N >> M >> P;

    int other = 6 - M - P;
    if(other == N){
        cout << "Stay\n";
    } else {
        cout << "Switch\n";
    }
}
