#include <bits/stdc++.h>
using namespace std;

// create node
class Node
{
public:
    int data;
    Node *next;

    // comparator
public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    // no argument
public:
    Node()
    {
        data = 0;
        next = NULL;
    }
    // without address
public:
    Node(int data1)
    {
        data = data1;
        next = NULL;
    }
};
// create lnked list
// time complexity is O(n)
Node *create_linked_list(vector<int> &v)
{
    int n = v.size();
    if (n == 0)
    {
        return NULL;
    }
    Node *head = new Node(v[0]);
    Node *start = head;
    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(v[i]);
        start->next = temp;
        start = temp;
    }
    return head;
}
// traversal of linked list
// time complexity is o(n)
// space complexity is O(1)
void linked_list_traversal(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << (temp->data) << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
// find length of the linked list
// time complexity is O(n)
int length_linked_list(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
// finding element
// time complexity is O(n)
// space complexity is O(1)
Node *finding_element(Node *head, int target)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == target)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
// brute force apporach
// time complexity is O(2*n)
// space complexity is O(n)

Node *odd_even_brute(Node *head)
{
    Node *temp = head;
    if (head == NULL)
    {
        return NULL;
    }
    vector<int> v;
    while (temp)
    {
        v.push_back(temp->data);
        if (temp->next != NULL)
        {
            temp = temp->next->next;
        }
        else
        {
            break;
        }
    }
    temp = head->next;
    while (temp)
    {
        v.push_back(temp->data);
        if (temp->next != NULL)
        {
            temp = temp->next->next;
        }
        else
        {
            break;
        }
    }
    int i = 0;
    temp = head;
    while (temp)
    {
        temp->data = v[i];
        i++;
        temp = temp->next;
    }
    return head;
}

// optimal apporach and complex implimentation 
// time complexity is O(n)
// spac ecomplexity is o(1)

Node *odd_even_optimal(Node *head)
{
    Node *temp1 = head;
    if (head == NULL)
    {
        return head;
    }
    Node *temp2 = head->next;
    Node *start = temp2;
    Node *end = head;
    while (temp1 != NULL || temp2 != NULL)
    {
        if (temp1 != NULL)
        {
            if (temp1->next != NULL)
            {
                temp1->next = temp1->next->next;
            }
            end = temp1;
            temp1 = temp1->next;
        }
        if (temp2 != NULL)
        {
            if (temp2->next != NULL)
            {
                temp2->next = temp2->next->next;
            }
            temp2 = temp2->next;
        }
    }
    end->next = start;
    return head;
}

// optimal apporach good implimentation
// time complexity is o(n)
// space complexity is O(1)

Node*odd_even_optimal2(Node*head){
    Node*odd=head;
    if(head==NULL){
        return head;
    }
    Node*even=head->next;
    Node*start=even;
    while(even!=NULL && even->next!=NULL){
        odd->next=odd->next->next;
        even->next=even->next->next;

        odd=odd->next;
        even=even->next;
    }
    odd->next=start;
    return head;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    Node *head = create_linked_list(v);
    linked_list_traversal(head);

    head = odd_even_brute(head);
    linked_list_traversal(head);

    head=odd_even_optimal(head);
    linked_list_traversal(head);


    head=odd_even_optimal2(head);
    linked_list_traversal(head);
}