#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 51;

int N;
ll arr[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    if(N == 1){
        cout << 0;
        return 0;
    }

    ll sum = 0;
    int numodd = 0;
    for(int a = 0; a < N; a++){
        cin >> arr[a];
        sum += arr[a];
        if(arr[a] & 1){
            numodd++;
        }
    }

    sort(arr, arr + N);
    reverse(arr, arr + N);

    if(arr[0] * 2 >= sum){
        cout << sum - arr[0];
        return 0;
    } else if (numodd & 1) {
        cout << (sum - 1) / 2;
    } else {
        cout << sum / 2;
    }
}
