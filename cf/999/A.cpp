#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

int N, K;
int arr[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;

    for(int a = 1; a <= N; a++){
        cin >> arr[a];
    }

    int L = 1, R = N;
    while(L <= N && arr[L] <= K){
        L++;
    }

    while(L <= R && arr[R] <= K){
        R--;
    }

    cout << N - (R - L + 1);
}
