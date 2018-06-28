#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 5005;
const int MAXV = 10005;

int N;
int arr[MAXN];

vector<int> primes;
int get_type(int val){
    if(val == 0) return 0;
    int ans = 1;
    for(int i : primes){
        int cnt = 0;
        while(val % i == 0){
            val /= i;
            cnt ^= 1;
        }
        if(cnt) {
            ans *= i;
        }
    }
    ans *= val;
    return ans;
}

bool vis[MAXN];
bool sieve[MAXV];

int out[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    for(int a = 2; a < MAXV; a++){
        if(!sieve[a]){
            primes.push_back(a);
            for(int b = 2 * a; b < MAXV; b += a){
                sieve[b] = true;
            }
        }
    }

    cin >> N;

    vector<int> uniq;
    for(int a = 0; a < N; a++){
        int tmp;
        cin >> tmp;
        arr[a] = get_type(tmp);
        uniq.push_back(arr[a]);
    }
    sort(allof(uniq));
    uniq.erase(unique(allof(uniq)), uniq.end());

    for(int a = 0; a < N; a++){
        arr[a] = lower_bound(allof(uniq), arr[a]) - uniq.begin();
    }
    for(int a = 0; a < N; a++){
        memset(vis, false, sizeof vis);
        int ans = 0;
        for(int b = a; b < N; b++){
            if(uniq[arr[b]] == 0){
                //ignore
            } else if(!vis[arr[b]]){
                vis[arr[b]] = true;
                ans++;
            }
            out[max(1, ans)]++;
        }
    }
    for(int a = 1; a <= N; a++){
        cout << out[a] << " ";
    }
}
