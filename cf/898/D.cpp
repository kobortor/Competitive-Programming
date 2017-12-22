#include<bits/stdc++.h>

using namespace std;

int N, M, K;
vector<int> alarms;

int main(){
    cin >> N >> M >> K;
    while(N--){
        int x;
        cin >> x;
        alarms.push_back(x);
    }
    sort(alarms.begin(), alarms.end());

    int ans = 0;
    queue<int> q;
    for(int i : alarms){
        while(!q.empty() && q.front() <= i - M){
            q.pop();
        }
        if((int)q.size() + 1 >= K){
            ans++;
        } else {
            q.push(i);
        }
    }
    cout << ans;
}
