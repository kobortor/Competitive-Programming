#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int S, R;

map<string, vector<string>> skills, adj;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> S;
    for(int a = 0; a < S; a++){
        string name, skill;
        cin >> name >> skill;
        skills[name].push_back(skill);
    }

    cin >> R;
    for(int a = 0; a < R; a++){
        string A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    string name;
    cin >> name;

    vector<pair<string, vector<string>>> people;
    for(string s : adj[name]){
        vector<string> v = skills[s];
        for(string sk : skills[name]){
            auto iter = find(allof(v), sk);
            if(iter != v.end()){
                v.erase(iter);
            }
        }

        people.push_back({s, v});
    }

    vector<string> bestskill, bestnames;
    for(int state = 0; state < (1 << people.size()); state++){
        vector<string> skill, names;
        for(int a = 0; a < (int)people.size(); a++){
            if(state & (1 << a)){
                skill.insert(skill.end(), allof(people[a].second));
                names.push_back(people[a].first);
            }
        }

        sort(allof(skill));
        skill.erase(unique(allof(skill)), skill.end());

        if(skill.size() > bestskill.size()){
            bestskill = skill;
            bestnames = names;
        } else if (skill.size() == bestskill.size() && bestnames.size() > names.size()){
            bestskill = skill;
            bestnames = names;
        }
    }

    sort(allof(bestnames));
    cout << bestnames[0];
    for(int a = 1; a < (int)bestnames.size(); a++){
        cout << "," << bestnames[a];
    }
}
