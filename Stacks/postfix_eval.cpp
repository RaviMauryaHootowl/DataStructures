int assign(char c)
{
    int val=0;
    switch(c)
    {
        case 'A':
        val=90;
        break;

        case 'B':
        val=50;
        break;

        case 'C':
        val=2;
        break;

        case 'D':
        val=3;
        break;

        case 'E':
        val=1;
        break;

        case 'F':
        val=2;
        break;

        case 'G':
        val=5;
        break;
    }
    return val;
}
int evaluatePostfix(string s)  
{  
    for (int i = 0; i<s.length(); ++i)  
    {  
        // If the char is an alphabet push it to the stack  
        if (isdigit(s[i]))  
            push((s[i]));  
  
        // If the char is an operator, pop two elements from stack apply the operator  
        else
        {  
            int x = assign(getTop()); 
            pop(); 
            int y = assign(getTop());
            pop();  

            if(s[i]=='+')
            {
               push(y + x); 
               break;   
            }
            else if(s[i]=='-')
            {
               push(y - x); 
               break;   
            }
            else if(s[i]=='*')
            {
               push(y * x); 
               break;   
            }
            else if(s[i]=='/')
            {
               push(y / x); 
               break;   
            }
            else if(s[i]=='%')
            {
               push(y % x); 
               break;   
            }
          
        }  
    }  
    return getTop();  
}  