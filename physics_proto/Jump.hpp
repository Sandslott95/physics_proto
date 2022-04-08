#pragma once

#include "Vector.hpp"
#include "Helper.h"

struct tets{
float mass = 50.0f;
Vector3 jumpSpeed = Vector3(0.0f, 5.0f, 0.0f);
Vector3 gravityAcceleration = Vector3(0.0f, -9.82f, 0.0f);
Vector3 acceleration;
Vector3 velocity;
Vector3 position;
Vector3 resultingForce;
Vector3 force_g;

void Jump(){
    velocity += jumpSpeed;
}
void SetPos(Vector3 pos){
    position = pos;
}
void Move(Vector3 step){
    position += step;
}
void Update(float deltaT){
    //Update forces
    force_g = gravityAcceleration*mass;

    //Set resulting force
    resultingForce = force_g;

    //Update acceleration
    acceleration = resultingForce / mass;

    //Update velocity
    velocity = velocity + acceleration * deltaT;

    //Update position
    position = position + velocity * deltaT;

}

Vector3 GetPos(){
    return position;
}
};

