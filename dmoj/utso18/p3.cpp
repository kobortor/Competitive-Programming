#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;

int N, T, K, V;
bool taken[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> T >> K >> V;
    for(int a = 1; a <= V; a++){
        int x;
        cin >> x;
        taken[x] = true;
    }

    int ans = 0;
    vector<int> empty;

    for(int a = 1, sum = 0; a <= N; a++){
        if(a > T){
            sum -= taken[a - T];
        }

        if(taken[a] == 0){
            empty.push_back(a);
        }
        sum += taken[a];

        if(a >= T){
            while(sum < K){
                taken[empty.back()] = true;
                empty.pop_back();
                sum++;
                ans++;
            }
        }
    }

    cout << ans;
}
