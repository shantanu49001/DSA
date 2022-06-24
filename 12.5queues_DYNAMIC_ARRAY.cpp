//by array we will implemnt first
//try to code on ur own
#include<bits\stdc++.h>
//difference is only with the linking part
//top aka first
//cpmpletly made by me.
//WE MADE A DYNAMIC QUEUE DIRECTLY
//REMOVE START ME ENTER AST SE
class Queue{
int *data;//data members
int length;
int index;
int frontIndex;
public:
Queue(){//class to define all data members
    data=new int[4];
    length=4;
    index=0;
    frontIndex=0;
}
bool IsEmpty(){
    return frontIndex>index;
}
int front(){//top
    if(!IsEmpty())
    printf("First elemnt is %d\n",data[frontIndex]);
    else
    printf("Nothing there\n");
}
void Enqueue(int element){//push
    if (length-1==index)
    {
        int *newArray=new int[2*length];
        for (int i = 0; i < index; i++)
        {
          newArray[i]=data[i];
        }
        length*=2;
        delete []data;
        data=newArray;

    }

    index++;
    data[index]=element;
    printf("Entered%d\n",element);

}
int size(){
    return index+1;
}
int Deqeue(){//pop
    if(!IsEmpty()){
    int val=data[frontIndex];
    printf("Removed%d\n",val);
    frontIndex++;
    }
    else{
        printf("Already empty\n");
        return 0;
    }
}
};
//INITIALLY MAKE FIRST INDEX=-1.
int main(){
    Queue q;
    q.Enqueue(2);//WE CAN AUTOMATE THIS PROCESS
    q.Enqueue(4);
    q.Enqueue(6);
    q.Enqueue(7);
    q.Enqueue(8);
    q.Enqueue(9);
    q.front();
    q.Deqeue();
    q.front();
    q.Deqeue();
    q.Deqeue();
    q.Deqeue();
    q.front();
    q.Deqeue();
    q.Deqeue();
    q.front();
    q.Deqeue();

    q.front();
    printf("size is %d",q.size());
}