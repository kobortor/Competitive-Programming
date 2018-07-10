#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;

int arr[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;

    int half = N / 2 + 1;
    for(int a = 1; a <= N - 1; a += 2){
        arr[half - (a + 1) / 2] = a;
        arr[half + (a + 1) / 2 - 1] = a;
    }

    int front = (half - 1) * 2;
    for(int a = 2; a <= N - 1; a += 2) {
        arr[front + half + a / 2 + 1] = a;
        arr[front + half - a / 2 + 1] = a;
    }

    for(int a = 1; a <= 2 * N; a++){
        cout << N - arr[a] << " ";
    }
}
