#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct node {
    // 0 = list
    // 1 = concat
    // 2 = shuffle
    // 3 = sort
    int type;
    list<node*> adj;
    list<int> lst;
};

pair<int, node*> parse(string &str, int idx) {
    if (str[idx] == '[') {
        list<int> lst;
        // parse list
        while (str[idx - 1] != ']') {
            idx++; // skip [ or ,
            int nxt = idx;
            while (isdigit(str[nxt])) {
                nxt++;
            }
            string tmp = str.substr(idx, nxt - idx);
            lst.push_back(stoi(tmp));
        }
        return {idx, new node{0, {}, lst}}
    } else if (str[idx] == 'c') {
        auto [nxt_idx, nd] = parse(str, idx + 7);
        auto [nxt_idx2, nd2] = parse(str, nxt_idx + 1);
        return {nxt_idx2 + 1, new node{1, {nd, nd2}, {}}};
    } else if (str[idx + 1] == 'h') {  // shuffle
        auto [nxt_idx, nd] = parse(str, idx + 8);
        return {nxt_idx + 1, new node{2, {nd}, {}}};
    } else {  // sort9
        auto [nxt_idx, nd] = parse(str, idx + 7);
        return {nxt_idx + 1, new node{3, {nd}, {}}};
    }
}

node* trim(node *root, bool seen) {
    if (seen && root->type >= 2) {
        return trim(root->adj.front(), seen);
    }
    list<node*> new_adj;
    for (node *nd : root->adj) {
        new_adj = trim(nd, seen || (root->type >= 2));
    }
    return new node{root->type, new_adj, root->lst};
}

void lower_traverse(node* root, list<int> &lst) {
    if (root->type == 0) {
        lst.merge(root->lst);
    } else {
        for (node* nd : root->adj) {
            lower_traverse(nd, lst);
        }
    }
}

void flatten_traverse(node* root, list<node*> &nodes) {
    if (root->type == 0) { // literal
        nodes.push_back(root);
    } else if (root->type == 1) { // concat
        for (node* nd : root->adj) {
            flatten_traverse(nd, nodes);
        }
    } else { // sort or shuffle
        list<int> lst;
        lower_traverse(root, lst);
        nodes.push_back(new node{root->type, {}, lst});
    }
}

node* flatten(node* root) {
    list<node*> nodes;
    flatten_traverse(root, nodes);
    return new node{1, nodes, {}};
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string A, B;
    cin >> A >> B;

    node *trA = parse(A, 0).second;
    node *trB = parse(B, 0).second;
    trA = trim(trA, false);
    trB = trim(trB, false);

    trA = flatten(trA);
    trB = flatten(trB);



}
