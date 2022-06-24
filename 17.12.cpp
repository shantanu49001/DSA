/*lowest common ancestror in binary tree
                3
            6       8
          2   11      13
             9  5    7
for 2,11-->lowest common ancestor is 6
for 5,7--->3
basically write the path from root to node and note from whee path becomes different
2,11-->  3->6->2|| 3->6->11---->6 lca
5,7---> 3->6->11->5|| 3->8>13->7


           1
        2     3
      4  5     7 
        6     8 9 

now we will match the root data with the wo nodes if it mathes then return the node or else call it in the subtrees
                 r 
        st1(5,6)   st2(5,6)--->for matching the root with qny of both
        5           null   ---->5


                  r
           (st1)    (str2)
           null      null--->null


                   r
            (str1)(5,7)   (str2)(5,7)
              5             7        --->node matching returned
              answer--->root=1
*/
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;
class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
BinaryTreeNode *takeInput()
{
    int rootData;
    printf("Enter root data\n");
    scanf("%d", &rootData);
    BinaryTreeNode *root = new BinaryTreeNode(rootData);
    queue<BinaryTreeNode *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode *front = pendingNodes.front();
        pendingNodes.pop();
        int leftChildData;

        printf("Enter left child data for %d or 0 to skip\n", front->data);
        scanf("%d", &leftChildData);
        if (leftChildData != 0)
        {
            BinaryTreeNode *leftChild = new BinaryTreeNode(leftChildData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }
        int rightChildData;
        printf("Enter right child of %d or 0 to skip\n", front->data);
        scanf("%d", &rightChildData);
        if (rightChildData != 0)
        {
            BinaryTreeNode *rightChild = new BinaryTreeNode(rightChildData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }

    return root;
}
void PrintTree(BinaryTreeNode *r)
{
    if (r == NULL)
    {
        return; // for void we canuse this
    }

    printf("%d: ", r->data);
    if (r->left != NULL)
    {
        printf("L-:%d ", r->left->data);
    }
    if (r->right != NULL)
    {
        printf("R-:%d ", r->right->data);
    }
    printf("\n");
    PrintTree(r->left);
    PrintTree(r->right);
}
int LCA(BinaryTreeNode *r,int n){
    if (r==NULL)
    {
        return NULL ;
    }
    if (r->data==n)
    {
        return n;
    }
    LCA(r->left,n);
    LCA(r->right,n);
    
    
    

}
int main(){
    BinaryTreeNode *root=takeInput();
    printf("You entered\n");
    PrintTree(root);
    int num1,num2;
    printf("Enter the nodes in pair for checking the LCA\n");
    scanf("%d",&num1);
    printf("Now the second one\n");
    scanf("%d",&num2);
    int ntp1=LCA(root,num1);
    int ntp2=LCA(root,num2);
    if (ntp1==NULL&&ntp2==NULL)
    {
        printf("NULL\n");
    }
    if (ntp1!=NULL&&ntp2!=NULL)
    {
        printf("LCA is %d",root->data);
    }
    if (ntp1!=NULL&&ntp2==NULL)
    {
        printf("LCA is %d",ntp1);
    }
    if (ntp2!=NULL&&ntp1==NULL)
    {
        printf("LCA is %d",ntp2);
    }
    
    
    return 0;
}