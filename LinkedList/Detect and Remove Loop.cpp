#include <vector>
using namespace std;

class LinkedList {
  public:
    int value;
    LinkedList* next;

    LinkedList(int value);
    void addMany(vector<int> values);
    LinkedList* getNthNode(int n);
};

LinkedList* findLoop(LinkedList* head) {
  // Write your code here.
	LinkedList *slow = head;
	LinkedList *fast = head;
	
	while(fast != NULL && fast->next != NULL){
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)
			break;
	}
	
	if(slow==head)
		return slow;  // slow->next = NULL to remove loop
	
	slow=head;
	while(slow->next != fast->next){
		slow=slow->next;
		fast=fast->next;
	}
	// slow->next = NULL to remove loop
	return slow->next;
}
