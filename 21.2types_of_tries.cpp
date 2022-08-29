//tries over hashmap->space opimasation
//                  ->fast searching
//                  ->dynamic searching me har word ke suggestion ko match nhi krna padega
/*
1.compressed tries->space optimisation
types of tries me 3:40  4:40
clubbing the node where path is single no branching other than 1 


at time of insertion we need to decide whether we can club it or not
ex->if singliy staringht b->e->ar
  ->if we are inserting bean then we need to break the ar


     ->deletin 7:50


tie starts with null char as root elememt



pattern matching me end of word ko check nhi krna hai jutst match the all patterns remove is terminal prorpety
word searching me is terminal ko consider karenge



13:00
pattern matching me prefixes of whole whole match 
word searching me word ke suffixes match
|
|
|
|
to solve this
2.Suffix tries->specially fo patternmatching but less space effiecient
               ->also when beech ke elements search krne hote hai
bend insert krte time bend insert krte time b nd end i.e word ke saare sufixes bhi insert krna hai*/