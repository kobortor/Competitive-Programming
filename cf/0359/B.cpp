#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, K;
int arr[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;
    K *= 2;

    ll add = N;
    ll sub = N;

    for(int a = 1; a <= N * 2; a++){
        arr[a] = a;
    }

    for(int a = 2; a <= N * 2; a += 2){
        if(add - sub < K){
            swap(arr[a], arr[a - 1]);
            sub -= 2;
        }
    }

    for(int a = 1; a <= N * 2; a++){
        cout << arr[a] << " ";
    }
}
