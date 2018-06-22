#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int N, S;
int arr[MAXN];

int cnt[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> S;
    for(int a = 1; a <= N; a++){
        cin >> arr[a];
    }

    int ans = 0;

    if(arr[S] != 0){
        ans++;
        arr[S] = 0;
    }

    for(int a = 1; a <= N; a++){
        cnt[arr[a]]++;
    }

    int avail = 0;

    ans += cnt[0] - 1;
    avail += cnt[0] - 1;

    int bk = MAXN - 1;
    while(cnt[bk] == 0){
        bk--;
    }

    for(int a = 1; a < bk; a++){
        if(cnt[a] == 0){
            cnt[a] = 1;
            if(avail == 0){
                ans++;
                cnt[bk]--;
                while(cnt[bk] == 0){
                    bk--;
                }
            } else {
                avail--;
            }
        }
    }
    cout << ans;
}
