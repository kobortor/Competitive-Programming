#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 4005;

int N, A, B, C;
int arr[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> A >> B >> C;

    fill(arr, arr + MAXN, -99999);
    arr[0] = 0;
    for(int a = 0; a <= N; a++){
        if(a >= A){
            arr[a] = max(arr[a], arr[a - A] + 1);
        }
        if(a >= B){
            arr[a] = max(arr[a], arr[a - B] + 1);
        }
        if(a >= C){
            arr[a] = max(arr[a], arr[a - C] + 1);
        }
    }
    cout << arr[N];
}
