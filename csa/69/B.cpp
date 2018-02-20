#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N;
int arr[MAXN];
int tmp[MAXN];

ll ans = 0;

ll c2(ll n){
    return n * (n - 1) / 2 + n;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a < N; a++){
        cin >> arr[a];
        tmp[a] = arr[a];
    }
    arr[N] = 1e9;
    tmp[N] = 1e9;
    N++;

    if(is_sorted(arr, arr + N)){
        ll prv = -1;
        for(int a = 1; a < N; a++){
            if(arr[a - 1] != arr[a]){
                ans += c2(a - prv - 1);
                prv = a - 1;
            }
        }
        cout << ans << "\n";
        cout << "1 1\n";
    } else {
        sort(tmp, tmp + N);
        int first = 1e9;
        int last = -1;
        for(int a = 0; a < N; a++){
            if(arr[a] != tmp[a]){
                first = min(first, a);
                last = max(last, a);
            }
        }

        reverse(arr + first, arr + last + 1);
        
        if(is_sorted(arr, arr + N)){
            cout << "1\n";
            cout << first + 1 << " " << last + 1 << "\n";
        } else {
            cout << 0;
        }
    }

}
