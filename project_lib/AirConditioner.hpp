#pragma once
#include "EnergyPoweredObject.hpp"

class AirConditioner : public EnergyPoweredObject{
protected:
    static size_t _id;
    static void setPrice(float new_price){ airConditioner_price = new_price;};
private:
    // NB : voir AirConditioner.cpp pour les valeurs/parametres

    //prix d'un climatiseur
    static float airConditioner_price;
    //couleur du climatiseur
    static const sf::Color airConditioner_color;
    //unite de refroidissement d'un climatiseur
    static const float airConditioner_cooling_unit;
    //puissance de fonctionnement
    static const float airConditioner_power;

public:
    AirConditioner() : EnergyPoweredObject(){_id++;};
    AirConditioner(size_t x, size_t y, size_t height, size_t width) : EnergyPoweredObject(x, y, height, width, airConditioner_color, airConditioner_price, airConditioner_cooling_unit,"Climatiseur "+std::to_string(_id++),airConditioner_power){};
    //renvoie l'unite de refroidissement d'un glacoon
    static float getGlacoonCoolingUnit(){return airConditioner_cooling_unit;};
    static sf::Color getColor(){return airConditioner_color;};
    static float getPrice(){return airConditioner_price;};
    std::string toString() const
    {
        return EnergyPoweredObject::toString()+"\n>>>>Climatiseur\n"; 
    }
    std::string description()const{
        std::string s = "Climatiseur : approuve par notre equipe d experts.\n\n";
        s+= "Parametres techniques :\n";
        s+= "\nRefroidissement unitaire :" ;
        s+= std::to_string(airConditioner_cooling_unit);
        s+="\n Prix :";
        s+= std::to_string(airConditioner_price);
        s+="\nConsommation energetique (W)";
        s+= std::to_string(airConditioner_power);
        return s + "\n";
    }

};

//parametres du climatiseur
float AirConditioner::airConditioner_price = 500.;
const sf::Color AirConditioner::airConditioner_color = sf::Color::Yellow ;
const float AirConditioner::airConditioner_power = 3500.;
const float AirConditioner::airConditioner_cooling_unit = 200.;
size_t AirConditioner::_id =0;