#include "packagingMachine.h"
#include <sstream>

PackagingMachine::PackagingMachine(int boxCap): boxCapacity(boxCap)
{}

unsigned PackagingMachine::numberOfBoxes() {
	return boxes.size();
}

unsigned PackagingMachine::addBox(Box& b1) {
	boxes.push(b1);
	return boxes.size();
}

HeapObj PackagingMachine::getObjects() const {
	return this->objects;
}

HeapBox PackagingMachine::getBoxes() const {
	return this->boxes;
}

// ---------------------------------------------

// TODO
unsigned PackagingMachine::loadObjects(vector<Object> &objs) {
    unsigned count = 0;
    vector<Object> help;
    for(Object o: objs){
        if(o.getWeight() <= boxCapacity) {
            objects.push(o);
            count++;
        }
        else help.push_back(o);
    }
    objs = help;
    return count;
}


// TODO
Box PackagingMachine::searchBox(Object& obj) {
    HeapBox help = getBoxes();
    Box helper;
    while(!help.empty()){
        helper = help.top();
        if(helper.getFree() >= obj.getWeight()) return helper;
        help.pop();
    }
    return Box(0);
}


// TODO
unsigned PackagingMachine::packObjects() {
	return 0;
}

// TODO
stack<Object> PackagingMachine::boxWithMoreObjects() const {
    stack<Object> res;
	return res;
}



