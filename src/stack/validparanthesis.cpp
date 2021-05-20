#include "stack.h"
#include <string>
#include <iostream>

class ValidParan
{
    public :
    
    bool validString(std::string s)
    {
        Stack<char> sl;
        bool result = false;

        if(s.size() == 0)
            return true;
        //std::cout<<"\nValidate: "<<s<<std::endl;
        for(char c : s)
        {
            if(sl.empty())
            {
                sl.push(c);
                //std::cout<<" pushed : "<<c<<std::endl;
            }
            else
            {
                if(sl.top() == '(' and c == ')' or
                   sl.top() == '[' and c == ']' or
                   sl.top() == '{' and c == '}' )
                {
                    sl.pop();
                    //std::cout<<"  popped : "<<c<<std::endl;
                }
                else
                {
                    sl.push(c);
                    //std::cout<<" pushed : "<<c<<std::endl;
                }
            }
        }

        if(sl.empty())
            return true;
        else
            return false;
        
            

    }
    
    
};

int main()
{
    ValidParan v ;
    std::string s1("()"), s2("()[]{}"), s3("(]"), s4("([)]"),s5("{[()]}");
    std::cout <<s1 <<", result:"<<v.validString(s1)<<std::endl;
    std::cout <<s2 <<", result:"<<v.validString(s2)<<std::endl;
    std::cout <<s3 <<", result:"<<v.validString(s3)<<std::endl;
    std::cout <<s4 <<", result:"<<v.validString(s4)<<std::endl;
    std::cout <<s5 <<", result:"<<v.validString(s5)<<std::endl;
}
