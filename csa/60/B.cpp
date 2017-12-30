#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, E1, E2;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> N >> E1 >> E2;
    if (E1 > E2) {
        swap(E1, E2);
    }

    int ans = 0;
    for(int a = 0; a < N; a++){
        int A, B;
        cin >> A >> B;
        if(A < B){
            ans += E1 <= A;
        } else {
            ans += A <= E2;
        }
    }
    cout << ans;
}