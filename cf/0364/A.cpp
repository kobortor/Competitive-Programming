#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

unordered_map<ll, ll> ump;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int A;
    string S;
    cin >> A >> S;

    int N = S.size();

    for(int a = 0; a < N; a++){
        ll sum = 0;
        for(int b = a; b < N; b++){
            sum += S[b] - '0';
            ump[sum]++;
        }
    }

    if(A == 0){
        cout << ump[0] * N * (N + 1) / 2 + ((ll)N * (N + 1) / 2 - ump[0]) * ump[0];
    } else {
        ump.erase(0);

        ll ans = 0;
        for(pll p : ump){
            if(A % p.first == 0){
                ans += p.second * ump[A / p.first];
            }
        }

        cout << ans;
    }
}
