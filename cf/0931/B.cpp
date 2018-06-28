#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, A, B;
    cin >> N >> A >> B;

    A--;
    B--;
    
    int rnd = 0;
    while(A != B){
        A >>= 1;
        B >>= 1;
        rnd++;
    }
    if((1 << rnd) == N){
        cout << "Final!";
    } else {
        cout << rnd;
    }
}
