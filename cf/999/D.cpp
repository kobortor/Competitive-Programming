#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int N, M;

int arr[MAXN];
vector<int> buckets[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;

    int R = N / M;

    for(int a = 1; a <= N; a++){
        cin >> arr[a];
        buckets[arr[a] % M].push_back(a);
    }

    vector<int> avail;

    for(int a = 0; a < M; a++){
        while((int)buckets[a].size() < R && !avail.empty()){
            buckets[a].push_back(avail.back());
            avail.pop_back();
        }
        while((int)buckets[a].size() > R){
            avail.push_back(buckets[a].back());
            buckets[a].pop_back();
        }
    }

    for(int a = 0; a < M; a++){
        while((int)buckets[a].size() < R && !avail.empty()){
            buckets[a].push_back(avail.back());
            avail.pop_back();
        }
    }

    ll ans = 0;
    for(int a = 0; a < M; a++){
        for(int i : buckets[a]){
            int mod = arr[i] % M;
            if(a < mod){
                ans += M - (mod - a);
                arr[i] += M - (mod - a);
            } else {
                ans += a - mod;
                arr[i] += a - mod;
            }
        }
    }

    cout << ans << "\n";
    for(int a = 1; a <= N; a++){
        cout << arr[a] << " ";
    }
}
