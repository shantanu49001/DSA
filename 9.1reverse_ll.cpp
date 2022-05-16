/**
 * @file 9.1reverse_ll.cpp@author your name (you@domain.com)
 * 1121
 * HEAD EK BAAR O MOVE KAREGE FIR AGLI BAAR LAST TAK MOVE
 * NEXT WO FIR SE 2ND TAK JAYEGA THEN SECOND LAST TAK
 * THIS WAY IT WILL MOVE HERE WE NEED TO TAKE BOOL
 *
 *
 */
// checking palindrome
#include <bits\stdc++.h>
//DOUBT IN THIS Q ;
//DOUBT IN THIS Q ;
//DOUBT IN THIS Q ;
//DOUBT IN THIS Q ;
//DOUBT IN THIS Q ;
class Node
{
public:
    int data;
    int index;
    Node *next;
    Node(int data, int index)
    {
        this->data = data;
        this->index = index;
        this->next = NULL;
    }
};

int main()
{
    int data;
    int index = 0;
    printf("Enter data for first node\n");
    scanf("%d", &data);
    Node *n1 = new Node(data, index);
    Node *temp = n1; // used
    Node *head = n1;

    Node *print = n1; // used
    index++;
    while (data != 0)
    {
        printf("Do u want to enter new node?enter data or press 0\n");
        scanf("%d", &data);
        if (data != 0)
        {
            Node *n = new Node(data, index);
            temp->next = n;
            temp = temp->next;
            index++;
        }
    }
    printf("You entered\n");
    int length=0;
    while (print != NULL)
    {
        printf("%d", print->data);
        print = print->next;
        length++;
    }
    printf("\n");
    bool plaindrome=true;
    for(int i=0;i<length;i++){

    }

    return 0;
}