#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

int N, M;

int date[MAXN];
int req[MAXN];

bool taken[MAXN];
vector<int> exam[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for(int a = 1; a <= M; a++){
        int start;
        cin >> start >> date[a] >> req[a];
        taken[date[a]] = true;
        exam[start].push_back(a);
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> schedule;
    for(int a = 1; a <= N; a++){
        for(int i : exam[a]){
            pq.push({date[i], i});
        }
        if(taken[a]){
            schedule.push_back(M + 1);
            continue;
        }
        if(pq.empty()){
            schedule.push_back(0);
        } else {
            if(!pq.empty() && pq.top().first <= a){
                cout << -1;
                return 0;
            }
            schedule.push_back(pq.top().second);
            req[pq.top().second]--;
            if(req[pq.top().second] == 0){
                pq.pop();
            }
        }
    }
    if(!pq.empty()){
        cout << -1;
    } else {
        for(int i : schedule){
            cout << i << " ";
        }
    }
}
