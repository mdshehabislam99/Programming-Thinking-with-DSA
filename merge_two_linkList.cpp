#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* mergeTwoSortedLinkedList(Node* head1, Node* head2)
{
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;
    
    Node* mergedHead = NULL;
    
    if(head1->data < head2->data)
    {
        mergedHead = head1;
        mergedHead->next = mergeTwoSortedLinkedList(head1->next, head2);
    }
    else
    {
        mergedHead = head2;
        mergedHead->next = mergeTwoSortedLinkedList(head1, head2->next);
    }
    
    return mergedHead;
}

int main()
{
    Node* head1 = new Node{1, new Node{3, new Node{5, NULL}}};
    Node* head2 = new Node{2, new Node{4, new Node{6, NULL}}};
    Node* mergedHead = mergeTwoSortedLinkedList(head1, head2);

    Node* current = mergedHead;
    while(current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    
   
    
    return 0;
}
