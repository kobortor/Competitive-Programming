#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 505;

int N;
int C[MAXN];
int F[MAXN];
int S[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a < N - 1; a++){
        cin >> C[a] >> S[a] >> F[a];
    }

    for(int a = 0; a < N; a++){
        int tm = 0;
        int idx = a;
        while (idx != N - 1) {
            if (tm <= S[idx]) {
                tm = S[idx];
            } else if (tm % F[idx] != 0){
                tm -= tm % F[idx];
                tm += F[idx];
            }
            tm += C[idx];
            idx++;
        }
        cout << tm << "\n";
    }
}