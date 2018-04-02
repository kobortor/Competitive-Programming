#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2005;

int T;
int arr[MAXN];

void testcase(){
    int N;
    cin >> N;

    for(int a = 1; a <= N; a++){
        cin >> arr[a];
    }
    for(int rm = 1; rm <= N; rm++){
        bool good = true;
        int prv = 0;
        for(int a = 1; a <= N; a++){
            if(a != rm){
                if(arr[a] < prv){
                    good = false;
                    break;
                }else{
                    prv = arr[a];
                }
            }
        }
        if(good) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> T;
    while(T--){
        testcase();
    }
}
