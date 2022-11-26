// practice stack , check for balance parentheses

#include <string>
#include <iostream>
#include <stack>

bool isPair(char begin, char end) {
	if (begin == '(' && end == ')') return true;
	if (begin == '{' && end == '}') return true;
	if (begin == '[' && end == ']') return true;
	return false;
}

bool isBalance(std::string exp) {
	std::stack<char> s;
	for (char c : exp)
	{
		if (c == '{' || c == '[' || c == '(') {
			s.push(c);
		}
		else if (c == '}' || c == ']' || c == ')') {
			if (s.empty() || !isPair(s.top(), c)) {
				return false;
			}
			s.pop();
		}
	}
	return s.empty();
}

void checkBalance() {
	std::string str = "{taksefsdfadgf[fsdfggsdffsdefdffsdfe(sdfsdfsdfsdfff(fsdfsefsdfhhhjbnnm))]}";
	std::cout << isBalance(str) << std::endl;
}


