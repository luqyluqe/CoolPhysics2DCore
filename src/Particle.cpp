#include "Particle.h"

BEGIN_NAMESPACE_COOLPHYSICS2D

Particle::Particle(bool overlappable,double radius,double mass,double elasticity,Vector position,Vector velocity,Vector acceleration,double lifeTime,Color color)
{
    _particle=new raw::Particle(overlappable,radius,mass,elasticity,position,velocity,
                                 acceleration,lifeTime,color);
}

Particle::Particle(Particle const& particle):_retainCount(particle._retainCount),_particle(particle._particle){}

Particle::~Particle()
{
    _destructorMutex.lock();
    if (_retainCount.only()) {
        delete _particle;
    }
    _destructorMutex.unlock();
}

std::string Particle::description()const
{
    return _particle->description();
}

void Particle::update(double timeInterval)
{
    _particle->update(timeInterval);
}

void Particle::reflectAbout(const Vector& axis)
{
    _particle->reflectAbout(axis);
}

double Particle::distanceTo(const Particle& p)const
{
    return _particle->distanceTo(*p._particle);
}

bool Particle::collide(const Particle& p1,const Particle& p2)
{
    return raw::Particle::collide(*p1._particle, *p2._particle);
}

void Particle::handleCollision(Particle& e1,Particle& e2)
{
    raw::Particle::handleCollision(*e1._particle, *e2._particle);
}

double Particle::lifeTime()const
{
    return _particle->lifeTime();
}

double Particle::radius()const
{
    return _particle->radius();
}

const Vector& Particle::position()const
{
    return _particle->position();
}
const Vector& Particle::velocity()const
{
    return _particle->velocity();
}
Vector& Particle::acceleration()const
{
    return _particle->acceleration();
}
const Color& Particle::color()const
{
    return _particle->color();
}
Circle Particle::range()const
{
    return _particle->range();
}
double Particle::mass()const
{
    return _particle->mass();
}
bool Particle::overlappable()const
{
    return _particle->overlappable();
}

ParticleBuilder::ParticleBuilder():_overlappable(false),_radius(0),_mass(0),_elasticity(0),_position(Vector(0,0)),_velocity(Vector(0,0)),_acceleration(Vector(0,0)),_lifeTime(0),_color(Color::whiteColor){}

ParticleBuilder& ParticleBuilder::overlappable(bool overlappable)
{
    _overlappable=overlappable;
    return *this;
}
ParticleBuilder& ParticleBuilder::radius(double radius)
{
    _radius=radius;
    return *this;
}
ParticleBuilder& ParticleBuilder::mass(double mass)
{
    _mass=mass;
    return *this;
}
ParticleBuilder& ParticleBuilder::elasticity(double elasticity)
{
    _elasticity=elasticity;
    return *this;
}
ParticleBuilder& ParticleBuilder::position(const Vector& position)
{
    _position=position;
    return *this;
}
ParticleBuilder& ParticleBuilder::velocity(const Vector& velocity)
{
    _velocity=velocity;
    return *this;
}
ParticleBuilder& ParticleBuilder::acceleration(const Vector& acceleration)
{
    _acceleration=acceleration;
    return *this;
}
ParticleBuilder& ParticleBuilder::lifetime(double lifetime)
{
    _lifeTime=lifetime;
    return *this;
}
ParticleBuilder& ParticleBuilder::color(const Color& color)
{
    _color=color;
    return *this;
}

Particle* ParticleBuilder::build()const
{
    Particle* particle = new Particle(_overlappable,_radius,_mass,_elasticity,_position,_velocity,_acceleration,_lifeTime,_color);
    return particle;
}

END_NAMESPACE_COOLPHYSICS2D
