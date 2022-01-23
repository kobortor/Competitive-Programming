#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int val;
        vector<Node*> children;

        Node() {
            val = 0;
            children = vector<Node*>();
        }

        Node(int _val) {
            val = _val;
            children = vector<Node*>();
        }

        Node(int _val, vector<Node*> _children) {
            val = _val;
            children = _children;
        }
};

struct Query {
    int u; 
    char c; 
};

array<int, 26> dfs(
        Node* root, const string &s, vector<int> &answers,
        vector<vector<pair<char, int>>> &queries_arr) {
    array<int, 26> counts;
    fill(counts.begin(), counts.end(), 0);
    counts[s[root->val - 1] - 'a'] = 1;

    for (Node* child : root->children) {
        array<int, 26> tmp = dfs(child, s, answers, queries_arr);

        for (int i = 0; i < 26; i++) {
            counts[i] += tmp[i];
        }
    }

    for (pair<char, int> query : queries_arr[root->val - 1]) {
        answers[query.second] = counts[query.first - 'a'];
    }

    return counts;
}

vector<int> countOfNodes(Node* root, vector<Query> queries, string s) {
    vector<vector<pair<char, int>>> queries_arr(s.size());
    for (int i = 0; i < (int)queries.size(); i++) {
        queries_arr[queries[i].u - 1].push_back(make_pair(queries[i].c, i));
    }

    vector<int> answers(queries.size());

    dfs(root, s, answers, queries_arr);

    return answers;
}


