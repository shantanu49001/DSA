//pop top push teeno me cap aur index me check lagana padega
//dynamic me new array ka size double ho jata hai
#include<bits\stdc++.h>
//changes to form a dynamic one.
class StackUsingArray{
int *data;//these all will be private 
int nextIndex;//ll ke node k content vaise hi
int capaciy;
public:
//StackUsingArray(int totalSize){
StackUsingArray(){
    data=new int[4];//array-->we decieded 
    nextIndex=0;
   // capaciy=totalSize;
    capaciy=4;//we decided
}
int size(){
    return nextIndex;

}
bool isEmpty(){
    return nextIndex==0;
}
void push(int element){
    if(nextIndex==capaciy){
     //   printf("Stack Full\n");
       // return;
//doubling the array
     int *newData=new int[2*capaciy];
     for (int i = 0; i < capaciy; i++)
     {
        newData[i]=data[i];
     }
            capaciy*=2;
            delete [] data;
            data=newData;//data ab nayi array ko point karega
    }
    data[nextIndex+1]=element;
    nextIndex++;
}
int pop(){
    if(isEmpty()){
        printf("Stack Empty\n");
        return INT_MIN;
    }
   
    printf("%d ",data[nextIndex]);
    nextIndex--;
}
int top(){
    if(isEmpty()){
        printf("Stack Empty\n");
        return INT_MIN;

    }
    return data[nextIndex];
}
//size,isempty,push,pop,top //--->these are the functions.
};
int main(){
    StackUsingArray s;//default constructor call hai kuch bhi karme ki zarroorat nhi
    
    int data;
    printf("Enter oth index data\n");

    scanf("%d",&data);
    int i=0;
    while (data!=0)
    {
        s.push(data);
        printf("Enter data or press 0 to exit\n");
        scanf("%d",&data);
        i++;
    }
    printf("YOU entered\n");
    while (i!=0)
    {
      s.pop();//public chaeeze object se hi call hogi.
        i--;
    }
    
    
    
  //automTE HERE.
    
    return 0;
}