#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* detectCycle(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    
    ListNode* slow = head;
    ListNode* fast = head;
    bool hasCycle = false;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            hasCycle = true;
            break;
        }
    }
    
    if (!hasCycle) {
        return NULL;
    }
    
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow;
}

int main() {
    // Create a linked list with a cycle
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = head->next; // Creating a cycle
    
    ListNode* cycleStart = detectCycle(head);
    if (cycleStart != NULL) {
        cout << "Cycle starts at node with value " << cycleStart->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }
    
    return 0;
}
