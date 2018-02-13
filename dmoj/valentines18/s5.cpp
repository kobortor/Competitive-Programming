#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;
const int MAXV = 1e5 + 6;

int N, K;

int gcd(int u, int v){
    while(u % v){
        u %= v;
        swap(u, v);
    }
    return v;
}

int val[20][MAXN];

void build(){
    for(int a = 0; a + 1 < 20; a++){
        for(int b = 1; b + (2 << a) - 1 <= N; b++){
            val[a + 1][b] = gcd(val[a][b], val[a][b + (1 << a)]);
        }
    }
}

int query(int l, int r){
    int len = r - l + 1;
    int lg = log2(len);
    return gcd(val[lg][l], val[lg][r - (1 << lg) + 1]);
}

vector<int> primes;

int carol(int x){
    int ans = 0;
    for(int i : primes){
        while(x % i == 0){
            ans++;
            x /= i;
        }
    }
    return ans + (x != 1);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    for(int a = 2; a * a < MAXV; a++){
        bool prime = true;
        for(int i : primes){
            if(a % i == 0){
                prime = false;
                break;
            }
        }
        if(prime){
            primes.push_back(a);
        }
    }

    cin >> N >> K;
    for(int a = 1; a <= N; a++){
        cin >> val[0][a];
    }
    build();
    
    ll ans = 0;
    int L1 = 1, L2 = 1;
    for(int a = 1; a <= N; a++){
        while(L1 <= a && carol(query(L1, a)) < K){
            L1++;
        }
        while(L2 <= a && carol(query(L2, a)) <= K){
            L2++;
        }
        ans += L2 - L1;
    }
    cout << ans;
}
