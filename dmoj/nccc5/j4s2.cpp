#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;

int N;
int arr[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a < N; a++){
        cin >> arr[a];
        arr[a] = N - arr[a];
    }
    
    int ans = 0;
    for(int a = 0; a < N; a++){
        for(int b = 0; b < a; b++){
            if(arr[a] < arr[b]){
                ans++;
            }
        }
    }
    cout << ans;
}
