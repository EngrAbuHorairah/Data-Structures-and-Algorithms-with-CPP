#include<iostream>
using namespace std;
#include<stack> // include stack library for using stack data structure

// function to return the precedence of an operator
int prec(char op)
{
	if(op == '^'){
		return 3;
	}
	else if(op=='*' || op == '/')
	{
		return 2;
	}
	else if(op == '+' || op == '-')
	{
		return 1;
	}
	else{
		return 0;
	}
}

// function to convert infix expression to postfix expression
string convert(string infix)
{
	stack<int>st; // create a stack of type int
	int i = 0;
	string postfix = ""; // create an empty string for storing the postfix expression
	
	while(infix[i]!='\0'){ // loop through each character in the infix expression
		if(infix[i]>= 'a' && infix[i]<='z' || infix[i]>= 'A' && infix[i]<= 'Z') // if the character is an operand, add it to the postfix expression
		{
			postfix += infix[i];
			i++;
		}
		else // if the character is an operator
		{
			if(infix[i]== '(') // if it's an opening bracket, push it onto the stack
			{
				st.push(infix[i]);
				i++;
			}
			else // if it's a closing bracket or an operator
			{
				if(infix[i]== ')') // if it's a closing bracket
				{
					// pop operators from the stack and add them to the postfix expression until an opening bracket is encountered
					while(st.top() != '(')
					{
						postfix+=st.top();
						st.pop();
					}
					st.pop(); // pop the opening bracket from the stack
					i++;
				}
				else // if it's an operator
				{
					// pop operators from the stack and add them to the postfix expression until an operator with lower precedence is encountered
					while(!st.empty() && prec(infix[i])<=prec(st.top()))
					{
						postfix+=st.top();
                        st.pop();
					}
					st.push(infix[i]); // push the current operator onto the stack
					i++;
				}
			}
		}
	}
	
	while(!st.empty()) // add any remaining operators from the stack to the postfix expression
	{
		postfix+=st.top();
		st.pop();
	}
	
	return postfix; // return the postfix expression
}

int main()
{
	string infix = "a+b";
	string postfix = convert(infix); // call the convert function to convert the infix expression to postfix expression
	cout<<"Postfix = "<<postfix; // print the postfix expression
	return 0;
}