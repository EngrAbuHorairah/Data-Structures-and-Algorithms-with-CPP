#include <iostream> // standard input/output stream library
#include <stack> // stack container adapter library
#include <math.h> // math library for pow() function
using namespace std; 

int calculate(string postfix)
{
    stack<int> st; // stack object to store integers
    string str = postfix; // string object to hold the postfix expression
    int result = 0; // variable to store the result of the calculation
    int size = str.length(); // variable to hold the length of the postfix expression

    for (int i = 0; i < size; i++) // loop through each character in the postfix expression
    {
        if (str[i] >= '0' && str[i] <= '9') // if the character is a digit
        {
            st.push(str[i] - '0'); // convert the character to an integer and push it onto the stack
        }
        else // if the character is an operator
        {
            int op1 = st.top(); // get the first operand from the top of the stack
            st.pop(); // remove the first operand from the stack
            int op2 = st.top(); // get the second operand from the top of the stack
            st.pop(); // remove the second operand from the stack

            switch (str[i]) // switch statement to perform the appropriate arithmetic operation
            {
                case '+':
                    st.push(op1 + op2); // add the two operands and push the result onto the stack
                    break;
                case '-':
                    st.push(op2 - op1); // subtract the first operand from the second operand and push the result onto the stack
                    break;
                case '*':
                    st.push(op2 * op1); // multiply the two operands and push the result onto the stack
                    break;
                case '/':
                    st.push(op2 / op1); // divide the second operand by the first operand and push the result onto the stack
                    break;
                case '^':
                    st.push(pow(op2, op1)); // raise the second operand to the power of the first operand and push the result onto the stack
                    break;
            }
        }
    }

    result = st.top(); // get the final result from the top of the stack
    st.pop(); // remove the final result from the stack
    return result; // return the final result
}

int main()
{
    string postfix = "24*"; // postfix expression to be calculated
    int value = calculate(postfix); // call the calculate function to get the result
    cout << "Value = " << value; // print the result to the console
    return 0; // return 0 to indicate successful execution
}