#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2005;

int N;
int arr[MAXN];
int gcd(int a, int b){
    while(a % b){
        a %= b;
        swap(a, b);
    }
    return b;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    int num1 = 0;
    for(int a = 0; a < N; a++){
        cin >> arr[a];
        num1 += arr[a] == 1;
    }
    if(num1){
        cout << N - num1;
        return 0;
    }

    int best = 1e9;
    for(int a = 0; a < N; a++){
        int val = 0;
        for(int b = a; b < N; b++){
            val = gcd(val, arr[b]);
            if(val == 1){
                best = min(best, b - a);
                break;
            }
        }
    }
    if(best == 1e9){
        cout << -1;
    } else {
        cout << best + N - 1;
    }
}
