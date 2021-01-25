// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include <iostream>
#include "catch.hpp"
#include "AirConditioner.hpp"
#include "Glacoon.hpp"
#include "PowerStrip.hpp"
using namespace std;
TEST_CASE("1: Glacoon")
{
  //parametres
  REQUIRE(Glacoon::getCoolingUnit() == 0.01f);
  REQUIRE(Glacoon::getColor() == sf::Color::Blue);
  REQUIRE(Glacoon::getPrice() == 0.5f);

  //instanciation d'un objet Glacoon
  Glacoon g0(1,2,3,4);
  REQUIRE(g0.getName() == "Glacon 0");
  REQUIRE(g0.getPrice() == 0.5f);
  //cout<<g0.toString()<<endl;
  //cout<<g0.description()<<endl;
}
TEST_CASE("2: PowerStrip")
{
  PowerStrip p0(1,2,3,4);
  REQUIRE(p0.getName() == "Multiprise 0");
  AirConditioner a0(5,6,3,4);
  CHECK(p0.plug(a0));
  REQUIRE(p0.getPowerSupplied()==3500.0f);
  REQUIRE(p0.getX() == 1.);

}

