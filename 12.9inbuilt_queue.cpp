#include<bits\stdc++.h>
using namespace std;//necessary for quue
#include<queue>
int main(){
    queue <int> q;
    printf("What operation u want to do\n");
    printf("1.Size of queue\n");
    printf("2.Front data\n");
    printf("3.enqueue\n");
    printf("4.dequeue\n");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        // int s=q.getSize();
        printf("Size is%d\n", q.size());
        break;

    case 2:
     while (!q.empty())
     {
         printf("%d->",q.front());
         q.pop();//q. likh ke baaki functions ke name aa jate hai
     }
     
        break;

    case 3:
        int data;
        printf("Enter data for node\n");
        scanf("%d", &data);
        q.push(data);
      //  q.enqueue(data);
        break;

    case 4:
     //   q.dequeue();
        q.pop();
        break;

    default:
        printf("Can't do\n");
        break;
    }
    int ch;
    printf("repeat? (1->yes) or (0-No )\n");
    scanf("%d", &ch);
    if (ch == 1)
    {
        main();
    }
    else if (ch == 0)
    {
        printf("Thanks for using\n");
        printf("Have a nice day\n");
    }

    return 0;
}