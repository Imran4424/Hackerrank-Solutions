#include <bits/stdc++.h>	

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};
*/
    int height(Node* root) 
    {
        if(NULL == root)
        {
            return -1;
        }

        int leftHeight = height(root -> left);
        int rightHeight = height(root -> right);

        if(leftHeight > rightHeight)
        {
            return leftHeight + 1;
        }

        return rightHeight + 1;
    }

    void printLevel(Node* root, int level)
    {
        if(NULL == root)
        {
            return;
        }

        if(0 == level)
        {
            cout << root -> data << " ";

            return;
        }

        printLevel(root -> left, level - 1);
        printLevel(root -> right, level - 1);
    }

    void levelOrder(Node* root) 
    {
        int treeHeight = height(root);

        for(int l = 0; l <= treeHeight; l++)
        {
            printLevel(root, l);
        }
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.levelOrder(root);
    return 0;
}
