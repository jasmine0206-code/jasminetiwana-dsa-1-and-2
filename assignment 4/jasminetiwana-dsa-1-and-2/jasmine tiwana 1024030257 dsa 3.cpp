//ASSIGNMENT 3
//Q1 
#include <iostream>
using namespace std;

#define MAX 5   // maximum size of stack

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    // (i) push
    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << x << endl;
        } else {
            arr[++top] = x;
            cout << x << " pushed into stack." << endl;
        }
    }

    // (ii) pop
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to pop." << endl;
        } else {
            cout << arr[top--] << " popped from stack." << endl;
        }
    }

    // (iii) isEmpty
    bool isEmpty() {
        return (top == -1);
    }

    // (iv) isFull
    bool isFull() {
        return (top == MAX - 1);
    }

    // (v) display
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Stack elements are: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    // (vi) peek
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Top element is: " << arr[top] << endl;
        }
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n*** Stack Menu ***\n";
        cout << "1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            if (s.isEmpty())
                cout << "Stack is Empty.\n";
            else
                cout << "Stack is not Empty.\n";
            break;
        case 4:
            if (s.isFull())
                cout << "Stack is Full.\n";
            else
                cout << "Stack is not Full.\n";
            break;
        case 5:
            s.display();
            break;
        case 6:
            s.peek();
            break;
        case 7:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
//Q2#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() { return (top == -1); }
    bool isFull() { return (top == MAX - 1); }

    void push(char ch) {
        if (!isFull()) {
            arr[++top] = ch;
        }
    }

    char pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        return '\0'; // if empty, return null char
    }
};

int main() {
    char str[MAX];
    cout << "Enter a string: ";
    cin.getline(str, MAX);

    Stack s;

    
    for (int i = 0; str[i] != '\0'; i++) {
        s.push(str[i]);
    }

    cout << "Reversed string: ";
    
    while (!s.isEmpty()) {
        cout << s.pop();
    }
    cout << endl;

    return 0;
}
//Q3
#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() { return (top == -1); }
    bool isFull() { return (top == MAX - 1); }

    void push(char ch) {
        if (!isFull()) {
            arr[++top] = ch;
        }
    }

    char pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        return '\0';
    }

    char peek() {
        if (!isEmpty()) {
            return arr[top];
        }
        return '\0';
    }
};


bool isBalanced(char expr[]) {
    Stack s;

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty()) return false; // no matching opening

            char top = s.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

   
    return s.isEmpty();
}

int main() {
    char expr[MAX];
    cout << "Enter expression: ";
    cin.getline(expr, MAX);

    if (isBalanced(expr))
        cout << "Balanced expression " << endl;
    else
        cout << "Not balanced " << endl;

    return 0;
}
//Q4
#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() { return (top == -1); }
    bool isFull() { return (top == MAX - 1); }

    void push(char ch) {
        if (!isFull()) arr[++top] = ch;
    }

    char pop() {
        if (!isEmpty()) return arr[top--];
        return '\0';
    }

    char peek() {
        if (!isEmpty()) return arr[top];
        return '\0';
    }
};

// Function to define precedence
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Function to check if character is operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Infix to Postfix Conversion
void infixToPostfix(char infix[], char postfix[]) {
    Stack s;
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        // If operand, add to postfix
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            postfix[j++] = ch;
        }
        // If '(', push to stack
        else if (ch == '(') {
            s.push(ch);
        }
        // If ')', pop until '('
        else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix[j++] = s.pop();
            }
            s.pop(); // remove '('
        }
        // If operator
        else if (isOperator(ch)) {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch)) {
                postfix[j++] = s.pop();
            }
            s.push(ch);
        }
    }

    // Pop remaining operators
    while (!s.isEmpty()) {
        postfix[j++] = s.pop();
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    cout << "Enter Infix Expression: ";
    cin.getline(infix, MAX);

    infixToPostfix(infix, postfix);

    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}
Q5//
#include <iostream>
#include <cstring>
#include <cmath>  
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() { return (top == -1); }
    bool isFull() { return (top == MAX - 1); }

    void push(int x) {
        if (!isFull()) arr[++top] = x;
    }

    int pop() {
        if (!isEmpty()) return arr[top--];
        return -1; 
    }
};


int evaluatePostfix(char postfix[]) {
    Stack s;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        
        if (ch >= '0' && ch <= '9') {
            s.push(ch - '0'); 
        }
        
        else {
            int val2 = s.pop();
            int val1 = s.pop();

            switch (ch) {
            case '+': s.push(val1 + val2); break;
            case '-': s.push(val1 - val2); break;
            case '*': s.push(val1 * val2); break;
            case '/': s.push(val1 / val2); break;
            case '^': s.push(pow(val1, val2)); break;
            }
        }
    }
    return s.pop(); 
}

int main() {
    char postfix[MAX];

    cout << "Enter Postfix Expression (operands as single digits): ";
    cin.getline(postfix, MAX);

    int result = evaluatePostfix(postfix);

    cout << "Result = " << result << endl;

    return 0;
}