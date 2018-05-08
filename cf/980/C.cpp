#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, K;
int arr[MAXN];
int prv[256];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    memset(prv, -1, sizeof prv);

    cin >> N >> K;
    for(int a = 0; a < N; a++){
        cin >> arr[a];

        int tmp = arr[a];
        int head = -1;
        while(true){
            if(tmp < 0) {
                head = 0;
                break;
            }
            if(arr[a] - tmp >= K) {
                head = tmp + 1;
                break;
            }
            if(prv[tmp] != -1){
                if(arr[a] - prv[tmp] < K){
                    head = prv[tmp];
                } else {
                    head = tmp + 1;
                }
                break;
            }
            tmp--;
        }
        for(int b = tmp + 1; b <= arr[a]; b++){
            prv[b] = head;
        }
        cout << prv[arr[a]] << " ";
    }
}
