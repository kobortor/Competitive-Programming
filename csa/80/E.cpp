#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 505;

int N;
int arr[MAXN];
vector<int> cuts[MAXN];

int query(){
    for(int a = 1; a <= N; a++){
        cout << arr[a] << " ";
    }
    cout << endl;
    int tmp;
    cin >> tmp;
    if(tmp == 0) {
        exit(0);
    }
    return tmp;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        cin >> arr[a];
    }

    if(arr[1] == arr[N]){
        query();
    }

    for(int a = 1; a <= N; a++){
        int lastv = arr[N];
        int tmp = N;
        while(arr[tmp] == arr[tmp - 1]){
            tmp--;
        }

        while(tmp > 1 && arr[tmp - 1] != arr[tmp]){
            swap(arr[tmp], arr[tmp - 1]);
            tmp--;
        }

        int cur = query();
        cuts[lastv].push_back(cur);
        if(arr[N] != lastv){
            cuts[arr[N]].insert(cuts[arr[N]].begin(), cur);
        }
    }

    for(int a = 1; a <= N; a++){
        if(cuts[a].empty()){
            continue;
        }

        for(int i = 1; i < (int)cuts[a].size(); i++){
            int delta = cuts[a][i] - cuts[a][i - 1];
            int before = (N - (cuts[a].size() - 1) + delta) / 2;
            arr[i + before] = a;
        }
    }

    assert(query() == 0);
}
