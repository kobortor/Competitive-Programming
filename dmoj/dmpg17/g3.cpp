#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll N, K;
string str;

ll ext_gcd(ll A, ll B, ll &X, ll &Y){
    if(B == 0){
        X = 1;
        Y = 0;
        return A;
    } else {
        ll G = ext_gcd(B, A % B, Y, X);
        //(A - [A/B]*B) * X + B * Y = G
        //A*X + B*(Y-[A/B]*X) = G
        Y -= A/B*X;
        return G;
    }
}

int tp(char c){
    if(c == '(' || c == ')'){
        return 0;
    }
    if(c == '[' || c == ']'){
        return 1;
    }
    if(c == '{' || c == '}'){
        return 2;
    }
    if(c == '<' || c == '>'){
        return 3;
    }
    assert(false);
    return -1;
}

int dir(char c){
    if(c == '<' || c == '[' || c == '(' || c == '{'){
        return 0;
    } else {
        return 1;
    }
}

char letters[][3] = {"()", "[]", "{}", "<>"};


ll cost[3];
ll cnt[3];
ll has_odd[3];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;
    cin >> cost[0] >> cost[1] >> cost[2];
    cin >> str;

    vector<pii> pairs;
    vector<int> stk;

    for(int a = 0; a < N; a++){
        if(dir(str[a]) == 0){
            stk.push_back(a);
        } else {
            pairs.push_back({stk.back(), a});
            stk.pop_back();
        }
    }

    for(pii p : pairs){
        char c1 = str[p.first];
        char c2 = str[p.second];

        cnt[tp(c1)]++;
        cnt[tp(c2)]++;

        if(tp(c1) != tp(c2)){
            has_odd[tp(c1)] = true;
            has_odd[tp(c2)] = true;
        }
    }

    int n0 = 0;
    if(!cost[1])n0++;
    if(!cost[2])n0++;

    for(int a = 0; a < 3; a++){
        if(!has_odd[a]){
            cost[a] *= 2;
            cnt[a] /= 2;
        }
    }


    bool good = false;
    ll G, X, Y;
    G = ext_gcd(cost[1], cost[2], X, Y);

    for(ll nx = 0; nx <= cnt[0]; nx++){
        ll targ = K - nx * cost[0];
        if(n0 == 2 && targ == 0){
            good = true;
            cnt[0] = nx;
            cnt[1] = 0;
            cnt[2] = 0;
            break;
        }

        if((n0 == 1 && targ % max(cost[1], cost[2]) == 0)){
            if(cost[1]){
                if(0 <= targ / cost[1] && targ / cost[1] <= cnt[1]){
                    good = true;
                    cnt[0] = nx;
                    cnt[1] = targ / cost[1];
                    cnt[2] = 0;
                }
                break;
            }
            if(cost[2]){
                if(0 <= targ / cost[2] && targ / cost[2] <= cnt[2]){
                    good = true;
                    cnt[0] = nx;
                    cnt[1] = 0;
                    cnt[2] = targ / cost[2];
                }
                break;
            }
        }
        
        if(n0 == 0 && targ % G == 0){
            ll mod = cost[2] / G;
            ll TX = X % mod * (targ / G) % mod;
            TX += mod;
            TX %= mod;
            if(TX * cost[1] > targ || TX > cnt[1]){
                continue;
            }

            TX += min((targ - TX * cost[1]) / (cost[1] * mod) * mod, (cnt[1] - TX) / mod * mod);
            while((TX + mod) * cost[1] <= targ && TX + mod <= cnt[1]){
                TX += mod;
            }

            if((K - nx * cost[0] - TX * cost[1]) % cost[2] == 0){
                ll TY = (K - nx * cost[0] - TX * cost[1]) / cost[2];
                if(0 <= TY && TY <= cnt[2]){
                    good = true;
                    cnt[0] = nx;
                    cnt[1] = TX;
                    cnt[2] = TY;
                    break;
                }
            }
        }
    }
    if(!good){
        cout << "impossible\n";
        return 0;
    }

    for(int a = 0; a < 3; a++){
        if(!has_odd[a]){
            cost[a] /= 2;
            cnt[a] *= 2;
        }
    }

    for(pii p : pairs){
        char &c1 = str[p.first];
        char &c2 = str[p.second];
        if(tp(c1) == tp(c2)){
            if(cnt[tp(c1)] >= 2){
                cnt[tp(c1)] -= 2;
                if(tp(c1) == 0){
                    c1 = '[';
                    c2 = ']';
                } else {
                    c1 = '(';
                    c2 = ')';
                }
            } else {
                c1 = '<';
                c2 = '>';
            }
        }
    }

    for(pii p : pairs){
        char &c1 = str[p.first];
        char &c2 = str[p.second];

        int tp1 = tp(c1);
        int tp2 = tp(c2);
        if(tp1 != tp2){
            if(cnt[tp1] && cnt[tp2]){
                cnt[tp1]--;
                cnt[tp2]--;
                c1 = letters[3 - tp1 - tp2][0];
                c2 = letters[3 - tp1 - tp2][1];
            } else if (cnt[tp1]){
                cnt[tp1]--;
                c1 = letters[tp2][0];
            } else if (cnt[tp2]){
                cnt[tp2]--;
                c2 = letters[tp1][1];
            } else {
                c1 = '<';
                c2 = '>';
            }
        }
    }
    cout << str << "\n";
}
