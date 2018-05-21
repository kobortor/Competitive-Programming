#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, K, M, L;

vector<int> staves;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K >> L;
    M = N * K;
    for(int a = 0; a < M; a++){
        int x;
        cin >> x;
        staves.push_back(x);
    }
    sort(allof(staves));
    
    int num_good = upper_bound(allof(staves), staves[0] + L) - staves.begin();
    if(num_good < N){
        cout << 0;
        return 0;
    }

    ll sum = 0;
    int i1 = 0, i2 = num_good;
    for(int a = 0; a < N; a++){
        int remain = N - a - 1;

        sum += staves[i1];
        i1++;

        for(int b = 1; b < K; b++){
            if(i1 + remain >= num_good){
                i2++;
            } else {
                i1++;
            }
        }
    }
    cout << sum;
}
