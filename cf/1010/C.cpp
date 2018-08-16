#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, K;

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

    cin >> N >> K;
    int G = K;

    while(N--){
        int X;
        cin >> X;
        G = gcd(G, X);
    }

    cout << K / G << "\n";
    for(int a = 0; a < K; a += G){
        cout << a << " ";
    }
}
