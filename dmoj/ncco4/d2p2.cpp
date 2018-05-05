#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 125;

int N, T;
int Si[MAXN], Ui[MAXN];

const int LIM = 10150;
int dp1[LIM];
int dp2[LIM];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> T;
    for(int a = 1; a <= N; a++) cin >> Si[a];
    for(int a = 1; a <= N; a++) cin >> Ui[a];

    for(int a = 1; a <= N; a++){
        Ui[a] = min(Ui[a], LIM / Si[a]);
    }

    memset(dp1, 0x3f, sizeof dp1);
    dp1[0] = 0;

    memset(dp2, 0x3f, sizeof dp2);
    dp2[0] = 0;

    for(int a = 1; a <= N; a++){
        //remove as needed
        int BND = 0;
        for(int i = 1; i <= Ui[a]; i++){
            BND += Si[a];
            for(int b = LIM - 1; b >= BND; b--){
                dp1[b] = min(dp1[b], dp1[b - Si[a]] + 1);
            }
        }

        //add as needed
        for(int b = Si[a]; b < LIM; b++){
            dp2[b] = min(dp2[b], dp2[b - Si[a]] + 1);
        }
    }

    int best = 1e9;
    for(int a = T; a < LIM; a++){
        //-a + b = -T
        //b = a - T

        int b = a - T;
        //cout << "remove " << a << " add " << b << " costs " << dp1[a] << " + " << dp2[b] << "\n";
        best = min(best, dp1[a] + dp2[b]);
    }

    if(best == 1e9){
        cout << "-1\n";
    } else {
        cout << best << "\n";
    }
}
