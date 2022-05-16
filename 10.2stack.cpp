//dynamic array with lifo principle.
//array me acess order of 1 me hoga
//ll me oder of n se acess hota hai
//array me back and forth move kr sake hai but ll me nhi.
//insertion is easy in ll at order of 1 but array me between me oder of n pr hota hai
//practically karo qs ko.

//stack is an abstract data type we can only inseet and delete in a specific order only.
//stack of book and chairs is an example.
//insert->push
//THISE ARE THE TWO OPERATIONS REQUIRED.
//delete->pop
//top->just reads the top most data.
//isEmpty   size
//these are the 5 functions allowed.
//whenever we need restriction to acess data we use classes
//insert->pushed
//del->pop;top;size;isEmpty
//stack is ju st applying functions ovr ll or array
//array must be private in our class so that it isn't changable by every body
//inseet|del|pop|top|size|isEmpty--->all these will be public
//push->add element and update index++
//top->just read-->index-1(coz index when noding added =0)
//pop->index-1->isse wo data jo added tha wo garbage ho jayega we can add element at that place
//size->value of  index
//isEmpty->
#include<bits\stdc++.h>
class StackUsingArray{
    int *data;
    int nextIndex;     //int *data=new int [10]--->dynamic array
    int capacity;
    public:
    
    StackUsingArray(int totalSize){//total size sirf is constrructor tak rahega uske baad destro ho jayega
        data=new int[totalSize];   //
        nextIndex=0;
        capacity=totalSize;
    }
    //return the no of elements present in my stack
    int size(){
        return nextIndex;
    }
    //check for empty stack
    bool isEmpty(){
        /*
        if(nextIndex==0){
            return true;
        }
        else{
            return 0;
        }
        */
       //short form
       return nextIndex==0;//agar true hua to true nhi to false bool funcion apne aap karta hai
    }
    //inset element
    void push(int element){
    if(nextIndex==capacity){
        printf("Stack full\n");
        return;//isse nikalne k liye return use hoga not return 0

    }
    data[nextIndex]=element;//*data ->zeroth inde hai dta[]-->khud hi deref
    nextIndex++;
    }
    //elemnt dlete
    int pop(){
       if(isEmpty()){
           printf("Stack empty\n");
           return INT_MIN;//coz ye int returning function hai
       }
        nextIndex--;//wo wali wali garbage ho jayegi
        return data[nextIndex];
    }
//top most elemnt delete
int top(){
    if(isEmpty()){
        printf("Stack empty\n");
        return INT_MIN;
    }
    return data[nextIndex];
}
};
int main(){//4 size ka stck banega
    StackUsingArray s(4);//object craested for this
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    printf("%d\n",s.top());//40 print
    printf("%d\n",s.pop());//40 print 40 delete
    printf("%d\n",s.pop());//30 print 30 delelte
    printf("%d\n",s.pop());
    printf("%d\n",s.size());//3 val nikal gyi size =1
    printf("%d\n",s.isEmpty());
    return 0;
}
