#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "EnergyPoweredObject.hpp"
#include "EnergySupplyObject.hpp"
#include "Glacoon.hpp"
#include "Object.hpp"
#include <list>

namespace Player
{
//Temperature max et initiale
#define TEMPERATURE_GOAL 25
#define INITIAL_TEMPERATURE 50

    class Player
    {
    private:
        unsigned int _wallet = 100;
        std::list<CoolingObject> _coolingObjects_list;
        std::list<EnergySupplyObject> _supplierObjects_list;

    public:
        Player(){};
        int temperature = INITIAL_TEMPERATURE;
        unsigned int getWallet() const { return _wallet; };
        std::list<EnergySupplyObject> getEnergySupplyObjects_list()const {return _supplierObjects_list;};
        std::list<CoolingObject> getCoolingObjects_list()const {return _coolingObjects_list;};
        int getTemperature()
        {
            std::list<CoolingObject>::iterator it;
            for (it = _coolingObjects_list.begin(); it != _coolingObjects_list.end(); it++)
            {
                temperature += it->getTotalCooling();
            }
            return temperature;
        }
        bool buy(const Glacoon &o)
        {
            //si le joueur a assez de sous
            if (_wallet >= Glacoon::getPrice())
            {
                //on ajoute l'objet a la liste des objets refroidissants
                _coolingObjects_list.push_back(o);
                return true;
            }
            return false;
        }
        bool buy(const EnergyPoweredObject &o)
        {
            if (_wallet >= o.getPrice())
            {
                std::list<EnergySupplyObject>::iterator it;
                for (it = _supplierObjects_list.begin(); it != _supplierObjects_list.end(); it++)
                {
                    //si l'un des items fournisseurs d'energie est disponible (ie. qu'il lui reste assez de puissance disponible)
                    if (it->getRemainingPower() >= o.getPowerConsumption())
                    {
                        //branchement automatique sur le premier item fournisseur d'energie (pas forcement efficace...)
                        it->plug(o);
                        return true;
                    }
                }
            }
            return false;
        }
        bool buy(const EnergySupplyObject &o)
        {
            if (_wallet >= o.getPrice())
            {
                _supplierObjects_list.push_back(o);
                return true;
            }
            return false;
        }
        ~Player(){};
    };
} // namespace Player
