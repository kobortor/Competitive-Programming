#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;

int X2;
vector<int> primes;
bool sieve[MAXN];
bool reach1[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> X2;
    for(int a = 2; a < MAXN; a++){
        if(!sieve[a]){
            primes.push_back(a);
            for(int b = 2 * a; b < MAXN; b += a){
                sieve[b] = true;
            }
        }
    }
    int largest_factor = 0;
    for(int i : primes){
        if(X2 % i == 0){
            largest_factor = i;
        }
    }
    
    int start = X2 - largest_factor + 1;
    //cout << "Start at " << start << endl;
    int ans = start;
    for(int i : primes){
        if(start - 1 >= i && X2 / i != (start - 1) / i){
            //cout << "Test " << i << endl;
            ans = min(ans, (start - 1) / i * i + 1);
        }
    }
    cout << ans;
}
