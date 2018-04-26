#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2005;

int N;
int arr[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    int c0 = 0, c1 = 0;
    for(int a = 0; a < N; a++){
        cin >> arr[a];
        if(arr[a] == 2){
            c1++;
        }
        arr[a]--;
    }

    int ans = 0;
    for(int a = 0; a < N; a++){
        if(arr[a]) c1--;
        else c0++;

        int bestL = 0, bestR = 0;

        int cntL = 0, cntR = 0;
        for(int b = a; b >= 0; b--){
            cntL += (arr[b] ? 1 : -1);
            bestL = max(bestL, cntL);
        }
        for(int b = a + 1; b < N; b++){
            cntR += (!arr[b] ? 1 : -1);
            bestR = max(bestR, cntR);
        }

        ans = max(ans, c0 + c1 + bestL + bestR);
    }
    cout << ans;
}
