#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a <= 2 * N; a++){
        for(int b = 0; abs(a - N) + b - N <= N; b++){
            int diff = abs(a - N) + abs(b - N);
            if(diff <= N){
                cout << N - diff;
            } else {
                cout << " ";
            }
            if(abs(a - N) + b - N == N){
                cout << endl;
            } else {
                cout << " ";
            }
        }
    }
}
