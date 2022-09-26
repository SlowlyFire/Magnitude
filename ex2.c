//Gal Giladi

#include <stdio.h>
#include "ex2.h"
#define MIN_SIZE -2147483648

/*function: add
 * input: magnitude a, magnitude b
 * output: the result of adding both of magnitudes (a+b)
 * */
magnitude add(magnitude a, magnitude b)
{
    magnitude addResult=0;

    //a is positive, b is negative
    if(a>=0 && b<=0)
    {
        //turning off MSB, now b is positive
        b=b&0x7fffffff;
        if(a>=b)
        {
            addResult=a-b;
            addResult=addResult&0x7fffffff;
        }
        
        else if(a<b)
        {
            addResult=b-a;
            addResult=addResult|0x80000000;
        }

        return addResult;
    }
    
    //b is positive, a is negative
    else if(a<=0 && b>=0)
    {
        //turning off MSB, now a is positive
        a=a&0x7fffffff;
        if(a>b)
        {
            addResult=a-b;
            addResult=addResult|0x80000000;
        }
        
        else if(a<b)
        {
            addResult=b-a;
            addResult=addResult&0x7fffffff;
        }
        
        else if(a==b)
        {
            addResult=a-b;
            addResult=addResult&0x7fffffff;
        }
        
        return addResult;
    }
   
    //both are negative
    else if(a<=0 && b<=0)
    {
        //turning off MSB, now a,b are positive
        a=a&0x7fffffff;
        b=b&0x7fffffff;
        addResult=a+b;
        addResult=addResult|0x80000000;
        //MIN_SIZE is -0 which is 0
        if(addResult==MIN_SIZE)
        {
            return 0;
        }
        return addResult;
    }
    
    //both are positive
    else if(a>=0 && b>=0)
    {
       addResult=a+b;
       addResult=addResult&0x7fffffff;
       return addResult;
    }
}

/*function: sub
 * input: magnitude a, magnitude b
 * output: the result of substracting b from a (a-b)
 */
magnitude sub(magnitude a, magnitude b)
{
    magnitude subResult=0;

    //a is positive, b is negative
    if(a>=0 && b<=0)
    {
        //turning off MSB,b is positive
        b=b&0x7fffffff;
        subResult=a+b;
        subResult=subResult&0x7fffffff;
        return subResult;
    }
    
    //b is positive, a is negative
    else if(a<=0 && b>=0)
    {
        //turning off MSB, now a is positive
        a=a&0x7fffffff;
        subResult=a+b;
        subResult=subResult|0x80000000;
        //MIN_SIZE is -0 which is 0
        if(subResult==MIN_SIZE)
        {
            return 0;
        }
        return subResult;
    }
   
    //both are negative
    else if(a<=0 && b<=0)
    {
        //turning off MSB, now a,b are positive
       a=a&0x7fffffff;
       b=b&0x7fffffff;
       if(a>b)
       {
           subResult=a-b;
           subResult=subResult|0x80000000;
       }
       
       else if(a<b)
       {
           subResult=b-a;
           subResult=subResult&0x7fffffff;
       }
       
       else if(a==b)
       {
         subResult=a-b;
         subResult=subResult&0x7fffffff;  
       }
       
       return subResult;
    }
    
    //both are positive
    else if(a>=0 && b>=0)
    {
       if(a>b)
       {
           subResult=a-b;
           subResult=subResult&0x7fffffff;
       }
       
       else if(a<b)
       {
           subResult=b-a;
           subResult=subResult|0x80000000;
       }
       
       else if(a==b)
       {
         subResult=a-b;
         subResult=subResult&0x7fffffff;  
       }
       
       return subResult;
    }
}

/*function: multi
 * input: magnitude a, magnitude b
 * output: the result of multipling a and b (a*b)
 */
magnitude multi(magnitude a, magnitude b)
{
    magnitude multiResult=0;

    //a is positive, b is negative
    if(a>=0 && b<=0)
    {
        //turning off MSB, now b is positive
        b=b&0x7fffffff;
        multiResult=a*b;
        multiResult=multiResult|0x80000000;
        if(multiResult==MIN_SIZE)
        {
            return 0;
        }
        return multiResult;
    }
    
    //b is positive, a is negative
    else if(a<=0 && b>=0)
    {
        //turning off MSB, now a is positive
        a=a&0x7fffffff;
        multiResult=a*b;
        multiResult=multiResult|0x80000000;
        if(multiResult==MIN_SIZE)
        {
            return 0;
        }
        return multiResult;
    }
    
    //both are positive
    else if(a>=0 && b>=0)
    {
        multiResult=a*b;
        multiResult=multiResult&0x7fffffff;
        return multiResult;
    }
    
    //both are negative
    else if(a<=0 && b<=0)
    {
        //turning off MSB, now a,b are positive
        a=a&0x7fffffff;
        b=b&0x7fffffff;
        multiResult=a*b;
        multiResult=multiResult&0x7fffffff;
        return multiResult;
    }
}

/*function: equal
 * input: magnitude a, magnitude b
 * output: comparing a to b. if a=b return 1 (true), else 0 (false)
 */
int equal(magnitude a, magnitude b)
{
    if(a<0 || b<0 )
    {
        //turning off MSB, now a,b are positive
        a=a&0x7fffffff;
        b=b&0x7fffffff;
    }
    if(a==b)
    {
        return 1; //true
    }
    else
    {
        return 0; //false
    }
}

/*function: greater
 * input: magnitude a, magnitude b
 * output: comparing a to b. if a>b return 1 (true), else 0 (false)
 */
int greater(magnitude a, magnitude b)
{
    //if both negative
    if(a<=0 && b<=0)
    {
        //turning off MSB, now a,b are positive
        a=a&0x7fffffff;
        b=b&0x7fffffff;
        //absolute value in negatives
        if(a>=b)
        {
            return 0; //false
        }
        
        else if(a<b)
        {
            return 1; //true
        }
    }
    
    //a is negative, b positive
    else if(a<=0 && b>=0)
    {
        return 0;
    }
    
    //b is negative, a positive
    else if(a>0 && b<0)
    {
        return 1;
    }
    
    //both positive
    else
    {
    return a>b;
    }
}
