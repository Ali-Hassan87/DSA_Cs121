
#include<iostream>
using namespace std;

template<typename T>
class set {

    struct node {
        node *left, *right, *parent;
        T val;

        node() {
            left = right = parent = nullptr;
        }
    };

    node* head;
    int n;

public:

    // Constructor
    set(){
        head = new node;

        head->left = head->right = head->parent = head;
        n = 0;
    }

    // Empty function
    bool empty(){
        return n == 0;
    }

    // Size function
    int size(){
        return n;
    }

    // Insert function
    void insert(const T& v){

        node* temp = new node;
        temp->val = v;

        // If tree is empty
        if(head->parent == head){
            head->left = head->right = head->parent = temp;
            temp->left = temp->right = temp->parent = head;
            n++;
            return;
        }

        node* ptr = head->parent;
        while(true) {

            if(v < ptr->val){
                if(ptr->left == head) {
                    ptr->left = temp;
                    temp->parent = ptr;
                    temp->left = temp->right = head;
                    n++;
                    return;
                }

                ptr = ptr->left;
            }

            else if(v > ptr->val) {
                if(ptr->right == head) {
                    ptr->right = temp;
                    temp->parent = ptr;
                    temp->left = temp->right = head;
                    n++;
                    return;
                }

                ptr = ptr->right;
            }

            else {
                delete temp;
                return;
            }
        }
    }
};

int main() {

    set<int> s;

    s.insert(5);
    s.insert(3);
    s.insert(2);
    s.insert(4);
    s.insert(7);
    s.insert(9);

    cout << "Size: " << s.size() << endl;
    cout << "Empty: " << s.empty() << endl;

}

