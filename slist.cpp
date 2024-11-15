#include "slist.h"
#include <string>
using namespace std;
void LinkedList::add(string code, double l1, double l2){
    Airport * temp= new Airport(code, l1, l2);
    if (!head){
        head = temp;
    }
    else{
        Airport *temp2 = head;
        while (temp2->next!=nullptr){
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
    size++;
}
void LinkedList::clear(){
    while(head!=nullptr){
        Airport *temp = head;
        head = head->next;
        delete temp;
    }
}
bool LinkedList::equals(LinkedList l1){
    if (size!=l1.size){
        return false;
    }
    Airport *f = head;
    Airport *s = l1.head;

    while (f!=nullptr &&s !=nullptr){
        if(f->code!= s->code || f->lat!=s->lat||s->longi!=s->longi){
            return false;
        }
        f = f->next;
        s = s->next;
    }
    return true;
}

Airport* LinkedList::get(int ind){
    int count = 0;
    Airport *curr = head;
    while(curr!=nullptr){
        if (count == ind){
            return curr;
        }
        else{
            count++;
            curr = curr->next;
        }
    }
    return curr;
}



// Constructor

// Destructor

// add(value)				//Adds a new value to the end of this list.

// clear()					//Removes all elements from this list.

// equals(list)				//Returns true if the two lists contain the same elements in the same order.

//get(index)				//Returns the element at the specified index in this list.

//insert(index, value)		//Inserts the element into this list before the specified index.

//exchg(index1, index2)		//Switches the payload data of specified indexex.

//swap(index1,index2)		//Swaps node located at index1 with node at index2

// isEmpty()				//Returns true if this list contains no elements.

// remove(index)			//Removes the element at the specified index from this list.

// set(index, value)		//Replaces the element at the specified index in this list with a new value.

// size()					//Returns the number of elements in this list.

// subList(start, length)	//Returns a new list containing elements from a sub-range of this list.

// toString()				//Converts the list to a printable string representation.
