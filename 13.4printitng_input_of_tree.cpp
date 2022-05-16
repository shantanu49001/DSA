//we will use recurions in max problems here in trees
#include<bits\stdc++.h>
using namespace std;
#include<vector>
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T>*> children; //--->nodes of tress node formed
                                    // array of pointer nodes                              //--->having address of parent
    TreeNode(T data)
    { // pointer node me initialosation
        this->data = data;
    }
};
void printTree(TreeNode<int>* root){//this is getting treenode's root
//node is the input here
printf("%d:",root->data);//parent print
for (int i = 0; i < root->children.size(); i++){
    printf("%d,",root->children[i]->data);
    //dono child printed
}
printf("\n");
//ab ye dono child bhi is tarah parent banke explore
for (int i = 0; i < root->children.size(); i++)
{
    printTree(root->children[i]);//recursion
}


}
int main(){
    TreeNode<int>* root=new TreeNode<int>(1);
    TreeNode<int>* node1=new TreeNode<int>(2);
    TreeNode<int>* node2=new TreeNode<int>(3);
    root->children.push_back(node1);
    root->children.push_back(node2);
    printTree(root);
    return 0;
}
//but 


/**
 *    1              1
 * 2     3            2
 *                     3---->both are samme
 * 
 * */