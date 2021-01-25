#pragma once
#include "CoolingObject.hpp"

class Glacoon : public CoolingObject
{
protected:
    static size_t _id ;
    static void setPrice(float new_price){ glacoon_price = new_price;};
private:
    // NB : voir Glacoon.cpp pour les valeurs/parametres

    //prix d'un glacon
    static float glacoon_price;
    //couleur du glacon
    static const sf::Color glacoon_color;
    //unite de refroidissement d'un glacon
    static const float glacoon_cooling_unit;

public:
    Glacoon() : CoolingObject(){_id++;};
    Glacoon(size_t x, size_t y, size_t height, size_t width) : CoolingObject(x, y, height, width, glacoon_color, glacoon_price, glacoon_cooling_unit,"Glacon "+std::to_string(_id++)){};
    //renvoie l'unite de refroidissement d'un glacoon
    static float getGlacoonCoolingUnit(){return glacoon_cooling_unit;};
    static float getPrice(){return glacoon_price;};
    static sf::Color getColor(){return glacoon_color;};
    

    std::string toString() const
    {
        return CoolingObject::toString()+"\n>>>Glacon\n"; 
    }
    std::string description()const{
        std::string s = "Bol a glacons : Fait son job.\n\n";
        s+= "Parametres techniques :\nLe bol a glacons est un objet qui n'a pas besoin d'etre branche.\n";
        s+= "\nRefroidissement unitaire :" ;
        s+= std::to_string(glacoon_cooling_unit);
        s+="\nPrix d'un bol de glacons";
        s+= std::to_string(glacoon_price);
        return s + "\n";
    }
};
//parametres du glacoon
float Glacoon::glacoon_price = 0.5;
const sf::Color Glacoon::glacoon_color = sf::Color::Blue ;
const float Glacoon::glacoon_cooling_unit = 0.01;
size_t Glacoon::_id = 0;
