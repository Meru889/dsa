// convert infix to postfix

#include <iostream>
#include <string>
#include <stack>


bool isOperand(char c) {
	if (c >= '0' && c <= '9') return true;
	return false;
}

bool isOperator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/') return true;
	return false;
}

bool isLeftBracket(char c) {
	return '(' == c;
}

bool isRightBracket(char c) {
	return ')' == c;
}

int priority(char c) {
	switch (c) {
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default :
		return 0;
	}

}

bool hasHigherPriority(char first, char second) {
	return priority(first) > priority(second);
}

std::string infixToPostfix(std::string exp) {
	int size = exp.length();
	std::stack<char> s;
	std::string postfix;
	for (int i = 0; i < size; i++) {
		char a = exp[i];
		if (a == ' ') {
			continue;
		}
		else if (isOperand(a)) {
			postfix.push_back(a);
		}
		else if (isOperator(a)) {
			while (!s.empty() && s.top() != '(' && hasHigherPriority(s.top(), a)) {
				postfix.push_back(s.top());
				s.pop();
			}
			s.push(a);
			

		}
		else if (isLeftBracket(a)) {
			s.push(a);
		}
		else if (isRightBracket(a)) {
			while (!s.empty() && s.top() != '(') {
				postfix.push_back(s.top());
				s.pop();
			}
			s.pop();
		}
	}
	while (!s.empty()) {
		postfix.push_back(s.top());
		s.pop();
	}
	return postfix;
}

void testConverFix() {
	std::cout << "Enter a formula: " << std::endl;
	std::string exp;
	std::getline(std::cin, exp);
	std::string p = infixToPostfix(exp);
	std::cout << "postFix is : " << p << std::endl;
}

