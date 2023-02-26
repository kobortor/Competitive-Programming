#include <bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<ll, ll> pll;

const int MAXN = 5e5 + 5;

struct edge {
    ll u, v, c;
    bool to_steal;
    bool taken;
} edges[MAXN];
bool station[MAXN];

ll sum[MAXN];
vector<pll> adj[MAXN];
vector<pll> waiting[MAXN];
vector<int> to_check;

void propagate(int pos) {
    if (station[pos]) {
        while (!waiting[pos].empty()) {
			// cout << "Added back " << waiting[pos].back().second << endl;
            to_check.push_back(waiting[pos].back().second);
            waiting[pos].pop_back();
        }
    } else {
        while (!waiting[pos].empty() && waiting[pos].back().first <= sum[pos]) {
			// cout << "Added back " << waiting[pos].back().second << endl;
            to_check.push_back(waiting[pos].back().second);
            waiting[pos].pop_back();
        }
    }
}

void testcase() {
    int n, p;
    cin >> n >> p;

	to_check.clear();
    for (int i = 1; i <= n; i++) {
		sum[i] = 0;
        adj[i].clear();
        station[i] = false;
		waiting[i].clear();
    }

	for (int i = 1; i <= p; i++ ){
		int pi;
		cin >> pi;
		station[pi] = true;
	}

    for (int i = 1; i <= n - 1; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].c;
        edges[i].to_steal = false;
		edges[i].taken = false;
    }

    int k;
    cin >> k;
    for (int i = 1; i <= k; i++) {
        int ki;
        cin >> ki;
        edges[ki].to_steal = true;
    }

    for (int i = 1; i <= n - 1; i++) {
        if (!edges[i].to_steal) {
			// cout << "Add edge " << edges[i].u << " - " << edges[i].v << " cost " << edges[i].c << endl;
			// sum[edges[i].u] += edges[i].c;
			// sum[edges[i].v] += edges[i].c;
            adj[edges[i].u].push_back({edges[i].v, edges[i].c});
            adj[edges[i].v].push_back({edges[i].u, edges[i].c});
        } else {
            waiting[edges[i].u].push_back({edges[i].c, i});
            waiting[edges[i].v].push_back({edges[i].c, i});
        }
    }

    for (int i = 1; i <= n; i++) {
		sort(allof(waiting[i]));
		reverse(allof(waiting[i]));
	}

	vector<int> answer;
    for (int i = 1; i <= n; i++) {
        if (station[i]) {
			// anything is fine
            propagate(i);
        } else {  // not station
			ll maxv = 0;
			for (pll p : adj[i]) {
				maxv = max(maxv, p.second);
				// cout << i << " add " << p.second << endl;
				sum[i] += p.second;
			}
			// cout << i << " -> " << sum[i] << endl;
			// cout << sum[i] << " - " << maxv << " vs " << maxv << endl;
			if (sum[i] - maxv < maxv) {
				cout << "NIE\n";
				return;
			}
			if (sum[i] % 2 == 1) {
				cout << "NIE\n";
				return;
			}
            propagate(i);
        }
    }

	while (!to_check.empty()) {
		int idx = to_check.back();
		to_check.pop_back();
		edge &e = edges[idx];
		// cout << "Checking " << idx << endl;
		
		if (e.taken) {
			continue;
		}
		if (!station[e.u] && (sum[e.u] < e.c || (sum[e.u] + e.c) % 2 == 1)) {
			// cout << "Reject " << idx << endl;
			continue;
		}
		if (!station[e.v] && (sum[e.v] < e.c || (sum[e.v] + e.c) % 2 == 1)) {
			// cout << "Reject2 " << idx << endl;
			continue;
		}

		e.taken = true;
		answer.push_back(idx);
		sum[e.u] += e.c;
		sum[e.v] += e.c;

        propagate(e.u);
        propagate(e.v);
	}

	if (answer.size() == k) {
		reverse(allof(answer));
		cout << "TAK\n";
		for (int i : answer) {
			cout << i << " ";
		}
		cout << "\n";
	} else {
		cout << "NIE\n";
	}
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int z;
    cin >> z;
    while (z--) {
        testcase();
    }
}
