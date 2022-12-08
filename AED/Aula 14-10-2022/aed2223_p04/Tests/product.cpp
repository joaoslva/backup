#include "product.h"

Product::Product(string i, float p, float w): id(i), price(p), weight(w) {}

string Product::getId() const {
    return id;
}

float Product::getPrice() const {
    return price;
}

float Product::getWeight() const {
    return weight;
}
bool Product::operator < (const Product &p1) const{
    if(price == p1.getPrice()){
        return weight < p1.getWeight();
    }
    return price < p1.getPrice();
}
