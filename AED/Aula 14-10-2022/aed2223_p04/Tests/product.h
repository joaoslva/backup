#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

class Product {
    string id;
    float price;
    float weight;
public:
    bool operator < (const Product &p1) const;
    Product(string i, float p, float w);
    string getId() const;
    float getPrice() const;
    float getWeight() const;
};
#endif
