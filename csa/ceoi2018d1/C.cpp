#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 10005;
const int MAXQ = 105;

int N, L, Q;

int arr[MAXN];
int _ans[2 * MAXN];
int* ans = _ans + MAXN;
int* ansback = ans;
vector<pii> queries;

int brute(int x, int y){
    int diff = 0;
    for(int a = 0; a < L; a++){
        diff += arr[x + a] != arr[y + a];
    }
    return diff;
}

int freq[MAXN];
int out[MAXQ][MAXN];

void writeans(int pos){
    int tot = -1; //ignore self
    for(int a = 0, b = 0; a < (int)queries.size(); a++){
        while(b <= queries[a].first){
            tot += freq[b++];
        }
        out[queries[a].second][pos] = tot;
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> L;
    for(int a = 0; a < N; a++){
        cin >> arr[a];
    }

    for(int a = 0; a + L - 1 < N; a++){
        *(ansback++) = brute(0, a);
        freq[ansback[-1]]++;
    }

    cin >> Q;
    for(int a = 0; a < Q; a++){
        int x;
        cin >> x;
        queries.push_back({x, a});
    }
    sort(allof(queries));

    writeans(0);
    for(int a = 1; a + L - 1 < N; a++){
        freq[ansback[-1]]--;
        ansback--;

        for(int i = 0; ans + i < ansback; i++){
            freq[ans[i]]--;
            ans[i] -= (arr[a - 1] != arr[i]);
            ans[i] += (arr[a + L - 1] != arr[i + L]);
            freq[ans[i]]++;
        }
        *(--ans) = brute(0, a);
        freq[ans[0]]++;
        writeans(a);
    }

    for(int a = 0; a < Q; a++){
        for(int b = 0; b + L - 1 < N; b++){
            cout << out[a][b] << " ";
        }
        cout << "\n";
    }
}
