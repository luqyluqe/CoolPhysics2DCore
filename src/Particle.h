#ifndef COOLPHYSICS2D_PARTICLE_HPP
#define COOLPHYSICS2D_PARTICLE_HPP

#include "config.h"
#include "Vector.h"
#include "Circle.h"
#include "Color.h"
#include "RawParticle.h"
#include "RetainCount.h"

#include <string>
#include <sstream>
#include <mutex>

using CoolPhysics2D::retaincount::RetainCount;
using namespace Math;

BEGIN_NAMESPACE_COOLPHYSICS2D

class Particle
{
public:
//    std::mutex _destructorMutex;
    
    Particle(bool overlappable,double radius,double mass,double elasticity,Vector position,Vector velocity,Vector acceleration,double lifeTime,Color color=Color::whiteColor);
    Particle(Particle const& particle);
    ~Particle();
    
    std::string description()const;
    
    void update(double timeInterval);
    
    void reflectAbout(const Vector& axis); //behavior when collides with the edge of the game world
    
    //Relation
    double distanceTo(const Particle& p)const;
    static bool collide(const Particle&,const Particle&);
    
    //Action
    static void handleCollision(Particle& e1,Particle& e2);
    
    //Accessor
    double lifeTime()const;
    double radius()const;
    const Vector& position()const;
    const Vector& velocity()const;
    Vector& acceleration()const;
    const Color& color()const;
    Circle range()const;
    double mass()const;
    bool overlappable()const;
private:
    raw::Particle* _particle;
    RetainCount _retainCount;
};

class ParticleBuilder
{
public:
    ParticleBuilder();
    
    ParticleBuilder& overlappable(bool overlappable);
    ParticleBuilder& radius(double radius);
    ParticleBuilder& mass(double mass);
    ParticleBuilder& elasticity(double elasticity);
    ParticleBuilder& position(const Vector& position);
    ParticleBuilder& velocity(const Vector& velocity);
    ParticleBuilder& acceleration(const Vector& acceleration);
    ParticleBuilder& lifetime(double lifetime);
    ParticleBuilder& color(const Color& color);
    
    Particle* build()const;
    
private:
    bool _overlappable;
    double _lifeTime;
    
    double _radius;
    double _mass;
    double _elasticity;
    double _friction;
    
    Vector _position;
    Vector _velocity;
    Vector _acceleration;
    
    Vector _lastPosition;
    Vector _lastVelocity;
    Vector _lastAcceleration;
    
    Color _color;
};

END_NAMESPACE_COOLPHYSICS2D

#endif
