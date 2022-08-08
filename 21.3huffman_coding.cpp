//when we want to compress a file i.e a text or any file
//this is done by hoffman coding ->this is a popuplar algo rtihm
/*compression
F=abaaad->  6bytes->48bits
1.frequently occuring characters ka space reduce->
reducing space re for foccuring cgar let say for a=3


b,d=12
12+12+12=36<<<48->hige effect 

we figure out the cunt of each occuring characters

then we pick up the most least occuring 2 caracters
 add those counts pf both and remove them from the lost


 now while addong the two consider it as one unit and sect next min occr and repaet it 6:22


 when whenever a new char is added to list add it to the list and repaet the same
 7:00


 7:45->struncture see

 now at that striutre assign left pathn as 0 and right as 1

now start is from last node
 now we want to to store abe let's say
last se a tak move karo and uska code select kar lo 10:30

f=aafqaea->insert krte time hr element ko uske code se replace krdo


Decompression->we now have a bit not the file
00110001010
0->check code->mil gya to 0 nahi to 00
0->check mil gya to next sirf 1 else 01 or 001
|
|
|
now repatet this




Implenetaion--.
maiantain the count 
list me se 2 min select ->min pq can help->insert the list to min pq
                        ->do min bahar nikale club krke insert 
                        ->repeat till null

                        ->now eement and count structure is like a binary tree
                        ->har ode me char count lef tchild path right child path hoga
                        ->now to get a code search the element by movinf from left to right from the root and if we move feft 0 then right me 1
                        ->and save that to a hashmap->10 se multiply krte kete add krte jao
                        






*/