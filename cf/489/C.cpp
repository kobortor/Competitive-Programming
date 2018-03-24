#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int M, S;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> M >> S;
    if(1 <= S && S <= 9 * M){
        //good
        string mins(M, '0');
        string maxs(M, '0');

        int v1 = S - 1;
        mins[0] = '1';
        for(int a = M - 1; a >= 0; a--){
            while(v1 > 0 && mins[a] != '9'){
                mins[a]++;
                v1--;
            }
        }

        int v2 = S;
        for(int a = 0; a < M; a++){
            while(v2 > 0 && maxs[a] != '9'){
                maxs[a]++;
                v2--;
            }
        }
        cout << mins << " " << maxs;

    } else if (M == 1 && S == 0) {
        cout << "0 0";
    } else {
        cout << "-1 -1";
    }
}
