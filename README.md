# Magnitude  

In this project we implement a new type of integers, which represents positive and negative numbers, that uses the "size
and sign" method. this method is called **Magnitude.**  
when we use that method, the MSB of a number will be its sign (+ or -) and the rest of the bits will represent the size of the number.  
**for example, the number 5 which is represented as: 00000101 will be represented in a negative way as: 10000101, and this will be -5.**   
*for more examples, look at correct_outputs file*  
  
In order to implement that magnitude method on integers, **we define a new typedef which is called "magintude"**,
and we use some functions on that variable, such as **add, sub, multiply, equal method and compare size method**.  
  
In order to compile the code:  
  gcc main1.c ex2.c ex2.h  
In order to run the code:  
  ./a.exe  


