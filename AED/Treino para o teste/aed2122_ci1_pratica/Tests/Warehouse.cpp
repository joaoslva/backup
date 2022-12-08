#include <climits>
#include "Warehouse.h"

Warehouse::Warehouse() {}

list<Packer> Warehouse::getPackers(){
    return packers;
}

void Warehouse::addPacker(const Packer &p) {
    packers.push_back(p);
}

list<stack<Order *>> Warehouse::getOrders() const {
    return processedOrders;
}

void Warehouse::setOrders(list<stack<Order *> > so) {
    processedOrders = so;
}


//=============================================================================
//TODO:

bool const helper(Packer &p1, Packer &p2){
    if(p1.getOrderQueue().size() == p2.getOrderQueue().size()){
        if(p1.getNamePacker() == p2.getNamePacker()){
            return p1.getIdPacker() < p2.getIdPacker();
        }
        else{
            return p1.getNamePacker() < p2.getNamePacker();
        }
    }
    return p1.getOrderQueue().size() > p2.getOrderQueue().size();
}
void Warehouse::sortPackers() {
    this->packers.sort(helper);
}

//TODO:
unsigned Warehouse::removePackers(unsigned nOrders) {
    unsigned result = 0;
    list<Packer> helper;
    for(Packer &p: this->packers){
        if(p.getOrderQueue().size() < nOrders){
            result += p.getOrderQueue().size();
        }
        else{
            helper.push_back(p);
        }
    }
    this->packers = helper;
    return result;
}

//TODO:
void Warehouse::addPacker(unsigned idPacker, string namePacker) {
    Packer p1 = Packer(idPacker, namePacker);
    for(Packer &p2: this->packers){
        if(p2.getOrderQueue().size() >= 2){
            p1.addOrder(p2.getOrderQueue().front());
            p2.removeOrder();
        }
    }
    this->packers.push_back(p1);
}

//TODO:
bool Warehouse::addToShorterQueue(Order* o) {
    Order* order_added = o;
    unsigned int omega = INT_MAX;

    if (packers.size() == 0) {
        return false;
    }

    for (auto itr = packers.begin(); itr != packers.end(); itr++) {
        if (itr->getOrderQueue().size() < omega) {
            omega = itr->getOrderQueue().size();
        }
    }
    for (auto itr = packers.begin(); itr != packers.end(); itr++) {
        if (itr->getOrderQueue().size() == omega) {
            itr->addOrder(order_added);
            break;
        }
    }
    return true;
}

//TODO:
unsigned Warehouse::processOrderByDeliveryType(string deliveryType, unsigned n) {
    unsigned processed = 0;
    for(auto itr = processedOrders.begin(); itr != processedOrders.end(); itr++){
        if(itr->top()->getDeliveryType() == deliveryType){
            while(n != 0){
                if(itr->empty()) break;
                itr->pop();
                processed++;
                n--;
            }
            if(itr->empty()){
                processedOrders.erase(itr);
            }
            break;
        }
    }


    return processed;
}
