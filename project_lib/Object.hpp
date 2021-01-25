#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Object{
    protected :
        //position (x,y) de l'objet
        size_t _posx, _posy;
        //taille de l'objet
        size_t _h,_w;
        //couleur
        sf::Color _color;
        //prix de l'objet(determine suivant le type d'objet)
        float _price;
        //nom de l'objet
        std::string _name;

    public :
        Object():_posx(0),_posy(0),_h(1),_w(1),_color(sf::Color::Black),_price(0.),_name(""){};
        Object(size_t x, size_t y, size_t height, size_t width, sf::Color color, float price,std::string name):_posx(x),_posy(y),_h(height),_w(width),_color(color), _price(price),_name(name){};
        std::string getName()const{return _name;};
        sf::Color getColor(){return this->_color;};
        float getPrice()const{return _price;};
        size_t getX()const{return _posx;};
        size_t getY()const{return _posy;};

        std::string toString()const{
            std::string s="";
            s+=">Objet :"+_name+"\nposition:(";
            s+=std::to_string(_posx)+","+std::to_string(_posy);
            s+=")\nhauteur:"+std::to_string(_h);
            s+="\nlargeur:"+std::to_string(_w);
            s+="\nprix:";
            s+=std::to_string(_price);
            return s+"\n";
        }
        friend std::string operator+(const std::string &s,const Object& o){
            return s+ o._name;
        }
        //fonctions virtuelles pures

        //virtual void draw()const = 0;

        //description generale de la classe de l'objet appelant *
        virtual std::string description()const = 0;
        
        ~Object(){};



};