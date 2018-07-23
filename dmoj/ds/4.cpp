#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct node {
    int val, prio, sz;
    node* left, *right;
    node(int v){
        val = v;
        prio = rand();
        sz = 1;
        left = nullptr;
        right = nullptr;
    }
};

void pushup(node* root){
    if(root == nullptr){
        return;
    }
    root->sz = 1;
    if(root->left != nullptr){
        root->sz += root->left->sz;
    }
    if(root->right != nullptr){
        root->sz += root->right->sz;
    }
}

void split(node* root, node*& L, node*& R, int val){
    if(root == nullptr){
        L = nullptr;
        R = nullptr;
        return;
    }

    if(root->val <= val){
        split(root->right, root->right, R, val);
        L = root;
    } else {
        split(root->left, L, root->left, val);
        R = root;
    }
    
    pushup(root);
}

void merge(node*& root, node* L, node* R){
    if(L == nullptr || R == nullptr){
        root = max(L, R);
    } else if (L->prio >= R->prio){
        merge(L->right, L->right, R);
        root = L;
    } else {
        merge(R->left, L, R->left);
        root = R;
    }
    pushup(root);
}

void insert(node*& root, node* ins){
    if(root == nullptr){
        root = ins;
        return;
    }

    if(ins->prio >= root->prio){
        split(root, ins->left, ins->right, ins->val);
        root = ins;
    } else if(ins->val <= root->val){
        insert(root->left, ins);
    } else {
        insert(root->right, ins);
    }

    pushup(root);
}

void erase(node*& root, int val){
    if(root == nullptr){
        return;
    }
    if(root->val == val){
        node *tmp;
        merge(tmp, root->left, root->right);
        delete root;
        root = tmp;
    } else if (val < root->val){
        erase(root->left, val);
    } else if (val > root->val){
        erase(root->right, val);
    }

    pushup(root);
}

node* nth(node* root, int idx){
    if(root == nullptr){
        return nullptr;
    }

    int lsz = root->left == nullptr ? 0 : root->left->sz;

    if(idx < lsz){
        return nth(root->left, idx);
    } else if (idx == lsz){
        return root;
    } else {
        return nth(root->right, idx - lsz - 1);
    }
}

node* find(node* root, int val){
    if(root == nullptr){
        return nullptr;
    }

    if(root->val == val){
        return root;
    } else if (root->val < val){
        return find(root->right, val);
    } else {
        return find(root->left, val);
    }
}

int rnk(node* root, int val){
    if(root == nullptr){
        return 0;
    }
    int lsz = root->left == nullptr ? 0 : root->left->sz;

    if (val <= root->val){
        return rnk(root->left, val);
    } else {
        return lsz + 1 + rnk(root->right, val);
    }
}

void dfs(node* root){
    if(root == nullptr){
        return;
    }

    dfs(root->left);
    cout << root->val << " ";
    dfs(root->right);
}

node* root = nullptr;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    for(int a = 1; a <= N; a++){
        int v;
        cin >> v;
        insert(root, new node(v));
    }

    int xorv = 0;
    for(int a = 1; a <= M; a++){
        char ch;
        int v;
        cin >> ch >> v;

        v ^= xorv;
        if(ch == 'I'){
            insert(root, new node(v));
        } else if (ch == 'R'){
            erase(root, v);
        } else if (ch == 'S'){
            int ans = nth(root, v - 1)->val;
            cout << ans << "\n";
            xorv = ans;
        } else {
            node* tmp = find(root, v);
            int ans;
            if(tmp == nullptr){
                ans = -1;
            } else {
                ans = rnk(root, v) + 1;
            }
            cout << ans << "\n";
            xorv = ans;
        }
    }
    dfs(root);
}
