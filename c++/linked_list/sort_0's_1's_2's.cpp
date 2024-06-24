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
// time complexity is O(3*n)
// space complexity is O(n)
Node *sort_brute(Node *head)
{
    Node *temp = head;
    vector<int> v;
    while (temp)
    {
        v.push_back(temp->data);
        temp = temp->next;
    }
    int low = 0;
    int mid = 0;
    int high = v.size() - 1;
    while (mid <= high)
    {
        if (v[mid] == 0)
        {
            swap(v[low], v[mid]);
            low++;
            mid++;
        }
        else
        {
            if (v[mid] == 1)
            {
                mid++;
            }
            else
            {
                if (v[mid] == 2)
                {
                    swap(v[high], v[mid]);
                    high--;
                }
            }
        }
    }
    temp = head;
    int i = 0;
    while (temp)
    {
        temp->data = v[i];
        temp = temp->next;
        i++;
    }
    return head;
}

// beeter apporach
// time complexity is O(2*n)
// space complexity is O(1)

Node *sort_better(Node *head)
{
    Node *temp = head;
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    while (temp)
    {
        if (temp->data == 0)
        {
            cnt0++;
        }
        if (temp->data == 1)
        {
            cnt1++;
        }
        if (temp->data == 2)
        {
            cnt2++;
        }
        temp = temp->next;
    }
    temp = head;
    while (temp)
    {
        if (cnt0)
        {
            temp->data = 0;
            cnt0--;
        }
        else
        {
            if (cnt1)
            {
                temp->data = 1;
                cnt1--;
            }
            else
            {
                if (cnt2)
                {
                    temp->data = 2;
                    cnt2--;
                }
            }
        }
        temp = temp->next;
    }
    return head;
}

// optimal apporach
// time complexity is O()
// space complexity is O()

Node *sort_optimal(Node *head)
{
    Node *temp = head;
    Node *temp0 = new Node(-1);
    Node *start0 = temp0;
    Node *temp1 = new Node(-1);
    Node *start1 = temp1;
    Node *temp2 = new Node(-1);
    Node *start2 = temp2;
    while (temp)
    {
        if (temp->data == 0)
        {
            temp0->next = temp;
            temp0 = temp;
        }
        if (temp->data == 1)
        {
            temp1->next = temp;
            temp1 = temp;
        }
        if (temp->data == 2)
        {
            temp2->next = temp;
            temp2 = temp;
        }
        temp = temp->next;
    }

    temp0->next = start1->next;
    if (start1->next == NULL)
    {
        temp0->next = start2->next;
    }
    else
    {
        temp1->next = start2->next;
    }
    temp2->next = NULL;
    return start0->next;
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

    head=sort_brute(head);
    linked_list_traversal(head);

    head=sort_better(head);
    linked_list_traversal(head);


    head=sort_optimal(head);
    linked_list_traversal(head);
}