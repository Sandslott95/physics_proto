#include <corecrt_math.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include "Vector.hpp"

int main()
{
    
    float mass = 2.f;
    const double a = -9.81; 
    int t = 0;
  
   
    Vector2 acc;
    Vector2 force = {100, 100};
    Vector2 v0 = {1200, 150};
    Vector2 gravity;
    gravity.y = -9.81f;
    gravity.x = 1.f;

    Vector2 grav = Vector2(0.0f, -9.82f);
    Vector2 v = v0;//Vector2(0.0f, 0.0f);
    Vector2 force_grav = grav*mass;

    Vector2 startPos;
    Vector2 pos;

    std::string content;

    std::ofstream csv_file("whatever.csv");
    csv_file << "time," <<  "X," <<  " Y" <<  "\n";
    
    while (t < 10) {    
        
        // Förlag 1: 
        //pos = startPos + (v0*t) + (gravity * powf(t, t)/2.f); 
        //pos = startPos + (v0*t) + (gravity ); 
        
        //Beräkna accelleration
        //acc = ((gravity)/mass);

        //Beräkna hastigheten
        //v0 = acc * t;
        //v0 = v0 + acc * t;

        //Beräkna pos
        //pos = pos + v0 * t;

        // Förlag 2: 
        Vector2 temp = force_grav;
        acc = (temp)/mass;

        v = v+acc*t;

        pos = pos + v*t;

         std::cout <<  "X:" << pos.x << " Y:" << pos.y << "\n";

        csv_file << t << "," <<  pos.x << "," << pos.y << "\n";
        t++;
    }                    
       
    csv_file.close();
    return 0;
}