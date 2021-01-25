#pragma once
#include "Object.hpp"

class CoolingObject : public Object
{
protected:
    //refroidissement par unite de surface
    float _cooling_unit;

public:
    CoolingObject() : Object(), _cooling_unit(0.){};
    CoolingObject(size_t x, size_t y, size_t height, size_t width, sf::Color color, float price, float cooling_unit,std::string name) : Object(x, y, height, width, color, price,name), _cooling_unit(cooling_unit){};
    ~CoolingObject(){};

    //retourne le refroidissement total de l'objet
    float getCoolingUnit() const { return _cooling_unit; };
    float getTotalCooling() const { return _cooling_unit * _h * _w; };
    std::string toString() const
    {
        std::string s = Object::toString();
        s += "\n>>Objet refroidissant\nrefroidissement par unite de surface:";
        s += std::to_string(_cooling_unit) + '\n';
        return s;
    }
    std::string description() const {return "C'est la classe CoolingOBject, jolie nan ?";};
};
