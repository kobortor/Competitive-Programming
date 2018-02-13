#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e4 + 4;

int N;
string str[MAXN];
int orig[MAXN];
int val[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a < N; a++){
        cin >> str[a] >> orig[a];
        val[a] = orig[a];
    }
    sort(val, val + N);
    int cutoff = val[N / 2];

    for(int a = 0; a < N; a++){
        if(orig[a] <= cutoff){
            cout << str[a] << " is not cute. </3" << endl;
        } else {
            cout << str[a] << " is cute! <3" << endl;
        }
    }
}
