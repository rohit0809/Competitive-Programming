#include <bits/stdc++.h>
using namespace std;

bool balancedBrackets(string str) {
  // Write your code here.
	int c1=0,c2=0,c3=0;
	stack<char> stk;
	for(int i=0;i<str.length();i++){
		if(str[i]=='(')
			stk.push(str[i]);
		else if(str[i]=='[')
			stk.push(str[i]);
		else if(str[i]=='{')
			stk.push(str[i]);
		else if(str[i]==')' && stk.size() > 0 && stk.top() == '(')
			stk.pop();
		else if(str[i]==']' && stk.size() > 0 && stk.top() == '[')
			stk.pop();
		else if(str[i]=='}' && stk.size() > 0 && stk.top() == '{')
			stk.pop();
		else
			return false;
	}
	
	return stk.empty();
}
