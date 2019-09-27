#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    
    priority_queue<int> pq;
    for (int a = 0; a < 31; a++) {
        if (n & (1 << a)) {
            pq.push(a);
        }
    }

    while ((int)pq.size() < k) {
        int top = pq.top();
        pq.pop();

        if (top == 0) {
            cout << "NO";
            return 0;
        }

        pq.push(top - 1);
        pq.push(top - 1);
    }

    if ((int)pq.size() != k) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        while (!pq.empty()) {
            cout << (1 << pq.top()) << " ";
            pq.pop();
        }
    }
}
