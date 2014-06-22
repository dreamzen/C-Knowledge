#include <iostream>
#include <vector>
using namespace std;

/**
 * Key point: delete p means the memory p pointed to is freed, but p still point there! We need to set p = NULL.
 * So, when we delete a list node, we need to find its pre-node, and set pre-node->next=NULL! We can't just delete node and set node=NULL.
 *
 */

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int v) : val(v), next(NULL) {}
};

int main()
{
	vector<int> vec;
	vec.push_back(1);
	cout << &vec[0] << endl;	// 0x0000
	ListNode *head = new ListNode(1);
	cout << head << endl;		// 0x0010
	ListNode *tail = new ListNode(2);
	cout << tail << endl;		// 0x0020
	head->next = tail;
	//delete tail
	delete tail;
	tail = NULL;
	if(head->next)				// It's TRUE!!
	{
		cout << "NOT DELETED!" << endl;
		cout << head->next->val << endl;// 2
		cout << head->next << endl;		// 0x0020
	}
	vec.push_back(3);
	cout << &vec[1] << endl;			// 0x0024
	cout << head->next << endl;			// 0x0020
	cout << head->next->val << endl;	// 1
	return 0;
}
	
