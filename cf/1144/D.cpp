#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int n;
int arr[MAXN];
int freq[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for (int a = 1; a <= n; a++){
        cin >> arr[a];
        freq[arr[a]]++;
    }

    int mxv = max_element(freq, freq + MAXN) - freq;

    cout << n - freq[mxv] << "\n";

    for (int a = 2; a <= n; a++) {
        if (arr[a - 1] == mxv && arr[a] != mxv) {
            if (arr[a] < arr[a - 1]){
                cout << "1 " << a << " " << a - 1 << "\n";
            } else {
                cout << "2 " << a << " " << a - 1 << "\n";
            }
            arr[a] = mxv;
        }
    }

    for (int a = n - 1; a >= 1; a--) {
        if (arr[a + 1] == mxv && arr[a] != mxv) {
            if (arr[a] < arr[a + 1]){
                cout << "1 " << a << " " << a + 1 << "\n";
            } else {
                cout << "2 " << a << " " << a + 1 << "\n";
            }
            arr[a] = mxv;
        }
    }
}
