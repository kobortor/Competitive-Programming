#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int x) : data(x), next(NULL) {}
};

Node* reverse(Node *head);

// Returns two points
pair<Node*, Node*> reverse_helper(Node* head) {
    if (head->next == nullptr || head->next->data % 2 == 1) {
        return make_pair(head, reverse(head->next));
    }

    pair<Node*, Node*> tmp = reverse_helper(head->next);
    head->next->next = head;
    return tmp;
}

Node* reverse(Node *head) {
    if (head == nullptr) {
        return head;
    }

    if (head->data % 2 == 1) {
        head->next = reverse(head->next);
        return head;
    }

    // otherwise head->data is even
    pair<Node*, Node*> tmp = reverse_helper(head);
    head->next = tmp.second;
    return tmp.first;
}

