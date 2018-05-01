#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 5e6 + 6;

set<int> primes;
bool taken[MAXN];
bool sieve[MAXN];

int val[MAXN];

void update(int x){
    vector<int> to_erase;
    for(int i : primes){
        if(i * i > x) break;
        if(x % i == 0){
            to_erase.push_back(i);
            for(int a = i; a < 200000; a += i){
                taken[a] = true;
            }
            while(x % i == 0){
                x /= i;
            }
        }
    }
    if(x != 1 && !taken[x]){
        to_erase.push_back(x);
        for(int a = x; a < 200000; a += x){
            taken[a] = true;
        }
    }
    for(int i : to_erase){
        primes.erase(i);
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    for(int a = 2; a < MAXN; a++){
        if(!sieve[a]){
            primes.insert(a);
            for(int b = 2 * a; b < MAXN; b += a){
                sieve[b] = true;
            }
        }
    }

    int N;
    cin >> N;
    
    for(int a = 1; a <= N; a++){
        cin >> val[a];
    }
    update(val[1]);
    cout << val[1] << " ";
    
    bool locked = true;
    for(int a = 2; a <= N; a++){
        if(!locked){
            cout << *primes.begin() << " ";
            primes.erase(primes.begin());
        } else {
            int nxt = val[a];
            while(taken[nxt]) nxt++;
            
            cout << nxt << " ";
            update(nxt);
            
            if(nxt != val[a]){
                locked = false;
            }
        }
    }
}
