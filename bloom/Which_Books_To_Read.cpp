#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

map<string, vector<string>> adj, books;
map<string, int> dist;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string person;
    int D, N, M;
    cin >> person >> D >> N >> M;

    for(int a = 1; a <= N; a++){
        string s;
        cin >> s;
        int idx = s.find('|');
        string name1 = s.substr(0, idx);
        string name2 = s.substr(idx + 1);

        adj[name1].push_back(name2);
        adj[name2].push_back(name1);
    }

    cin.ignore();
    for(int a = 1; a <= M; a++){
        string s;
        getline(cin, s);
        int idx = s.find('|');
        string name = s.substr(0, idx);
        while(idx != -1){
            idx++;
            int nidx = s.find('|', idx);
            string book = s.substr(idx, nidx - idx);
            books[name].push_back(book);
            idx = nidx;
        }
    }

    queue<pair<string, int>> q;
    dist[person] = 0;
    q.push({person, 0});

    set<string> toread;

    while(!q.empty()){
        string name = q.front().first;
        int curdist = q.front().second;

        toread.insert(allof(books[name]));

        q.pop();

        if(curdist + 1 <= D){
            for(string s : adj[name]){
                if(!dist.count(s) || dist[s] > curdist + 1){
                    dist[s] = curdist + 1;
                    q.push({s, curdist + 1});
                }
            }
        }
    }

    cout << toread.size() - books[person].size();
}
