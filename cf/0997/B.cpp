#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int solve(int N){
    set<int> st;
    for(int a = 0; a <= N; a++){
        for(int b = 0; a + b <= N; b++){
            for(int c = 0; a + b + c <= N; c++){
                int d = N - a - b - c;
                st.insert(4 * b + 9 * c + 49 * d);
            }
        }
    }

    return st.size();
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll N;
    cin >> N;
    if(N <= 11){
        cout << solve(N);
    } else {
        cout << solve(11) + 49ll * (N - 11);
    }
}
