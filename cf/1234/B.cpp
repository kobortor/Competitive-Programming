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

    set<int> avail;
    deque<int> dq;

    while (n--) {
        int id;
        cin >> id;

        if (avail.count(id)) {
            // ignore
        } else {
            if ((int)dq.size() == k) {
                avail.erase(dq.back());
                dq.pop_back();
            }

            dq.push_front(id);
            avail.insert(id);
        }
    }

    cout << dq.size() << "\n";
    for (int i : dq) cout << i << " ";
}
