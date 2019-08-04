#include <bits/stdc++.h>
using namespace std;

class LinkedList {
  public:
    int value;
    LinkedList* next;

    LinkedList(int value);
    void addMany(vector<int> values);
    vector<int> getNodesInArray();
};

void solve(LinkedList **head, int &val, int k){
	if(*head==NULL)
		return;
		
	solve(&(*head)->next,val,k);
	val++;
	
	if(val==k){
		LinkedList *node = (*head)->next->next;
		LinkedList *temp = (*head)->next;
		if(node==NULL){
			(*head)->next=NULL;
			free(temp);
		}
		else{
			(*head)->next=node;
			free(temp);
		}
	}
	
}

void removeKthNodeFromEnd(LinkedList* head, int k) {
  // Write your code here.
	int val = -1;
	solve(&head,val,k);
	val++;
	if(val==k){
		head->value=head->next->value;
		head->next=head->next->next;
	}
}
