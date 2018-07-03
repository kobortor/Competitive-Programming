#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, A, B;
bool ans[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> A >> B;

    if(A == B){
        while(A--){
            cout << "1 ";
        }
        while(B--){
            cout << "2 ";
        }
        return 0;
    }

    priority_queue<pii> pq;
    for(int a = 1; a <= N; a++){
        int x;
        cin >> x;

        if(A < B){
            pq.push({x, -a});
        } else {
            pq.push({x, a});
        }
    }

    if(A < B){
        while(A--){
            ans[-pq.top().second] = true;
            pq.pop();
        }

        for(int a = 1; a <= N; a++){
            if(ans[a]){
                cout << "1 ";
            } else {
                cout << "2 ";
            }
        }
    } else {
        while(B--){
            ans[pq.top().second] = true;
            pq.pop();
        }

        for(int a = 1; a <= N; a++){
            if(ans[a]){
                cout << "2 ";
            } else {
                cout << "1 ";
            }
        }
    }

}
