//
//  UnitKit.hpp
//  UnitKit
//
//  Created by Harry Potter on 2021/5/26.
//

#ifndef UnitKit_hpp
#define UnitKit_hpp

#include <iostream>
#include <string>
#include <typeinfo>

namespace UnitKit {
    class Unit {
    protected:
        double value;
    public:
        virtual std::string getUnitFlag();
        // Initalizers;
        Unit();
        Unit(double);
        Unit(Unit &);
        Unit(Unit &&);
        
        // Operators
        virtual bool operator==(Unit &);
        virtual bool operator!=(Unit & another) { return !((*this) == (another));}
        Unit operator+(Unit & another) { return Unit(this -> value + another.value); }
        Unit operator-(Unit & another) { return Unit(this -> value - another.value); }
        Unit operator*(double n) {
            return Unit(this -> value * n);
        }
        Unit operator/(double n) {
            return Unit(this -> value / n);
        }
        
        // Type casts
        virtual operator double() { return (*this).value; }
        
        // Friends
        friend std::ostream& operator<<(std::ostream&, Unit &);
        friend std::istream& operator>>(std::istream&, Unit &);
    };
    std::ostream& operator<<(std::ostream&, Unit &);
    std::istream& operator>>(std::istream&, Unit &);

    // Classes
    namespace BaseTypes {
        
        // Gram
        class Gram : public UnitKit::Unit {
        public:
            Gram() : Unit() {};
            Gram(double v) : Unit(v) {};
            Gram(Gram & a) : Unit(a) {};
            Gram(Gram && a) : Unit(a) {};
            Gram(Unit & u) : Unit(u) {};
            Gram(Unit && u) : Unit(u) {};
            
            std::string getUnitFlag() override {
                return std::string("g");
            }
            
            Gram operator+(Unit & another) { return Gram(this -> value + double(another)); }
            Gram operator-(Unit & another) { return Gram(this -> value - double(another)); }
            Gram operator*(double n) {
                return Gram(this -> value * n);
            }
            Gram operator/(double n) {
                return Gram(this -> value / n);
            }
            
            friend std::ostream& operator<<(std::ostream&, Gram &&);
        };
        std::ostream& operator<<(std::ostream&, Gram &&);
    
        // Meter
        class Meter : public UnitKit::Unit {
        public:
            Meter() : Unit() {};
            Meter(double v) : Unit(v) {};
            Meter(Meter & a) : Unit(a) {};
            Meter(Meter && a) : Unit(a) {};
            Meter(Unit & u) : Unit(u) {};
            Meter(Unit && u) : Unit(u) {};
            
            std::string getUnitFlag() override {
                return std::string("m");
            }
            
            Meter operator+(Unit & another) { return Meter(this -> value + double(another)); }
            Meter operator-(Unit & another) { return Meter(this -> value - double(another)); }
            Meter operator*(double n) {
                return Meter(this -> value * n);
            }
            Meter operator/(double n) {
                return Meter(this -> value / n);
            }
            
            friend std::ostream& operator<<(std::ostream&, Meter &&);
        };
        std::ostream& operator<<(std::ostream&, Meter &&);
    
        // Newton
        class Newton : public UnitKit::Unit {
        public:
            Newton() : Unit() {};
            Newton(double v) : Unit(v) {};
            Newton(Newton & a) : Unit(a) {};
            Newton(Newton && a) : Unit(a) {};
            Newton(Unit & u) : Unit(u) {};
            Newton(Unit && u) : Unit(u) {};
            
            std::string getUnitFlag() override {
                return std::string("N");
            }
            
            Newton operator+(Unit & another) { return Newton(this -> value + double(another)); }
            Newton operator-(Unit & another) { return Newton(this -> value - double(another)); }
            Newton operator*(double n) {
                return Newton(this -> value * n);
            }
            Newton operator/(double n) {
                return Newton(this -> value / n);
            }
            
            friend std::ostream& operator<<(std::ostream&, Newton &&);
        };
        std::ostream& operator<<(std::ostream&, Newton &&);
    }
    namespace Variants {
    // Where T should be a deriven class of UnitKit::Unit
        template <typename T>
        class Kilo : public UnitKit::Unit {
        public:
            Kilo<T>() : Unit() {};
            Kilo<T>(double d) : Unit(d) {};
            Kilo<T>(T v) : Unit(double(v) / 1000) {};
            Kilo<T>(Kilo<T> & a) : Unit(a) {};
            Kilo<T>(Kilo<T> && a) : Unit(a) {};
            Kilo<T>(Unit & u) : Unit(u) {};
            Kilo<T>(Unit && u) : Unit(u) {};
            
            std::string getUnitFlag() override {
                return std::string("k") + T(*this).getUnitFlag();
            }
            
            // Type Casts
            operator T() {
                return T(this -> value * 1000);
            }
            
            // Friends
            friend std::ostream& operator<<(std::ostream&, Kilo<T> &&);
        };
        template <typename T>
        std::ostream& operator<<(std::ostream&, Kilo<T> &&);
    }
}


#endif /* UnitKit_hpp */
