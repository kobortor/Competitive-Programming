#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, P, T;
    cin >> N >> P >> T;
    T--;
    int moved = (T / 9) * 3;
    if(T % 9 >= 4){
        moved++;
    }
    if(T % 9 >= 5){
        moved--;
    }
    if(T % 9 >= 6){
        moved++;
    }
    if(T % 9 >= 7){
        moved++;
    }
    if(T % 9 >= 8){
        moved++;
    }

    int pos = P - moved;
    if(pos <= 0 || pos > N){
        cout << -1;
    } else {
        cout << pos;
    }
}
