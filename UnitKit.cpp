//
//  UnitKit.cpp
//  UnitKit
//
//  Created by Harry Potter on 2021/5/26.
//

#include "UnitKit.hpp"

// class Unit

std::string UnitKit::Unit::getUnitFlag() {
    return std::string("[Invalid Unit]");
}

std::ostream& UnitKit::operator<<(std::ostream& os, Unit & u) {
    os << u.value << u.getUnitFlag();
    return os;
}

std::istream& UnitKit::operator>>(std::istream& is, Unit & u) {
    is >> u.value;
    return is;
}

UnitKit::Unit::Unit() {
    this -> value = 0.0;
}

UnitKit::Unit::Unit(double v) {
    this -> value = v;
}

UnitKit::Unit::Unit(Unit & au) {
    this -> value = au.value;
}

UnitKit::Unit::Unit(Unit && au) {
    this -> value = au.value;
}

bool UnitKit::Unit::operator==(Unit & au) {
    return (this -> value == au.value);
}

// Grams

std::ostream& UnitKit::BaseTypes::operator<<(std::ostream& os, Gram && g) {
    os << g.value << g.getUnitFlag();
    return os;
}

// Meters

std::ostream& UnitKit::BaseTypes::operator<<(std::ostream& os, Meter && g) {
    os << g.value << g.getUnitFlag();
    return os;
}

// Newtons

std::ostream& UnitKit::BaseTypes::operator<<(std::ostream& os, Newton && g) {
    os << g.value << g.getUnitFlag();
    return os;
}

template <typename T>
std::ostream& UnitKit::Variants::operator<<(std::ostream& os, Kilo<T> && k) {
    os << k.value << k.getUnitFlag();
    return os;
}

