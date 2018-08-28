#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    int cnt = 0;
    int totR = 0, totC = 0;
    for(int a = 1; a <= N; a++){
        string S;
        cin >> S;
        for(int b = 0; b < M; b++){
            if(S[b] == 'B'){
                totR += a;
                totC += b + 1;
                cnt++;
            }
        }
    }

    cout << totR / cnt << " " << totC / cnt;
}
