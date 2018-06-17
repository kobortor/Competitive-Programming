#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 13;

int N, M;
pii A[MAXN];
pii B[MAXN];

bool common_good[MAXN];

pair<bool, bool> goodA[MAXN], goodB[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for(int a = 1; a <= N; a++){
        cin >> A[a].first >> A[a].second;
        if(A[a].first > A[a].second){
            swap(A[a].first, A[a].second);
        }
    }
    for(int a = 1; a <= M; a++){
        cin >> B[a].first >> B[a].second;
        if(B[a].first > B[a].second){
            swap(B[a].first, B[a].second);
        }
    }

    for(int a = 1; a <= N; a++){
        for(int b = 1; b <= M; b++){
            if(A[a] == B[b]){
                continue;
            }

            if((A[a].first == B[b].first || A[a].first == B[b].second)) {
                common_good[A[a].first] = true;
                goodA[a].first = true;
                if(A[a].first == B[b].first){
                    goodB[b].first = true;
                } else {
                    goodB[b].second = true;
                }
            }

            if(A[a].second == B[b].first || A[a].second == B[b].second){
                common_good[A[a].second] = true;
                goodA[a].second = true;

                if(A[a].second == B[b].first){
                    goodB[b].first = true;
                } else {
                    goodB[b].second = true;
                }
            }
        }
    }

    if(count(common_good, common_good + MAXN, true) == 1) {
        cout << find(common_good, common_good + MAXN, true) - common_good;
    } else {
        bool allgood = true;
        for(int a = 1; a <= N; a++){
            allgood &= !goodA[a].first || !goodA[a].second;
        }
        for(int b = 1; b <= M; b++){
            allgood &= !goodB[b].first || !goodB[b].second;
        }

        if(allgood){
            cout << 0;
        } else {
            cout << -1;
        }
    }
}
