/*
                        1
                2       3       4   
             5     6              9 
                 7   8
the way we printed-:1:2,3,4
                    2:5,6
                    3:
                    4:9
                    5:
                    6:7,8
                    9:
                    7:
                    8:
(every nodes says pehle meri baari).
pre order-:first print my root thrn others
1->2->5(agar idhar child hote to pehle wo hota coz beanch pehle poori print)->6->7->8
->3->4->9
*/
#include<bits\stdc++.h>
#include<vector>
#include<queue>
using namespace std;
class TreeNode{
    public:
    int data;
    vector<TreeNode *> children;
    TreeNode(int data){
        this->data=data;
    }
};
TreeNode* takeInput(){
    int rootData;
    printf("Enter data for root\n");
    scanf("%d",&rootData);
    TreeNode *root=new TreeNode(rootData);
    queue<TreeNode *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size()!=0)
    {
        TreeNode *front=pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        printf("Enter number of child nodes for node with data %d",front->data);
         scanf("%d",&numChild);
         for (int  i = 0; i < numChild; i++)
         {
             int childData;
             printf("Enter data for %dth child node of parent node with data %d: \n",i,front->data);
             scanf("%d",&childData);
             TreeNode *child=new TreeNode(childData);
             front->children.push_back(child);
             pendingNodes.push(child);
         }
         
    }
    
    return root;
}
//code for pre order-:-->use recursion to print preorder
//code for pre order-:-->use recursion to print preorder
//firy we want root to print as whole
void preorder(TreeNode *root){
    if(root==NULL){
        return;
    }
//first make a dry run yourself.s
    printf("%d->",root->data);//fist print root
    for (int  i = 0; i < root->children.size(); i++)
    {
        preorder(root->children[i]);
        //if next wala root hai wo print ho jayega warna 
        //wo agle wale childfren tak chala jayenga.s
    }
    
}


int main(){
    TreeNode *root=takeInput();
    preorder(root);
    return 0;
}