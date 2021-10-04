#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <time.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class List
{

public:
    Node *head;
    Node *tail;
    int index;
    unordered_map<int, int> hash;

    List()
    {
        head = NULL;
        tail = NULL;
        index = 0;
    }

    void add(int val)
    {

        Node *n = new Node();
        n->data = val;
        hash.insert(make_pair(index, val));
        index++;

        if (head == NULL)
        {
            head = n;
            n->next = NULL;
            tail = n;
        }
        else
        {
            tail->next = n;
            n->next = NULL;
            tail = n;
        }
    }

    void remove(int val)
    {

        Node *ptr = head;
        Node *prev = NULL;

        while (ptr != NULL)
        {
            if (ptr->data == val)
            {
                prev->next = ptr->next;
                break;
            }
            prev = ptr;
            ptr = ptr->next;
        }

        hash.erase(val);
    }

    void print_list()
    {

        Node *ptr = head;
        while (ptr != NULL)
        {
            cout << " -> " << ptr->data;
            ptr = ptr->next;
        }

        cout << endl;
    }

    int At(int i)
    {
        return hash.at(i);
    }

    int Size(){
        return index;
    }

    void merge(List* l){
         tail->next = l->head;
    }

    bool find(int val){

        bool found = false;

        for_each(hash.begin(),hash.end(),[&val,&found](const pair<int,int> &p) {
            
            if(p.second == val)
             found = true;

        });

        return found;
        
    }
    
    void random(int n){

     srand(time(0));
     for(int i = 0; i<n ; i++){
         add(rand());
     }

    }

};
