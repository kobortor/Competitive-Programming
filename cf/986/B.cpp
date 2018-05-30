#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;

int N;
int arr[MAXN];
int pos[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        cin >> arr[a];
        pos[arr[a]] = a;
    }

    int swaps = 0;
    for(int a = 1; a <= N; a++){
        if(pos[a] == a){
            continue;
        }

        swap(pos[a], pos[arr[a]]);
        swap(arr[a], arr[pos[arr[a]]]);

        swaps++;
    }

    if(swaps % 2 == N % 2){
        cout << "Petr";
    } else {
        cout << "Um_nik";
    }
}
