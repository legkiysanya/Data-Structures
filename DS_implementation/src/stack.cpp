#include <iostream> 
using namespace std;

struct node {
   int num;
   node *next = NULL;
   node(int _num) : num(_num), next(nullptr) {};
};

class list {
private:
   node *head;
public:
    list() { // конструктор 
      head = nullptr;
      cout << "head initialized by null pointer" << "\n";
   }

   ~list() {
      while (head) pop();
      cout << "list is destructed now" << std::endl;
   }
   
   void push(int n);
   void pop();
   bool empty() { return head == nullptr; }
   node *top() {
      if (!head) return nullptr;
      return head;
   } 
   void makenull() { while (head) pop(); }
};


void list::pop() {
   node* tmp;

   tmp = head->next;
   delete head;
   head = tmp;
}

void list::push(int n) {
    node *tmp = new node(n);
    tmp->num  = n;

    tmp->next = head;
    head = tmp;
}

int main() {
   list stack;
   std::cout << stack.top()<< "\n";
   stack.push(98123);
   stack.push(7);
   stack.makenull();
   std::cout << stack.top()<< "\n";
   stack.push(0);
   //std::cout << stack.top()<< "\n";
   
}

