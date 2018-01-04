#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


const int MAXN = 1e5 + 5;

long long N;
long long A[MAXN];

long long gcd(long long a, long long b){
    a = abs(a);
    b = abs(b);
    while(a % b){
        a %= b;
        swap(a, b);
    }
    return b;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a < N; a++){
        cin >> A[a];
    }
    
    long long minB = 1;
    for(int a = 0; a < N; a++){
        long long x;
        cin >> x;
        A[a] -= x;
        
        minB = max(minB, x + 1);
        
        if(A[a] < 0){
            cout << -1;
            return 0;
        }
    }
    
    for(int a = 0; a < N; a++){
        if(A[a] == 0){
            swap(A[a], A[N - 1]);
            N--;
            a--;
        }
    }
    if(N == 0){
        cout << minB;
        return 0;
    }
    
    long long GCD = A[0];
    for(int a = 1; a < N; a++){
        GCD = gcd(GCD, A[a]);
    }
    if(GCD < minB){
        cout << -1;
        return 0;
    }
    
    long long best = 2e9;
    for(long long i = 1; i * i <= GCD; i++){
        if(GCD % i == 0){
            if(i >= minB){
                best = min(best, i);
            }
            if(GCD / i >= minB){
                best = min(best, GCD / i);
            }
        }
    }
    cout << best;
}