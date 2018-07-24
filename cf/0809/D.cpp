#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct node {
    int x, y, prio, lz;
    int minx, maxx, maxy;
    node *left, *right;
    node(int _x, int _y){
        x = _x;
        y = _y;

        minx = maxx = x;
        maxy = y;

        prio = rand();
        lz = 0;
        left = 0;
        right = 0;
    }
};

void pushdown(node* root){
    if(!root){
        return;
    }
    if(root->left){
        root->left->x += root->lz;
        root->left->y += root->lz;
        root->left->minx += root->lz;
        root->left->maxx += root->lz;
        root->left->maxy += root->lz;
        root->left->lz += root->lz;
    }

    if(root->right){
        root->right->x += root->lz;
        root->right->y += root->lz;
        root->right->minx += root->lz;
        root->right->maxx += root->lz;
        root->right->maxy += root->lz;
        root->right->lz += root->lz;
    }

    root->lz = 0;
}

void pushup(node* root){
    if(!root){
        return;
    }
    root->minx = root->x;
    root->maxx = root->x;
    root->maxy = root->y;

    if(root->left){
        root->minx = min(root->minx, root->left->minx);
        //root->maxx = max(root->maxx, root->left->maxx);
        root->maxy = max(root->maxy, root->left->maxy);
    }
    if(root->right){
        //root->minx = min(root->minx, root->right->minx);
        root->maxx = max(root->maxx, root->right->maxx);
        root->maxy = max(root->maxy, root->right->maxy);
    }
}

void split(node* root, node*& L, node*& R, int val){
    pushdown(root);
    if(!root){
        L = 0;
        R = 0;
        return;
    }

    if(root->x <= val){
        split(root->right, root->right, R, val);
        L = root;
    } else {
        split(root->left, L, root->left, val);
        R = root;
    }
    pushup(root);
}

void merge(node*& root, node* L, node *R){
    pushdown(root);
    if(!L || !R){
        root = max(L, R);
        return;
    } else if(L->prio >= R->prio){
        merge(L->right, L->right, R);
        root = L;
    } else {
        merge(R->left, L, R->left);
        root = R;
    }
    pushup(root);
}

void insert(node*& root, node* ins){
    pushdown(root);
    if(!root){
        root = ins;
        return;
    }

    if(ins->prio >= root->prio){
        split(root, ins->left, ins->right, ins->x);
        root = ins;
    } else if (root->x <= ins->x){
        insert(root->right, ins);
    } else {
        insert(root->left, ins);
    }
    pushup(root);
}

void update(node* root, int L, int R){
    pushdown(root);
    if(!root){
        return;
    }

    if(R < root->minx || L > root->maxx){
        return;
    }

    if(L <= root->x && root->x <= R){
        root->x++;
        root->y++;
        root->minx++;
        root->maxx++;
        root->maxy++;
    }

    if(L <= root->minx && root->maxx <= R){
        root->lz++;
        pushdown(root);
        pushup(root);
        return;
    }

    update(root->left, L, R);
    update(root->right, L, R);

    pushup(root);
}

int best_before(node* root, int val){
    if(root == nullptr){
        return 0;
    }

    pushdown(root);

    if(root->maxx < val){
        return root->maxy;
    }
    if(root->minx >= val){
        return 0;
    }

    int ans = 0;
    if(root->x < val){
        ans = root->y;
    }

    ans = max(ans, best_before(root->left, val));
    ans = max(ans, best_before(root->right, val));

    pushup(root);
    return ans;
}

node* root = nullptr;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    srand(time(0));

    int N;
    cin >> N;

    for(int a = 0; a < N; a++){
        int L, R;
        cin >> L >> R;

        int lft = best_before(root, L);

        update(root, L, R - 1);
        
        insert(root, new node(L, lft + 1));
    }

    cout << root->maxy;
}
