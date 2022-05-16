//every node says pehle mere child ko
/*
                         1
              2          3         4
           5    6      7   8 
                            9  

5 6 2 7 9 8 3 4 1 
left priko>right 

generic->the first way we printed.
*/
#include <bits\stdc++.h>
#include <vector>
#include <queue>
using namespace std;
class TreeNode
{
public:
    int data;
    vector<TreeNode *> children;
    TreeNode(int data)
    {
        this->data = data;
    }
};
TreeNode *takeInput()
{
    int rootData;
    printf("Enter data for root\n");
    scanf("%d", &rootData);
    TreeNode *root = new TreeNode(rootData);
    queue<TreeNode *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        printf("Enter number of child nodes for node with data %d", front->data);
        scanf("%d", &numChild);
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            printf("Enter data for %dth child node of parent node with data %d: \n", i, front->data);
            scanf("%d", &childData);
            TreeNode *child = new TreeNode(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}
//best example of recursions .
void postOrder(TreeNode *root){
 //1.pehle root milegu
 //2.uske child ko print krna hai
 //3.then root ko print krna hai
 if (root==NULL)
 {
     printf("%d",root->data);
 }
 
 for (int  i = 0; i < root->children.size(); i++)
 {
     postOrder(root->children[i]);
 }
 printf("%d",root->data);
 
}
int main(){
    TreeNode *root=takeInput();
    postOrder(root);
    return 0;
}

/*single and simplest case leke flow banao----------------->dsa one anuj bhaiya 56 .me concept to code recursion hai 
     1                                                      this is the best way
    2 3 
1.root milegi 2.agar wo null hai to seedha print
3.warna root se uske child m jana hai 
4.fir root ko print krna hai 
5.ab child bhi recursive hau to usme recursion----->child ko wapas recursion ka banna hai 
6.root recursion nhi hai to usko print
7.now by coding this simle "single case"
 we have doe whole recursive call*/