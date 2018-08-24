#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;
int N;
int arr[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        cin >> arr[a];
    }

    int ans = 0;
    for(int a = 1; a <= N; a++){
        int b = a;
        while(b + 1 <= N && arr[b + 1] <= arr[b] * 2){
            b++;
        }
        ans = max(ans, b - a + 1);
        a = b;
    }

    cout << ans;
}
