#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2005;

int N;
int arr[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a < N; a++){
        arr[a] = a + 1;
    }

    sort(arr, arr + N, [](int x, int y){
        int bit = 0;
        while((x & (1 << bit)) == (y & (1 << bit))){
            bit++;
        }
        return y & (1 << bit);
    });

    for(int a = 0; a < N; a++){
        cout << arr[a] << "\n";
    }
}
