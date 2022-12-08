#include "box.h"
#include <sstream>

Object::Object(unsigned i, unsigned w): id(i), weight(w)
{}

unsigned Object::getID() const {
	return id;
}

unsigned Object::getWeight() const {
	return weight;
}

Box::Box( unsigned cap): capacity(cap), free(cap)
{}

unsigned Box::getCapacity() const {
	return capacity;
}

unsigned Box::getFree() const {
	return free;
}

void Box::addObject(Object& obj) {
	free -= obj.getWeight();
	objects.push(obj);
}

StackObj Box::getObjects() const {
    return objects;
}

unsigned Box::getSize() const {
	return objects.size();
}


// ---------------------------------------------

//TODO
bool Object::operator<(const Object& o1) const {
    if(weight == o1.getWeight()) return id < o1.getID();
    return weight < o1.weight;
}

//TODO
bool Box::operator<(const Box& b1) const {
	if(free == b1.getFree()) return objects.size() < b1.getObjects().size();
    return free < b1.getFree();
}




