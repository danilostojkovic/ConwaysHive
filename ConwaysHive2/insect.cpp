#include "insect.h"

Insect::Insect(int index):cellIndex(index) { age=0; };
bool Insect::operator==(const Insect& i) const {
    return cellIndex==i.cellIndex && age==i.age;
}
int Insect::getIndex() const {
    return cellIndex;
}
