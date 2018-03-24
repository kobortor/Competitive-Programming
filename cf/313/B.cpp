#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

string str;
int arr[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    cin >> str;
    for(int a = 0; a + 1 < (int)str.size(); a++){
        if(str[a] == str[a + 1]){
            arr[a + 1]++;
        }
    }
    for(int a = 1; a < MAXN; a++){
        arr[a] += arr[a - 1];
    }
    int Q;
    cin >> Q;
    while(Q--){
        int l, r;
        cin >> l >> r;
        cout << arr[r - 1] - arr[l - 1] << "\n";
    }

}
