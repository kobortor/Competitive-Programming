#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

ll N, U;

ll arr[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> U;
    for(int a = 0; a < N; a++){
        cin >> arr[a];
    }
    
    double best = -1;
    for(int a = 0, b = 0; a < N; a++){
        while(b + 1 < N && arr[b + 1] - arr[a] <= U){
            b++;
        }
        //cout << a << ", " << b << endl;
        if(b - a >= 2){
            //cout << "Get " << arr[b] - arr[a + 1] << " / " << arr[b] - arr[a] << endl;
            best = max(best, (double)(arr[b] - arr[a + 1]) / (arr[b] - arr[a]));
        }
    }
    if(best < 0){
        cout << -1;
    } else {
        cout << fixed << setprecision(15) << best;
    }
}
