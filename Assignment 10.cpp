#include <bits/stdc++.h>
using namespace std;

template <class T>
class Node {
private:
	T data;
	Node* next;
public:
	Node(T x) {
		data = x;
		next = NULL;
	}
	template <class U> friend class Stack;
};

template <class T>
class Stack {
private:
	Node<T> * head;
public:
	Stack() {
		head = NULL;
	}
	bool isEmpty() {
		return head == NULL;
	}
	void Push(T x) {
		Node<T> * newNode = new Node<T>(x);
		if (head == NULL) {
			head = newNode;
			return;
		}
		newNode->next = head;
		head = newNode;
	}
	void Pop() {
		if (isEmpty())
			return;
		Node<T> * temp = head;
		head = head->next;
		delete temp;
	}
	int Top() {
		if (!isEmpty())
			return head->data;
		else {
			cout << "Empty List\n";
			return -1;
		}
	}
};

class Expression {
private:
	string exp;
	bool isOperand(char c) {
		return ((c >= '0' && c <= '9') ||
		        (c >= 'A' && c <= 'Z') ||
		        (c >= 'a' && c <= 'z'));
	}

	bool isOperator(char c) {
		return (c == '+' || c == '-' || c == '*' || c == '/');
	}

	int evaluate(int op1, int op2, char oprtr) {
		if (oprtr == '+') return (op1 + op2);
		else if (oprtr == '-') return (op1 - op2);
		else if (oprtr == '*') return (op1 * op2);
		else if (oprtr == '/') return (op1 / op2);
		else return -1;
	}

	int getPriority(char oprtr) {
		if (oprtr == '+' || oprtr == '-')
			return 1;
		else if (oprtr == '*' || oprtr == '/')
			return 2;
		else
			return -1;
	}

	bool isHigherPrece(char oprtr1, char oprtr2) {
		int pri1 = getPriority(oprtr1);
		int pri2 = getPriority(oprtr2);
		return pri1 >= pri2;
	}
public:
	Expression(string str = "") {
		this->exp = str;
	}

	string getExpression() {
		return exp;
	}

	void setExpression() {
		getline(cin, exp);
		while (exp.length() == 0 )
			getline(cin, exp);
	}

	int evaluatePostfix() {
		Stack<int> stk;
		for (int i = 0; i < exp.length(); i++) {
			if (isOperand(exp[i])) {
				int operand = 0;
				while (exp[i] != ' ') {
					operand = (operand * 10) + (exp[i] - '0');
					i++;
				}
				stk.Push(operand);
			}
			else if (isOperator(exp[i])) {
				int op2 = stk.Top(); stk.Pop();
				int op1 = stk.Top(); stk.Pop();
				stk.Push(evaluate(op1, op2, exp[i]));
			}
		}
		return stk.Top();
	}

	string infixToPostfix() {
		string postfix = "";
		stack<char> stk;
		for (int i = 0; i < exp.length(); i++) {
			if (isOperand(exp[i])) {
				while (i < exp.size() && exp[i] != ' ') {
					postfix += exp[i];
					i++;
				}
				postfix += ' ';
			}
			else if (isOperator(exp[i])) {
				while (!stk.empty() && stk.top() != '(' && isHigherPrece(stk.top(), exp[i])) {
					postfix += stk.top();
					postfix += ' ';
					stk.pop();
				}
				stk.push(exp[i]);
			}
			else if (exp[i] == '(')
				stk.push('(');
			else if (exp[i] == ')') {
				while (!stk.empty() && stk.top() != '(') {
					postfix += stk.top();
					postfix += ' ';
					stk.pop();
				}
				stk.pop();
			}
		}

		while (!stk.empty()) {
			postfix += stk.top();
			postfix += ' ';
			stk.pop();
		}

		return postfix;
	}
};

int main() {
	Expression exp;
	while (true) {
		int option;
		cout << "Choose What do you want??\n";
		cout << "\t1 for infix to postfix conversion\n";
		cout << "\t2 for postfix evaluation\n";
		cout << "\t0 to exit\n:";
		cin >> option;

		if (option == 0)
			break;
		else if (option == 1) {
			cout << "Enter Infix Expression: ";
			exp.setExpression();
			cout << "Postfix form: " << exp.infixToPostfix() << endl;
		}
		else if (option == 2) {
			cout << "Enter Postfix Expression: ";
			exp.setExpression();
			cout << "Value of Postfix expression is: " << exp.evaluatePostfix() << endl;
		}
		else
			cout << "Invalid Value. Enter again.\n";
	}
	return 0;
}