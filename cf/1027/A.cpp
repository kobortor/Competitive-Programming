#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int T;
    cin >> T;

    while(T--){
        int N;
        string S;
        cin >> N >> S;

        bool good = true;
        for(int a = 0; 2 * a < N; a++){
            int x = S[a] - 'a';
            int y = S[N - a - 1] - 'a';

            good &= x == y || abs(x - y) == 2;
        }

        cout << (good ? "YES\n" : "NO\n");
    }
}
