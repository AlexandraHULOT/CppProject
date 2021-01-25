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
  REQUIRE(Glacoon::getGlacoonCoolingUnit() == 0.01f);
  REQUIRE(Glacoon::getGlacoonColor() == "blue");
  REQUIRE(Glacoon::getGlacoonPrice() == 0.5f);

  //instanciation d'un objet Glacoon
  Glacoon g0(1,2,3,4);
  REQUIRE(g0.getName() == "Glacon 0");
  REQUIRE(g0.getGlacoonPrice() == 0.5f);
  g0.setPrice(0.6f);
  REQUIRE(g0.getGlacoonPrice() == 0.6f);
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
}

