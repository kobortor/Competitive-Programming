#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int cnt[4];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;
    N *= 2;

    string sa, sb;
    cin >> sa >> sb;
    for(int a = 0; a < N; a++){
        int bit = 0;
        if(sa[a] == '1'){
            bit |= 1;
        }
        if(sb[a] == '1'){
            bit |= 2;
        }

        cnt[bit]++;
    }

    int n1 = 0, n2 = 0;
    for(int a = 0; a < N; a++){
        int id = 3;
        while(!cnt[id]){
            id--;
        }

        cnt[id]--;

        if(a % 2 == 0 && (id & 1)){
            n1++;
        }
        if(a % 2 == 1 && (id & 2)){
            n2++;
        }
    }

    if(n1 == n2){
        cout << "Draw";
    } else if (n1 > n2){
        cout << "First";
    } else {
        cout << "Second";
    }
}
