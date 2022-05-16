#include <bits\stdc++.h>
using namespace std;
#include <stack>
#include <queue>
// jo pehle aa rhe hai unke children pehle call karlo
// perfect use of queue
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;
    TreeNode(T data)
    {
        this->data = data;
    }
};
TreeNode<int> *takeInputLevelWise() // node returning function with no agruments
{
    int rootData;
    printf("Enter root data\n");
    scanf("%d", &rootData);
    TreeNode<int> *root = new TreeNode<int>(rootData); // root created.
    // now we have to create the queue->jisme root jaiyega
    // root bahar ayea poochne k liye mere child kitne hai
    // un child to 1 se connect karke queue me dalna bhi bai
    queue<TreeNode<int> *> pendingNodes; // quue ke pass child nodes pointer hai hai
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        printf("Enter no of nodes for %d \n", front->data);
        int numChild;
        scanf("%d", &numChild);
        for (int i = 0; i < numChild; i++)
        {
            int childdata;
            printf("Enter %dth child data of %d \n", i, front->data);
            scanf("%d", &childdata);
            // now we must create the nodes dynamically so that we can use this anytime
            TreeNode<int> *child = new TreeNode<int>(childdata);
            front->children.push_back(child); // vector me add
            pendingNodes.push(child);         // queue me add
            // while me wapas gye.
        }
    }
    return root;
}
void printTree(TreeNode<int> *root)
{                              // now try to modify this as done in takeinput.
    printf("%d:", root->data); // parent print
    for (int i = 0; i < root->children.size(); i++)
    {
        printf("%d,", root->children[i]->data);
        // dono child printed
    }
    printf("\n");
    // ab ye dono child bhi is tarah parent banke explore
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]); // recursion
    }
}
int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printTree(root);
    return 0;
}