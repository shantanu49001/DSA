#include<bits\stdc++.h>
//child are only two at max  for every node 
//data *left *right--->data members .
using namespace std;
class BinaryTreeNode{//node ban gyi--->containig left child node and right child node
public:
int  data;
BinaryTreeNode* left;
BinaryTreeNode* right;
BinaryTreeNode(int data){
   this->data=data;
   this->left=NULL;
   this->right=NULL;//to ignore garbage 

}
~BinaryTreeNode(){//har node khud delte hone se pehle apne saare child ko dlete krta hia jae
delete left;//even if delete left and right are jull no issues with that 
delete right;
}//delte null is allowed
};
int main(){
    BinaryTreeNode *root=new BinaryTreeNode(1);
    BinaryTreeNode *node1=new BinaryTreeNode(2);
    BinaryTreeNode *node2=new BinaryTreeNode(3);
    root->left=node1;
    root->right=node2;
    return 0;
}