#include <vector>
#include <unordered_map>
using namespace std;

// Feel free to add new properties and methods to the class.
class MinMaxStack {
	public:
	vector<int> stack = {};
	vector<unordered_map<string,int>> vec = {};
  
	int peek() {
    // Write your code here.
		return stack[stack.size()-1];
  }

  int pop() {
    // Write your code here.
		vec.pop_back();
		int p = stack[stack.size()-1];
		stack.pop_back();
		return p;
  }

  void push(int number) {
    // Write your code here.
		unordered_map<string,int> has = {
			{"min",number},
			{"max",number}
		};
		if(vec.size()){
			unordered_map<string,int> prev = vec[vec.size()-1];
			has["min"] = min(number,prev["min"]);
			has["max"] = max(number,prev["max"]);
		}
		stack.push_back(number);
		vec.push_back(has);
  }

  int getMin() {
    // Write your code here.
		return vec[vec.size()-1]["min"];
  }

  int getMax() {
    // Write your code here.
		return vec[vec.size()-1]["max"];
  }
};