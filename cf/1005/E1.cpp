#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int N, M;

int arr[MAXN];

int _[MAXN * 2];
int *cnt = _ + MAXN;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for(int a = 1; a <= N; a++){
        cin >> arr[a];
    }

    int m_pos = find(arr + 1, arr + N + 1, M) - arr;

    for(int a = m_pos, tot = 0; a >= 1; a--){
        if(arr[a] < M) {
            tot++;
        } else if (arr[a] > M){
            tot--;
        }

        cnt[tot]++;
    }

    ll ans = 0;
    for(int a = m_pos, tot = 0; a <= N; a++){
        if(arr[a] < M) {
            tot--;
        } else if (arr[a] > M){
            tot++;
        }

        ans += cnt[tot];
        ans += cnt[tot - 1];
    }

    cout << ans;
}
