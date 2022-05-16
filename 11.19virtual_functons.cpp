//those functions which are present in base class and oveeriden in derived
//we will discuss about pure virtual fuctons-->they don't have any definitions
//Virtual void print()=0
//abstract class=>any class conting pure virtal function
//we can't create object for abstract class
//vehicle(abstract) ko derive kara car ne to 
//kar ke pass do method hai ya to car ke saare virtual funtions to complete kare ya khud bhi abstacrct ban jaye
//agar car k abstr nhi banna to compulsaryhai usko paret ke saare virtual functins koimplement karna

class Vehicle{
    public:
    string color;

};