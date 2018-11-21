/************************************************************************************** 
 ********** Author: Jed Piezas
 ********** Date: November 20 2018
 ********** Description:  Function that evaluates an expression in a postfix format
 **********               and returns the value of that operation. Contains helper methods
 **********               that determine what operations need to take place and to 
 **********               differentiate between numbers and operations
 ***************************************************************************************/

#include <cstring>
#include <stack>
#include <cctype>
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;
using std::stack;
using std::strtok;
using std::atof;

// Helper function prototypes
bool isOperation(char);
double handleOperation(double, double, char);

/************************************************************************************** 
 * Main function that takes in a c-string of an expression in postfix notation.
 * It makes use of a stack<double> to push and pop items and loops over the elements in
 * the string. When the element is a number, it will push that element into the stack.
 * If the element is an operation, it will pop two elements off the stack and run the 
 * operation with the two operands and push the result back into the stack. This 
 * loop continues until there is only one element left in the stack.
 **************************************************************************************/
double postfixEval(char str[])
{
    stack<double> postfixStack;
    char* token;
    double num;
    // Create a token from the c-string using white-space as a delimiter
    token = strtok(str, " ");
    while (token != NULL) {
        // Convert to element to a double and push it to the stack
        // if it is a digit
        if (isdigit(*token)) {
            num = atof(token); 
            postfixStack.push(num);
        }
        
        // Otherwise, grab the right-hand-side and left-hand-side, respectively,
        // and perform the mathematical operation with the two values and the token
        // push the result back in the stack.
        if (isOperation(*token)) {
            double rightHandSide = postfixStack.top();
            postfixStack.pop();
            double leftHandSide = postfixStack.top();
            postfixStack.pop();

            double result = handleOperation(leftHandSide, rightHandSide, *token);
            postfixStack.push(result);
        }
        // This increments through the token so that we don't have an infinite loop
        token = strtok(NULL, " ");
    }    
    // Once the loop is done, return the top element (there should only be one)
    return postfixStack.top();
}

/************************************************************************************** 
 *  Helper method to see if the element passed in is a valid mathematical operation
 ***************************************************************************************/
bool isOperation(char token)
{
    return token == '+' || token == '-' || token == '*' || token == '/';
}

/************************************************************************************** 
 * Takes a character and the two digits to perform a mathematical operation and return 
 * the result
 ***************************************************************************************/
double handleOperation(double lhs, double rhs, char token)
{
    switch(token) {
        case '+':
            return lhs + rhs;
            break;
        case '-':
            return lhs - rhs;
            break;
        case '*':
            return lhs * rhs;
            break;
        case '/':
            {
                if (rhs == 0) {
                    cout << "Unable to divide by 0" << endl;
                    exit(1);
                }
                return lhs / rhs;
                break;
            }
    } 
}
