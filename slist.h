#ifndef SLIST_H
#define SLIST_H
#include <string>
using namespace std;
/*

Class Library File

*/
class Airport{
    public:
        string code;
        double longi;
        double lat;
        Airport * next;
        Airport(string c, double l1, double l2){
            code = c;
            longi = l1;
            lat = l2;
            next = nullptr;
        }
};
class LinkedList{
    private:
        Airport *head;
        int size = 0;
    public:
        LinkedList(){
            head = nullptr;
        }
        void add(string code, double longi, double lat);
        void clear();
        bool equals(LinkedList l);
        Airport* getHead(){
            return head;
        }
        void setHead(Airport *h){
            head = h;
        }
        Airport * get(int i);
};

#endif
