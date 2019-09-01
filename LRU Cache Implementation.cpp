#include <bits/stdc++.h>
#define ll long long int 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define debug 0

using namespace std;

class LRUCache{
	list<int> dq;
	unordered_map<int,list<int>::iterator> has;
	
	int capacity;
	
	public:
		LRUCache(int);
		void refer(int);
		void display();
};

LRUCache::LRUCache(int c){
	capacity=c;
}

void LRUCache::refer(int x){
	if(has.find(x)==has.end()){
		if(dq.size()==capacity){
			int last = dq.back();
			dq.pop_back();
			has.erase(last);
		}
	}
	else{
		dq.erase(has[x]);
	}
	
	dq.push_front(x);
	has[x]=dq.begin();
}

void LRUCache::display(){
	list<int>::iterator it;
	
	for(it=dq.begin();it!=dq.end();++it){
		cout<<*it<<" ";
	}
	
	cout<<"\n";
}


int main() {
	
    int n,i,k;
	
	LRUCache lru(4); 
  
    lru.refer(1); 
    lru.refer(2); 
    lru.refer(3); 
    lru.refer(1); 
    lru.refer(4); 
    lru.refer(5); 
    lru.display();
	
	return 0;
}