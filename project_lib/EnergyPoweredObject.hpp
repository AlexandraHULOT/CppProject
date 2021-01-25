#pragma once
#include "CoolingObject.hpp"

class EnergyPoweredObject : public CoolingObject{

        protected:
        float _power_consumption;

        public:
        EnergyPoweredObject():CoolingObject(),_power_consumption(0.){};
        EnergyPoweredObject(size_t x, size_t y, size_t height, size_t width, sf::Color color, float price,float cooling_unit,std::string name, float power_consumption):CoolingObject(x,y,height,width,color,price,cooling_unit,name),_power_consumption(power_consumption){};
        std::string description()const{return "";};
        ~EnergyPoweredObject(){};
        struct classcomp {
                bool operator() (const EnergyPoweredObject& s1,const EnergyPoweredObject& s2)const{
                        return s1.getPowerConsumption()  <= s2.getPowerConsumption() ;
                }
        };
        float getPowerConsumption() const{ return _power_consumption;};
        std::string toString()const{ return ">>>Objet qui requiert une alimentation\nconsommation energetique:"+std::to_string(_power_consumption)+"\n";};
        
};