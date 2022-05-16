#include<iostream>
using namespace std;
int increment(int &n){//this var has ref to same i previously formed
    n++;//i value bhi change r dega
    cout<<n<<endl;

}
//we can also make a function that can return a refence as well
int &f(int n){//refer var returning function
    //*f(int n)
    return n;
}
int main(){
int i=10;
increment(i);
cout<<i<<endl;
int &b=f(i);//this function assigns ref to b of i
//but we must alokeep in mind about the scope of ref it will be used only till function is executing
//same applies with the pointer returning function
}