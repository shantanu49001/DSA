#include<bits\stdc++.h>
#include<vector>
#include<queue>
using namespace std;
class TreeNode{//1.formation of node 
    public:
    int data;
    vector<TreeNode *> children;//2.vector functions work for children
    TreeNode(int data){
     this->data=data;
    }

};
void printTree(TreeNode *root){
    printf("%d:",root->data);//11.first printing the root 
    for (int i = 0; i < root-> children.size(); i++)//12.now printing thr root ke children me first ka data
    {
     printf("%d ",root->children[i]->data);

    }
    printf("\n");
    for (int  i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);//13.now calling root to be child of root current to initiate function again.
    }
    
    
}
TreeNode* takeInput(){//3.root returning function
int rootData;
printf("Enter data for root node\n");
scanf("%d",&rootData);//4.formation of root
TreeNode *root=new TreeNode(rootData);
queue<TreeNode *> pendingNodes;//5.pushing root to queue
pendingNodes.push(root);
while (pendingNodes.size()!=0)//5.start of lining 
{
    TreeNode *front=pendingNodes.front();//6.storing root node which is in front of queue in front node 
    pendingNodes.pop();//7.removing that rfront node from queue
    printf("Enter no of children\n");
    int numChild;//8.linking of childeen
    scanf("%d",&numChild);
    for (int i = 0; i < numChild; i++)
    {
        int childData;
        printf("Enter data of %dth child ",i);
        scanf("%d",&childData);
        TreeNode *child=new TreeNode(childData);//9.formation of child node
        front->children.push_back(child);//10.front aka root initially uske vector array me child push
        pendingNodes.push(child);//ab root child ho jayega;-->to usko queue me push-->process repeat
    }
    

}
 return root;
}
int main(){
  TreeNode *root=  takeInput();
    printTree(root);
    return 0;
}