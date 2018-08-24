#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, K;
    string S;
    cin >> N >> K;
    cin >> S;

    int overlap = 0;
    for(int a = N - 1; a >= 1; a--){
        if(S.substr(N - a) == S.substr(0, a)){
            overlap = a;
            break;
        }
    }

    cout << S;
    for(int a = 2; a <= K; a++){
        cout << S.substr(overlap);
    }

}
