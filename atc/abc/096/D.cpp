#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    vector<int> primes;
    for(int a = 2; a <= 55555; a++){
        bool is_prime = true;
        for(int b = 2; b * b <= a; b++){
            if(a % b == 0){
                is_prime = false;
            }
        }
        if(a % 5 == 1 && is_prime){
            primes.push_back(a);
        }
    }

    int N;
    cin >> N;
    for(int a = 0; a < N; a++){
        cout << primes[a] << " ";
    }
}
