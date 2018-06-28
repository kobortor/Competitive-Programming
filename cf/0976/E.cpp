#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

ll N, A, B;
pll pokemon[MAXN];
ll diff[MAXN];
ll prefix[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> A >> B;
    B = min(B, N);

    ll base = 0;
    for(int a = 1; a <= N; a++){
        cin >> pokemon[a].first;
        cin >> pokemon[a].second;
        base += pokemon[a].second;
        diff[a] = max(0ll, pokemon[a].first - pokemon[a].second);
    }

    sort(diff + 1, diff + N + 1);
    reverse(diff + 1, diff + N + 1);

    ll ans = 0;

    for(int a = 1; a <= N; a++){
        prefix[a] = prefix[a-1] + diff[a];
    }

    if(B == 0){
        cout << base;
        return 0;
    }

    for(int a = 1; a <= N; a++){
        ll olddiff = max(0ll, pokemon[a].first - pokemon[a].second);
        ll newdiff = max(0ll, ((ll)pokemon[a].first << A) - pokemon[a].second);

        if(olddiff >= diff[B]){ //was originally going to be used anyways
            //cout << base << " + " << prefix[B] << " - " << olddiff << " + " << newdiff << endl;
            ans = max(ans, base + prefix[B] - olddiff + newdiff);
        } else { //was not originally going to be used
            //cout << base << " + " << prefix[B-1] << " + " << newdiff << endl;
            ans = max(ans, base + prefix[B-1] + newdiff);
        }
        //cout << a << " " << ans << endl;
    }
    cout << ans;
}
