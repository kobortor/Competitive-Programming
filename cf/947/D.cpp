#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

string src, targ;

int NBC1[MAXN];
int NBC2[MAXN];

set<int> notA1;
set<int> notA2;

int Q;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    notA1.insert(0);
    notA2.insert(0);

    cin >> src >> targ;
    for(int a = 1; a <= (int)src.size(); a++){
        if(src[a - 1] != 'A'){
            NBC1[a]++;
            notA1.insert(a);
        }
        NBC1[a] += NBC1[a - 1];
    }
    for(int a = 1; a <= (int)targ.size(); a++){
        if(targ[a - 1] != 'A'){
            NBC2[a]++;
            notA2.insert(a);
        }
        NBC2[a] += NBC2[a - 1];
    }

    cin >> Q;
    while(Q--){
        int A, B, C, D;
        cin >> A >> B >> C >> D;

        int backA1 = min(B - A + 1, B - *prev(notA1.upper_bound(B)));
        int backA2 = min(D - C + 1, D - *prev(notA2.upper_bound(D)));

        int cnt1 = NBC1[B] - NBC1[A - 1];
        int cnt2 = NBC2[D] - NBC2[C - 1];

        if(backA2 > backA1){
            cout << "0";
            continue;
        }

        if(backA1 == backA2 && cnt2 != 0 && cnt1 == 0){
            cout << "0";
            continue;
        }

        if((backA2 - backA1) % 3 != 0 || (cnt2 != 0 && cnt1 == 0)){
            //gotta cut some off
            cnt1 += 2;
        }

        //cout << cnt1 << " vs " << cnt2 << endl;
        if(cnt1 <= cnt2 && (cnt2 - cnt1) % 2 == 0){
            cout << "1";
        } else {
            cout << "0";
        }
    }
}
