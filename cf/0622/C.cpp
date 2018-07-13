#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int N, M;
int arr[MAXN];
int nxt[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;

    for(int a = 1; a <= N; a++){
        cin >> arr[a];
    }
    arr[N + 1] = -1;

    for(int a = 2; a <= N + 1; a++){
        if(arr[a] != arr[a - 1]){
            for(int b = a - 1; arr[a - 1] == arr[b]; b--){
                nxt[b] = a;
            }
        }
    }

    while(M--){
        int L, R, X;
        cin >> L >> R >> X;

        if(arr[L] != X){
            cout << L << "\n";
        } else {
            int id = nxt[L];
            if(id <= R){
                cout << id << "\n";
            } else {
                cout << "-1\n";
            }
        }
    }
}
