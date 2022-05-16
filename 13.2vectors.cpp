//substitute of dynamic array
//iska size nhi batana padta 
//apne aap naye lements add kr leta hai
//vector is a template by default
#include<bits\stdc++.h>//isse vector include ho jata hai
#include<vector>
using namespace std;

int main(){
 //   vector<int> *vp=new vector<int>();//dyanimic allocation-->khud se delete krna padta hai

vector<int> v;
v.push_back(10);//sabse last me add
v.push_back(20);
v.push_back(40);//size 3 ho gya ab tak
printf("%d",v[0]);//isko array ki tarah treat kr sakte hai
//push back size check krta rehta hai aur apne aap size badha dega agar required hua to

v[1]=0;//allowed
//isse ho sakta hai vector ke bahar hum add kr de
v[3]=10;//push back sirf 40 ke baad tak ka size tha
v.pop_back();
//v.[]-->aise insert karne pr wo inko ignore kr dega pehle push back wale add karega aur fir last me ye wale garbage me store kr dga
//ye 40 ke baad add hoga
//10 33 ke baad add ho jayeg
//v[]-->ye sirf get,update k loye use karemge
v.at(2);//element at position 2 return
//v.krke saare functions study kar lena
//v.at(9)-->out of range ho jayega-->safer to use
//v[]-->ye jo mn hota hai wo dega bhele hi ho ya nhi
for (int i = 0; i < v.size(); i++)
{
    printf("%d",v.at(i));
}
//v.pop_back-->last wala remove ho jayega
//v.capacity-->cureent array ka size->har baar pushback,popback krne par badal  jayega
return 0;
//inshort ye v.push/v.pop krn pr hi size badalta hai
}