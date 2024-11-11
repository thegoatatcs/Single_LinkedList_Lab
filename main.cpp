//
//  main.cpp
//  LLTemplate
//
//  Created by James Shockey on 12/6/16.
//  Copyright © 2016 James Shockey. All rights reserved.
//


/*
 *
 *	Linked List lab.
 *	- Build a library for singly linked list.
 *	- Replace the airport array in main with a Linked List.
 *  - sort the array. 
 *	
 */


#include <iostream>
#include <fstream>
#include <cmath> 
#include <cstring>
#include "slist.h"

using namespace std;

void simpleSortTotal(LinkedList &s);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);

int main()
{
    ifstream infile;
    int i=0;
    char cNum[10] ;
    LinkedList airports;		// Replace array with Linked List
    int   airportCount;
    //Airport* a[13500];
    
    infile.open ("./USAirportCodes.csv", ifstream::in);
    if (infile.is_open())
    {
        int   c=0;
        while (infile.good())
        { 
            string code;
            getline(infile, code,',');
            infile.getline(cNum, 256, ',');
            double longitude = atof(cNum);
            infile.getline(cNum, 256, '\n');
            double latitude = atof(cNum);
            airports.add(code, longitude, latitude);               
            

            
            i++ ;
            c++;
        }
        airportCount = c-1;
        infile.close();

        simpleSortTotal(airports);
        Airport* curr = airports.getHead();
        while (curr->next->next->next!=nullptr){
            
            curr = curr->next;
        }
        cout<<curr->code<<" "<<curr->lat<<" "<<curr->longi<<endl;
        
        Airport *curr2 = airports.getHead();
        double aus_long = 30.1944;
        double aus_lat = 97.6700;
        while(curr2!=nullptr){
            double dis = distanceEarth(aus_lat, aus_long, curr2->lat, curr2->longi);
            double miles = dis/1.609344;
            if (miles<=100){
                cout<<curr2->code<<" ";
            }
            curr2 = curr2->next;
        }
        


        
        


    }
    else
    {
        cout << "Error opening file";
    }
 


    
}



#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

// This function converts decimal degrees to radians
double deg2rad(double deg) {
  return (deg * pi / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
  return (rad * 180 / pi);
}


/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}


/*
	Provide sort routine on linked list
*/
void simpleSortTotal(LinkedList &s) {
    bool swapped;
    double aus_long = 30.1944;
    double aus_lat = 97.6700;
    do {
        swapped = false;
        Airport* current = s.getHead();
        Airport* previous = nullptr;
        while (current != nullptr && current->next != nullptr) {
            double c_dist = distanceEarth(aus_lat, aus_long, current->lat, current->longi);
            double n_dist = distanceEarth(aus_lat, aus_long, current->next->lat, current->next->longi);
            if (c_dist>n_dist) {
                if (previous == nullptr) {
                    s.setHead(current->next);
                } else {
                    previous->next = current->next;
                }
                
                Airport* temp = current->next->next;
                current->next->next = current;
                current->next = temp;
                
                swapped = true;
            }

            previous = current;
            current = current->next;
        }
    } while (swapped);
}

