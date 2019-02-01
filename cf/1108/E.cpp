#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;
const int MAXM = 305;

int N, M;
int arr[MAXN];
int minv[MAXN];

pii ranges[MAXM];
int prefix[MAXM * 2];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for(int a = 1; a <= N; a++){
        cin >> arr[a];
    }

    vector<int> uniq;
    uniq.push_back(1);
    uniq.push_back(N + 1);
    for(int a = 1; a <= M; a++){
        cin >> ranges[a].first >> ranges[a].second;
        uniq.push_back(ranges[a].first);
        uniq.push_back(ranges[a].second + 1);
    }

    sort(allof(uniq));
    uniq.erase(unique(allof(uniq)), uniq.end());

    for(int a = 1; a <= M; a++){
        ranges[a].first = lower_bound(allof(uniq), ranges[a].first) - uniq.begin();
        ranges[a].second = lower_bound(allof(uniq), ranges[a].second + 1) - uniq.begin();
    }

    for(int a = 0; a + 1 < (int)uniq.size(); a++){
        minv[a] = *min_element(arr + uniq[a], arr + uniq[a + 1]);
    }

    pii best = pii(-1, -1);
    for(int a = 1; a <= N; a++){
        for(int b = 0; b < (int)uniq.size(); b++){
            prefix[b] = 0;
        }

        for(int b = 1; b <= M; b++){
            int l = uniq[ranges[b].first];
            int r = uniq[ranges[b].second] - 1;

            if(r < a || a < l){
                assert(ranges[b].first < ranges[b].second);
                prefix[ranges[b].first]++;
                prefix[ranges[b].second]--;
            }
        }

        int low = 1e9;
        int cur = prefix[0];
        for(int b = 1; b < (int)uniq.size(); b++) {
            low = min(low, minv[b - 1] - cur);
            cur += prefix[b];
        }

        best = max(best, pii(arr[a] - low, a));
    }

    cout << best.first << "\n";
    int pos = best.second;
    vector<int> applied;
    for(int a = 1; a <= M; a++){
        int l = uniq[ranges[a].first];
        int r = uniq[ranges[a].second] - 1;
        if (r < pos || pos < l){
            applied.push_back(a);
        }
    }

    cout << applied.size() << "\n";
    for(int i : applied) {
        cout << i << " ";
    }
}
