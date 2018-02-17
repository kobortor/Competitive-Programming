#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int T;
    cin >> T;
    while(T--){
        priority_queue<int> pq1, pq2;
        while(1){
            int x;
            cin >> x;
            if(x == 0){
                break;
            } else if(x == -1){
                cout << pq1.top() << "\n";
                pq1.pop();
                if(pq1.size() < pq2.size()){
                    pq1.push(-pq2.top());
                    pq2.pop();
                }
            } else {
                pq1.push(x);
                while(pq1.size() > pq2.size() + 1){
                    pq2.push(-pq1.top());
                    pq1.pop();
                }
                while(!pq2.empty() && pq1.top() > -pq2.top()){
                    int v1 = pq1.top();
                    int v2 = pq2.top();
                    pq1.pop();
                    pq2.pop();

                    pq1.push(-v2);
                    pq2.push(-v1);
                }
            }
        }
    }
}
