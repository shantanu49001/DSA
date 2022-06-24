#include<bits\stdc++.h>
#include<map>
#include<string>
#include<vector>
using namespace std;
//if we used unordered then it wil not be in order any random orer me print hoga
int main(){
    map<string, int> OurMap;
    OurMap["abc"]=1;
    OurMap["cde"]=2;//key can't be same.
    OurMap["efg"]=3;
    OurMap["ghi"]=4;
    OurMap["ijk"]=5;
    OurMap["klm"]=6;
    OurMap["mno"]=7;
    map<string, int>::iterator it=OurMap.begin();//this return s the iterator
    while (it!=OurMap.end())
    {
        cout<<"Key:"<<it->first<<"\t"<<"Value:"<<it->second<<endl;
        it++;
    }
    vector<int> v;//isme order me hoga walyas
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    vector<int>::iterator iter=v.begin();
    while (iter!= v.end())
    {
        cout<<*iter<<" "<<endl;
        iter++;
        
    }
    //ourMap.find retuns an ietrator
    map<string,int>::iterator iter_two=OurMap.find("abc");
    //erase in range
    OurMap.erase(iter_two, iter_two + 4);//abc se four age tak erase
    //to earse whole map use end begin
    return 0;
}