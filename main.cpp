//
//  main.cpp
//  UnitKit
//
//  Created by Harry Potter on 2021/5/26.
//

#include <iostream>
#include "UnitKit.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    UnitKit::Variants::Kilo<UnitKit::BaseTypes::Gram> kg(4.0);
    cout << kg << endl;
    cout << UnitKit::BaseTypes::Gram(kg) << endl;
    return 0;
}
