#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N;
int arr[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a < N; a++){
        cin >> arr[a];
    }

    int val = *min_element(arr, arr + N);
    int cur = val % N;

    while(arr[cur] > val){
        cur = (cur + 1) % N;
        val++;
    }

    cout << cur + 1;
}
