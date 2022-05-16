//we will learn const object creation
//Fraction const f3;-->dafault constructor clled jo ki f3 me garnage vaues daal deta hai
//f3 ke through hum koi bhi function call nhi kar sakte.
//constant object se saath sirf constanat functions to hi call kr sakte hai
//ye wo functions hai jo huare object ki koi bhi value ko na change krni ki gauraneee dete hai
//int getNumerator() const{

//}
/**
 * void setNum(int n){---->isme const likne pr bhi kaam nhi chalega
 * n=numerator
 * }
 * object ki properties agar ksi me kahin bhi change ho rhi hai to wo nhi kr sakte
 */

//STAIC MEMBERS-:
/**
 * THAT DATA MEMBERS THAT HAVE SAME VALUE FOR ALL OBJECTS
 * 
 */
class Student{
    public:
    int rollNumber;//pobjec property
    int age;//object property
 static int totalStudents;//----->ye to sabke liye same hai
    //ab ye class ki proprty hai ye object ko nhi milti
    //by default properires are non satic
    //to acess it cout<<Student::totalStudent
    //rest by object
};
//initialse bahar jaake krte hai
int Student::totalStudents=0;
//cout s1.totalStudents---->0
//s1.totalStudents=20
//cout s2.totalStudents------>20   copy to banti nhi class ka hi tata change hota hai
//cout Student::totalStudents--->20


