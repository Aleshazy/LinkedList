#include <iostream>
using namespace std;
class Node
{
    private:
        int value;
        Node* next_member = nullptr;
    public:
        Node(int value) : value(value){};
        void add_next_member(Node* ptr)
        {
            next_member = ptr;
        }
        int get_value()
        {
            return value;
        }
        Node* get_next_member()
        {
            return next_member;
        }
};

class LinkedList
{
    public:
    Node* first_elem = nullptr;
    LinkedList(Node* first_elem): first_elem(first_elem){};
        
    void insert(int position, int value)
    {
        Node* new_node = new Node(value);
        if (position == 0) 
        {
            new_node->add_next_member(first_elem);
            first_elem = new_node;
            return;
        }
        
        Node* current = first_elem;
        int index = 0;
        
        while (current != nullptr && index < position - 1)
        {
            current = current->get_next_member();
            index ++;
        }
        
        if (current != nullptr) 
        {
            new_node->add_next_member(current->get_next_member());
            current->add_next_member(new_node);
        }
    }
    void append(int d) {
        Node* n = first_elem;
        
        if (n == nullptr) {
            first_elem = new Node(d);
            return;
        }
    
        while (n->get_next_member() != nullptr) {
            n = n->get_next_member();
        }
        Node* new_node = new Node(d);
        n->add_next_member(new_node);
    }
    
        void push(){} // add elem at the beggining of the list
        void pop(){} // get the first elem of the list and than delete it
        void del(int posiotion){} // delete elem that is placed in positon
        
};

int main() {
    Node* node0 = new Node(12);
    Node* node1 = new Node(123);
    node0->add_next_member(node1);
    LinkedList llist = LinkedList(node0);
    cout << llist.first_elem->get_value() << endl;
    cout << llist.first_elem->get_next_member()->get_value() << endl;

    LinkedList llist1 = LinkedList(new Node(0));
    llist1.append(10);
    llist1.append(20); 

    Node* member = llist1.first_elem;
    while (member != nullptr) {
        cout << member->get_value() << endl;
        member = member->get_next_member();
    }
}
