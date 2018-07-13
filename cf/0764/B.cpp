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

    for(int i = 1; i <= N - i + 1; i += 2){
        swap(arr[i], arr[N - i + 1]);
    }

    for(int a = 1; a <= N; a++){
        cout << arr[a] << " ";
    }
}
