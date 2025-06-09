#include <iostream>
#include "setHashed.hpp"
#include <cassert>

void testInsert();
void testDelete();
void testIntersection();
void testSum();
void testSub();
void testEqualityOperator();

int main() {
    testInsert();
    testDelete();
    testIntersection();
    testSum();
    testSub();
    testEqualityOperator();
    return 0;
}

void testInsert(){
    setHashed<int> newSet;
    assert(!newSet.contains(1));
    newSet.insertElement(1);
    assert(newSet.contains(1));
}

void testDelete(){
    setHashed<int> newSet;
    newSet.deleteElement(2);
    assert(!newSet.contains(2));

    assert(!newSet.contains(1));

    newSet.insertElement(1);
    newSet.deleteElement(1);

    assert(!newSet.contains(1));
    newSet.insertElement(2);
    newSet.insertElement(2);
    assert(newSet.contains(2));

    newSet.deleteElement(2);
    assert(!newSet.contains(2));

}

void testIntersection(){
    setHashed<int> newSet1;
    setHashed<int> newSet2;
    setHashed<int> sumSet3;

    newSet1.insertElement(1);
    newSet1.insertElement(2);
    newSet1.insertElement(3);
    newSet1.insertElement(4);

    newSet2.insertElement(3);
    newSet2.insertElement(4);
    newSet2.insertElement(5);

    sumSet3 = newSet1 * newSet2;

    assert(!sumSet3.contains(1));
    assert(!sumSet3.contains(2));
    assert(sumSet3.contains(3));
    assert(sumSet3.contains(4));
    assert(!sumSet3.contains(5));
}

void testSum(){
    setHashed<int> newSet1;
    setHashed<int> newSet2;
    setHashed<int> sumSet3;

    newSet1.insertElement(1);
    newSet1.insertElement(2);
    newSet1.insertElement(3);
    newSet1.insertElement(4);

    newSet2.insertElement(3);
    newSet2.insertElement(4);
    newSet2.insertElement(5);

    sumSet3 = newSet1 + newSet2;
    assert(sumSet3.contains(1));
    assert(sumSet3.contains(2));
    assert(sumSet3.contains(3));
    assert(sumSet3.contains(4));
    assert(sumSet3.contains(5));

}

void testSub(){
    setHashed<int> newSet1;
    setHashed<int> newSet2;
    setHashed<int> sumSet3;

    newSet1.insertElement(1);
    newSet1.insertElement(2);
    newSet1.insertElement(3);
    newSet1.insertElement(4);

    newSet2.insertElement(3);
    newSet2.insertElement(4);
    newSet2.insertElement(5);

    sumSet3 = newSet1 - newSet2;

    assert(sumSet3.contains(1));
    assert(sumSet3.contains(2));
    assert(!sumSet3.contains(3));
    assert(!sumSet3.contains(4));
    assert(!sumSet3.contains(5));

}

void testEqualityOperator(){
    setHashed<int> newSet1;
    setHashed<int> newSet2;

    newSet1.insertElement(1);
    newSet1.insertElement(2);
    newSet1.insertElement(3);
    newSet1.insertElement(4);

    newSet2.insertElement(3);
    newSet2.insertElement(4);
    newSet2.insertElement(5);

    assert(!(newSet1 == newSet2));

    newSet1.deleteElement(1);
    newSet1.deleteElement(2);

    newSet2.deleteElement(5);
    assert(newSet1 == newSet2);
}