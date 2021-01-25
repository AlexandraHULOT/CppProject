#pragma once
#include "EnergySupplyObject.hpp"

class PowerStrip : public EnergySupplyObject
{
protected:
    static size_t _id;
private:
    // NB : voir PowerStrip.cpp pour les valeurs/parametres

    //prix d'une multiprise
    static float powerStrip_price;
    //couleur d'une multiprise
    static const sf::Color powerStrip_color;
    //puissance generee
    static const float powerStrip_power;

public:
    PowerStrip() : EnergySupplyObject(){_id++;};
    PowerStrip(size_t x, size_t y, size_t height, size_t width) : EnergySupplyObject(x, y, height, width, powerStrip_color, powerStrip_price,powerStrip_power,"Multiprise "+std::to_string(_id++)){};
    
    //renvoie l'unite de refroidissement d'un PowerStrip
    static float getPower(){return powerStrip_power;};
    static sf::Color getColor(){return powerStrip_color;};
    static float getPrice(){return powerStrip_price;};
     std::string toString() const
    {
        return EnergySupplyObject::toString()+"\n>>>Multiprise\n"; 
    }
    std::string description()const{
        std::string s = "Multiprise : Branchee a elle-meme, la multiprise genere une quantite d'energie presque infinie! Cependant, le cout d'une telle ingeniosite est tres elevee...\n\n";
        s+= "Parametres techniques :\n";
        s+= "\npuissance unitaire :" ;
        s+= std::to_string(powerStrip_power);
        s+="\n Prix :";
        s+= std::to_string(powerStrip_price);
        return s + "\n";
    }
};

//parametres de la multiprise
float PowerStrip::powerStrip_price = 50.;
const sf::Color PowerStrip::powerStrip_color = sf::Color::Green ;
const float PowerStrip::powerStrip_power = 999999.99;
size_t PowerStrip::_id = 0;
