#include <iostream>

#include "searchable_array_bag.hpp"
#include "searchable_tree_bag.hpp"
#include "set.hpp"

void section(const char* name) {
    std::cout << "\n====================\n";
    std::cout << name << "\n";
    std::cout << "====================\n";
}

int main() {

    int data[] = {1,2,3,4};

    section("STEP 1: CREATE BAGS");

    searchable_array_bag arrayBag;
    searchable_tree_bag  treeBag;

    section("STEP 2: INSERT VALUES");

    arrayBag.insert(data,4);
    treeBag.insert(data,4);

    std::cout << "\nEXPECTED (array): 1 2 3 4\n";
    std::cout << "ACTUAL   (array): ";
    arrayBag.print();

    std::cout << "\nEXPECTED (tree): 1 2 3 4 (order may vary)\n";
    std::cout << "ACTUAL   (tree): ";
    treeBag.print();


    section("STEP 3: CLONE TEST");

    searchable_bag* cloneA = arrayBag.clone();
    searchable_bag* cloneT = treeBag.clone();

    std::cout << "\nEXPECTED clone equals original\n";
    std::cout << "ACTUAL cloneA: ";
    cloneA->print();
    std::cout << "ACTUAL cloneT: ";
    cloneT->print();


    section("STEP 4: SET WRAPPER COPY TEST");

    set sa(arrayBag);
    set st(treeBag);

    std::cout << "\nEXPECTED set copies original contents\n";
    std::cout << "ACTUAL sa: ";
    sa.print();
    std::cout << "ACTUAL st: ";
    st.print();


    section("STEP 5: MODIFY ORIGINALS");

    arrayBag.clear();
    treeBag.clear();

    std::cout << "\nEXPECTED originals empty\n";
    std::cout << "ACTUAL arrayBag: ";
    arrayBag.print();
    std::cout << "ACTUAL treeBag: ";
    treeBag.print();

    std::cout << "\nEXPECTED sets UNCHANGED (deep copy via clone)\n";
    std::cout << "ACTUAL sa: ";
    sa.print();
    std::cout << "ACTUAL st: ";
    st.print();


    section("STEP 6: HAS TEST");

    std::cout << "EXPECTED sa.has(3) = 1\n";
    std::cout << "ACTUAL   sa.has(3) = " << sa.has(3) << "\n";

    std::cout << "EXPECTED sa.has(9) = 0\n";
    std::cout << "ACTUAL   sa.has(9) = " << sa.has(9) << "\n";


    delete cloneA;
    delete cloneT;

    return 0;
}