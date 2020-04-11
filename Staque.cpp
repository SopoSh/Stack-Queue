//--- Staque.cpp -------------------------------------------------
// implements Staque member functions


#include <iostream>
using namespace std;

#include "Staque.h"




//--- Definition of Staque default constructor
Staque::Staque()
    : front(0), back(0), counter(0)
{}

//--- Definition of Staque copy constructor
Staque::Staque(const Staque& original)
{
    front = back = 0;
    counter = 0;
    if (!original.empty())
    {
        // Copy first node
        front = back = new Staque::Node(original.top());

        // Set pointer to run through original's linked lists
        Staque::NodePointer origPtr = original.front->next;

        while (origPtr != 0)
        {
            back->next = new Staque::Node(origPtr->data, counter++, 0, back);
            back = back->next;
            origPtr = origPtr->next;
        }
    }
}

//--- Definition of Stack destructor
Staque::~Staque()
{
    // Set pointers to run through the stack
    Staque::NodePointer prev = front,  // node to be deallocated
        ptr;          // its successor
    while (prev != 0)
    {
        ptr = prev->next;
        delete prev;
        prev = ptr;
    }
}

//--- Definition of assignment operator
const Staque& Staque::operator=(const Staque& rightHandSide)
{
    if (this != &rightHandSide)         // check that not staque = staque
    {
        this->~Staque();                  // destroy current linked list
        if (rightHandSide.empty())       // empty stack
        {
            front = back = 0;
            counter = 0;
        }
        else
        {                                // copy rightHandSide's list
           // Copy first node
            front = back = new Staque::Node(rightHandSide.top());

            // Set pointers to run through the stacks' linked lists
            Staque::NodePointer rhsPtr = rightHandSide.front->next;

            while (rhsPtr != 0)
            {
                back->next = new Staque::Node(rhsPtr->data, counter++, 0, back);
                back = back->next;
                rhsPtr = rhsPtr->next;
            }
        }
    }
    return *this; //has a return value, differing from copy onstructor
}

//--- Definition of empty()
bool Staque::empty() const
{
    return (front == 0);
}

//--- Definition of push()
void Staque::push(const StaqueElement& value)
{
    front = new Staque::Node(value, counter++, front, 0);
}

//definition of enstauqe
void Staque::enstaque(const StaqueElement& value) {
    Staque::NodePointer newptr = new Staque::Node(value, counter++, 0, back);
    if (empty())
        front = back = newptr;
    else {
        back->next = newptr;
        back = newptr;
    }
}


//--- Definition of display()
void Staque::display(ostream& out) const
{
    Staque::NodePointer ptr;
    for (ptr = front; ptr != 0; ptr = ptr->next)
        out << ptr->data << " " << endl;
}


//--- Definition of pop()
void Staque::pop()
{
    if (!empty())
    {
        Staque::NodePointer ptr = front;
        front = front->next;
        delete ptr;
    }
    else
        cerr << "*** Stack is empty -- can't remove a value ***\n";
}

//definition of destaque
void Staque::destaque() {
    if (!empty())
    {
        Staque::NodePointer ptr = back;
        back = back->prec;
        back->next = 0;
        delete ptr;
    }
    else
        cerr << "*** Stack is empty -- can't remove a value ***\n";
}

//--- Definition of top()
StaqueElement Staque::top() const
{
    if (!empty())
        return (front->data);
    else
    {
        cerr << "*** Staque is empty "
            " -- returning garbage ***\n";
        StaqueElement* temp = new(StaqueElement);
        StaqueElement garbage = *temp;     // "Garbage" value
        delete temp;
        return garbage;
    }
}

int Staque::frontTs() const {
    return front->ts;
}
int Staque::backTs() const {
    return back->ts;
}