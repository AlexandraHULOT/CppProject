#pragma once
#include "Object.hpp"
#include <map>
#include "EnergyPoweredObject.hpp"

class EnergySupplyObject : public Object{
    private : 
    protected:

        //puissance totale que peut fournir l'objet (qui requiert une alimentation) 
        float _power_unit;
        //ensemble des objets alimentes par notre objet de type EnergyPoweredObject
        std::map<EnergyPoweredObject,float,EnergyPoweredObject::classcomp> _powered_objects;
        
    public:
        EnergySupplyObject():Object(),_power_unit(0.){};
        EnergySupplyObject(size_t x, size_t y, size_t height, size_t width, sf::Color color, float price,float power_unit,std::string name):Object(x,y,height,width,color,price,name),_power_unit(power_unit){};
        ~EnergySupplyObject(){};

        //retourne la puissance totale que peut fournir l'objet
        float getTotalPower()const{return _power_unit;}
        //retourne une string de tous les objets alimentes avec leur consommation respective
        std::string getPoweredObjects()const{
            std::string s = "" ;
            for (auto const &obj : _powered_objects)
                s = s+ obj.first+ " consomme "+ std::to_string(obj.second)+ " W\n";
            return s;
        }
        //retourne la puissance totale fournie
        float getPowerSupplied() const{
            float pw = 0. ;
            for (auto const &o : _powered_objects)
                pw += o.second;
            return pw;
        }
        float getRemainingPower()const{
            return getTotalPower() - getPowerSupplied();
        }
        //si l'objet a brancher est de type EnergyPoweredObject et si l'objet appelant peut fournir cette puissance, return true
        //return false sinon
        template<typename T>bool plug( const T& o){
            if ( (std::is_base_of<EnergyPoweredObject,T>::value) && ((_power_unit - getPowerSupplied()) >= 0.)){
                _powered_objects.insert(std::pair<EnergyPoweredObject,float>(o ,o.getPowerConsumption()));
                return true;
            }
            return false;
        }
        std::string toString()const{
            std::string s ="";
            s+=">>Objet fournisseur d'energie\npuissance totale que peut fournir l'objet:";
            s+=std::to_string(_power_unit);
            s+="Objets branches :";
            s+= getPoweredObjects();
            s+="puissance disponible:";
            s+=std::to_string(_power_unit - getPowerSupplied());
            return s+"\n";
        }
        std::string description()const{return "";};
        

};  