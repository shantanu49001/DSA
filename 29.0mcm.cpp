//we are given n matrixes we need to return minimum no of 
/*
operations to multily them
2*3  [3*4  4*5]
or
(2*3  3*4)  4*5

general-> a0*a1   a1*a2-->no of operation->  a0*a1*a2


(2*3   3*4)   4*5
2*3*4->operaton needed here .....(i)

2*4     4*5-> 2*4*5.............(ii)
------------------------------------------
(i)+(ii)=>answer
------------------------------------------

a0*a1 a1*a2 a2*a3 a3*a4 .....an-1*an-->dimensions of matrices

but i need the data of arra of size n+1

a0 a1 a2 a3   .......an-->to calculate the answer
(and this is the input we get)

m1  m2    m3 .........-> these are the matrices


final levep answer

(m1....mk)      (mk+1...........mn)--->
a0a1...ak-1ak    ak+1,ak+2       an-1an
option1-> (m1)(m2......mn)
option2-> (m1.m2)(m3....mn)
.
.
.
.
.
option last->(m1.m2.m3.m4.....mn-1)(mn)
and i need to select the best one possible

recurson formula->13:30
                ->15:41









*/

