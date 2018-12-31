#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 5005;
int arr[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;

    ll tot = 0;
    for(int a = 1; a <= N; a++){
        cin >> arr[a];
        tot += arr[a];
    }

    if(N == 1){
        if(arr[0] == 0) cout << "MULTIPLE SOLUTIONS";
        else cout << "NO SOLUTION";
    } else if (tot % (N - 1) == 0) {
        tot /= N - 1;
        for(int a = 1; a <= N; a++){
            if(tot - arr[a] < 0 || 255 < tot - arr[a]){
                cout << "NO SOLUTION";
                return 0;
            }
        }
        for(int a = 1; a <= N; a++){
            cout << tot - arr[a] << endl;
        }
    } else cout << "NO SOLUTION";
}
