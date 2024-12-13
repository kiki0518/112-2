#include <iostream>

using namespace std;

class ListNode {
public:
    int data;
    ListNode *next;
    ListNode(int x) : data(x), next(NULL) {}
};

class LinkedList {
private:
    ListNode* head;

public:
    LinkedList() : head(NULL) {}

    void push_back(int data) {
        //TODO
        ListNode* temp = new ListNode(data);
        if(head == NULL) { 
        head = temp;
        } else {
            ListNode* end = head;
            while(end->next != nullptr) {
                end = end->next;
            }
            end->next = temp;
        }
    }

    bool isPalindrome() {
        //TODO
        ListNode* lst2 = reverse(head);
        while(lst2!=NULL && head!=NULL) {
            //cout<<"lst2->data: "<<lst2->data<<endl;
            //cout<<"head->data: "<<head->data<<endl;
            if(lst2->data != head->data) {
                // cout<<"ret: false";
                return false;
            }
            lst2 = lst2->next;
            head = head->next;
        }
        return true;
    }

    ListNode* reverse(ListNode* node) {
        //TODO
        if(node == NULL) {
            return NULL;
        }

        ListNode* rev = NULL, *rev_head;
        ListNode* temp = node;
        while(temp != NULL) {
            ListNode* t = new ListNode(temp->data);
            if(rev == NULL) {
                rev = t;
                rev_head = rev;
                rev->next = NULL;
            } else {
                rev->next = t;
                rev = rev->next;
                rev->next = NULL;
            }
            temp = temp->next;
        }
        // cout<<"copy successfully!"<<endl;
        ListNode *temp_next, *prev;
        temp = rev_head;

        prev = temp;
        temp = temp->next;

        while(temp != NULL) {
            temp_next = temp->next;
            temp->next = prev;
            
            prev = temp;
            temp = temp_next;
        } 
        // cout<<"reverse successfully!"<<endl;
        return prev;
    }


    ~LinkedList() {
        ListNode *current = head;
        while (current != NULL) {
            ListNode *next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    LinkedList lst;
    int length, num;

    cin >> length;

    for (int i = 0; i < length; i++) {
        cin >> num;
        lst.push_back(num);
    }

    bool result = lst.isPalindrome();
    cout << (result ? "Yes" : "No") << endl;

    return 0;
}