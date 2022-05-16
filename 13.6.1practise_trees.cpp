#include <bits\stdc++.h>
#include<vector>
using namespace std;

class TreeNode
{
public:
    int data;
    vector<TreeNode* >  children;//this array stores address of nodes of tree node class
    TreeNode(int data)
    {
        this->data = data; // initilsed
        // vector me yaha pr add nhi karenge wo bahar kaemge
    }
};
int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *node1=new TreeNode(2);
    TreeNode *node2=new TreeNode(3);
    root->children.push_back(node1);
    root->children.push_back(node2);
    
    return 0;
}