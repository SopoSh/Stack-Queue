#pragma once
/*-- Staque.h --------------------------------------------------------------

  This header file defines a staque data type.
  Basic operations:
    constructor:  Constructs an empty staque
    copy constructor, destructor
    enstaque:     modifies a staque by adding a value at the back
    destaque:     remove value at first
    empty:        Checks if a staque is empty
    push:         Modifies a staque by adding a value at the top
    top:          Accesses the top staque value; leaves staque unchanged
    pop:          Modifies staque by removing the value at the top
    display:      Displays all the staque elements
--------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

#ifndef STAQUE
#define STAQUE

typedef int StaqueElement;


class Staque
{

private:
    /*** Node class ***/
    //class inside a class
    class Node
    {
    public:
        //in public because it is already encapsulated in private part of class staque
        StaqueElement data;
        int ts;
        Node* prec;
        Node* next;

        //--- Node constructor
        Node(StaqueElement value, int num = 0, Node* link2 = 0, Node* link1 = 0) //null, no garbage 
            /*-------------------------------------------------------------------
              Precondition:  None.
              Postcondition: A Node has been constructed with value in its data
                  part and its next part set to link (default 0).
             -------------------------------------------------------------------*/
            :data(value), ts(num), next(link2), prec(link1)
        {}
    }; //end of node class

    typedef Node* NodePointer;

    /***** Data Members *****/
    NodePointer front, back;      // pointer to top and back of staque
    int counter;




public:
    //verbs, operations on data
/***** Function Members *****/
/***** Constructors *****/
    Staque();
    /*-----------------------------------------------------------------------
      construct a Staque object.
     Precondition:  None.
     Postcondition: An empty staque object has been constructed
         (front and back pointers are initialized to a null pointer, counter is zero).
         null link indicates that it does not refer to any node
   ------------------------------------------------------------------------*/

    Staque(const Staque& original);
    /*Copy constructor
      Preconditions: original is the staque to be copied.
      Postcondition: no return type, traverses the list and allocates a new node corresponding
      to each node in the original list and links
    */

    /***** Destructor *****/
    ~Staque();
    /*------------------------------------------------------------------------
      Class destructor

      Precondition:  None
      Postcondition: The linked list in the staque has been deallocated in memory pool
    ------------------------------------------------------------------------*/

    /***** Assignment *****/
    const Staque& operator= (const Staque& rightHandSide);
    /*------------------------------------------------------------------------
      Assignment Operator
      Precondition:  rightHandSide is the staque to be assigned and is
          received as a const reference parameter.
      Postcondition: The current stack becomes a copy of rightHandSide
          and a const reference to it is returned.
    ------------------------------------------------------------------------*/

    bool empty() const;
    /*------------------------------------------------------------------------
      bool Check if Staque is empty.
      Precondition: None
      Postcondition: Returns true if Staque is empty and false otherwise.
     -----------------------------------------------------------------------*/

    void push(const StaqueElement& value);
    /*------------------------------------------------------------------------
      Add a value to a Staque.

      Precondition:  value is to be added to this Staque
      Postcondition: value is added at top of Staque provided there is space;
           otherwise, a stack-full message is displayed and execution is
           terminated.
     -----------------------------------------------------------------------*/
    void enstaque(const StaqueElement& value);
    /* add a value to a staque

       Precondition: value is added to this staque
       Postcondition: it is added at back
    */

    void display(ostream& out) const;
    /*------------------------------------------------------------------------
      Display values stored in the Staque.

      Precondition:  ostream out is open.
      Postcondition: Staque's contents, from top down, have been output to out.
     -----------------------------------------------------------------------*/

    StaqueElement top() const;
    /*------------------------------------------------------------------------
      Retrieve value at top of Staque (if any).

      Precondition:  Staque is nonempty
      Postcondition: Value at top of Staque is returned, unless the Staque is
          empty; in that case, an error message is displayed and a "garbage
          value" is returned.
     -----------------------------------------------------------------------*/

    void pop();
    /*------------------------------------------------------------------------
      Remove value at top of staque (if any).

      Precondition:  Staque is nonempty.
      Postcondition: Value at top of Staque has been removed, unless the Staque
          is empty; in that case, an error message is displayed and
          execution allowed to proceed.
     -----------------------------------------------------------------------*/
    void destaque();
    /*------------------------------------------------------------------------
      Remove value at back of staque (if any).

      Precondition:  Staque is nonempty.
      Postcondition: Value at back of Staque has been removed, unless the Staque
          is empty; in that case, an error message is displayed and
          execution allowed to proceed.
     -
     */

    int frontTs() const;
    int backTs() const;


}; // end of class declaration

#endif
