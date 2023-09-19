#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

int main() {
    // Create a linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    
    // Traverse the linked list
    ListNode* current = head;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    
    // Insert a node
    ListNode* newNode = new ListNode(4);
    newNode->next = head->next;
    head->next = newNode;
    
    // Delete a node
    head->next = head->next->next;
    
    return 0;
}
