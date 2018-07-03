#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, L, R;

int arr[2][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> L >> R;
    for(int a = 1; a <= N; a++){
        cin >> arr[0][a];
    }

    for(int a = 1; a <= N; a++){
        cin >> arr[1][a];
    }

    bool good = true;
    for(int a = 1; a < L; a++){
        good &= arr[0][a] == arr[1][a];
    }
    for(int a = R + 1; a <= N; a++){
        good &= arr[0][a] == arr[1][a];
    }
    if(good){
        cout << "TRUTH";
    } else {
        cout << "LIE";
    }
}
