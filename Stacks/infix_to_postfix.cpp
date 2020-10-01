string infixToPostfix(string s) 
{ 
    push('E'); // 'E' stands for end of stack
    int l = s.length(); 
    string new_s; 
    for(int i = 0; i < l; i++) 
    { 
        // If the scanned character is an operand, add it to output string. 
        if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z')) 
        new_s+=s[i]; 
  
        //  
        else if(s[i] == '(') 
        {
            push('(');
        } 
          
        // If the char is ‘)’, pop and to output string from the stack till '(' is encountered 
        else if(s[i] == ')') 
        { 
            while(getTop() != 'E' && getTop() != '(') 
            { 
                char c = getTop(); 
                pop(); 
               new_s += c; 
            } 
            if(getTop() == '(') 
            { 
                char c = getTop(); 
                pop(); 
            } 
        } 
          
        else{ 
            //&& prec(s[i]) <= prec(getTop())
            while(getTop() != 'E') 
            { 
                char c = getTop(); 
                pop(); 
                new_s += c; 
            } 
            push(s[i]); 
        }
    } 
  
    
    //Pop all the remaining elements 
    while(getTop() != 'E') 
    { 
        char c = getTop(); 
        pop(); 
        new_s += c; 
    } 
      
    return new_s;
  
} 