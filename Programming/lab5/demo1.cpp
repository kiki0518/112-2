#include <iostream>

using namespace std;

class LinkedList;

class ListNode {
private:
    int data;
    ListNode *next;
public:
    ListNode() : data(0), next(nullptr) {}
    ListNode(int a) : data(a), next(nullptr) {}

    friend class LinkedList;
};

class LinkedList {
public:
    LinkedList() : first(nullptr) {}
    void PrintList();
    void Push_back(int x);
    void Interleave(LinkedList& list2);

private:
    ListNode* first;
};

void LinkedList::PrintList() {
    if (first == nullptr) {
        cout << "Linked list is empty" << endl;
        return;
    }

    ListNode *current = first;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void LinkedList::Push_back(int x) {
    //todo
    ListNode* temp = new ListNode(x);
    if(first == nullptr) { 
        first = temp;
    } else {
        ListNode* end = first;
        while(end->next != nullptr) {
            end = end->next;
        }
        end->next = temp;
    }
}

void LinkedList::Interleave(LinkedList& list2) {
    //todo
    ListNode* temp1 = first;
    ListNode* temp2 = list2.first;

    ListNode* temp1_next, *temp2_next;

    if(temp1 == nullptr) {
        first = temp2;
        return;
    }
    if(temp2 == nullptr) {
        return;
    }

    while(temp1!=nullptr && temp2!=nullptr){

        temp1_next = temp1->next;
        temp1->next = temp2;

        temp2_next = temp2->next;
        if(temp1_next!=nullptr) {
            temp2->next = temp1_next;
        } else {
            return;
        }
        //cout<<"temp1: "<<temp1->data<<endl;
        //cout<<"temp2: "<<temp1->data<<endl;
        temp1 = temp1_next;
        temp2 = temp2_next;
    }
    
}

int main() {
    LinkedList list1;
    LinkedList list2;
    int count1, count2, num;

    cin >> count1;
    for (int i = 0; i < count1; i++) {
        cin >> num;
        list1.Push_back(num);
    }

    cin >> count2;
    for (int i = 0; i < count2; i++) {
        cin >> num;
        list2.Push_back(num);
    }

    list1.Interleave(list2);
    list1.PrintList();

    return 0;
}