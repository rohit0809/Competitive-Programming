#include <bits/stdc++.h>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
	sort(array.begin(),array.end());
	int siz = array.size();
	int l = 0;
	int r = siz-1;
	
	vector<int> ans;
	
	while(l<r){
		if(array[l] + array[r] == targetSum){
			ans.push_back(array[l]);
			ans.push_back(array[r]);
			return ans;
		}
		
		if(array[l]+array[r] < targetSum)
			l++;
		else if(array[l]+array[r] > targetSum)
			r--;
	}
}
