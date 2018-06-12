#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int N, K;
int arr[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;
    for(int a = 0; a < N; a++){
        cin >> arr[a];
    }
    sort(arr, arr + N);

    int removed = 0;
    for(int a = 0, back = 0; a < N; a++){
        while(arr[back] != arr[a]){
            if(arr[a] <= arr[back] + K){
                removed++;
                back++;
            } else {
                back++;
            }
        }
    }

    cout << N - removed;
}
