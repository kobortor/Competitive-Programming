#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 55;

int N;
int arr[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    int numodd = 0;
    int numeven = 0;
    ll sum = 0;
    for(int a = 0; a < N; a++){
        cin >> arr[a];
        sum += arr[a];
        if(arr[a] & 1){
            numodd++;
        } else {
            numeven++;
        }
    }
    sort(arr, arr + N);
    reverse(arr, arr + N);
    
    if(arr[0] * 2 > sum || numodd % 2 || numeven % 2 != N % 2){
        cout << "NO";
    } else {
        cout << "YES";
    }
}
