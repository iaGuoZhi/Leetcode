#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node *> arrays;
        if(root==NULL)
            return root;
        arrays.push(root);

        while(arrays.size()){
            int size= arrays.size();
            for(;size>0;--size){
                Node *node1= arrays.front();
                arrays.pop();
                if(node1->left){
                    arrays.push(node1->left);
                }
                if(node1->right){
                    arrays.push(node1->right);
                }
                Node *node2=NULL;
                if(size>1)
                    node2=arrays.front();
                node1->next=node2;
            }
        }
        return root;
    }
};