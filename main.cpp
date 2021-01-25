#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "project_lib/Glacoon.hpp"
#include "project_lib/AirConditioner.hpp"
#include "project_lib/PowerStrip.hpp"
#include "project_lib/Player.hpp"

using namespace sf;
using namespace std;

#define BLOC_WIDTH 50
#define WINDOW_X 2000
#define WINDOW_Y 850

// Taille de l'ecran
const Vector2f WINDOW_SIZE(WINDOW_X, WINDOW_Y);
//Taille des objets
const Vector2f BLOC_SIZE(BLOC_WIDTH, BLOC_WIDTH);

//notre fond d'ecran est de 1367x767, soit:
//le nombre d'items max par rangee 1367/BLOC_WIDTH
#define MAX_RAW_ITEM 27
//le nombre d'items max par colonne 767/BLOC_WIDTH
#define MAX_COLUMN_ITEM 15

//initialement, nous avons 0 objets
size_t objects_count = 0;
Vector2f pos_last_object(0, 0);


int main()
{

    //on cree la fenetre principale
    RenderWindow window(sf::VideoMode((int)WINDOW_SIZE.x, (int)WINDOW_SIZE.y, 64), "Your cooling factory");
    // Limite la fenetre a 60 images par seconde
    window.setFramerateLimit(60);

    // -------------------Fond d'ecran-----------------
    Texture background_texture;
    background_texture.setSmooth(true);
    if (!background_texture.loadFromFile("background.png"))
    {
        cerr << "Error during import "
             << "background.png" << endl;
        // On ferme le programme
        exit(EXIT_FAILURE);
    }
    Sprite background(background_texture);
    background.setColor(Color::Blue);

    //--------------Player-----------------------------
    Player::Player player;

    //--------------Text-------------------------------
    //----1.Tilte--------------------------------------
    Font font_snow;
    if (!font_snow.loadFromFile("snow.ttf"))
    {
        cerr << "Error during import "
             << "snow.ttf" << endl;
        exit(EXIT_FAILURE);
    }
    Text game_title;
    game_title.setFont(font_snow);
    game_title.setString("YOUR COOLING FACTORY");
    game_title.setCharacterSize(30);
    game_title.setStyle(Text::Bold);
    game_title.setPosition(Vector2f(1450, 0));
    //----2.Parameters--------------------------------------
    Font font_arial;
    if (!font_arial.loadFromFile("arial.ttf"))
    {
        cerr << "Error during import "
             << "arial.ttf" << endl;
        exit(EXIT_FAILURE);
    }
    Text wallet_text;
    wallet_text.setFont(font_arial);
    wallet_text.setString("Porte-monnaie : " + to_string(player.getWallet()) + " $");
    wallet_text.setCharacterSize(30);
    wallet_text.setStyle(Text::Bold);
    wallet_text.setPosition(Vector2f(1400, 100));

    Text temperature_text, temperature_goal_text;
    temperature_text.setFont(font_arial);
    temperature_text.setString("Temperature: " + to_string(player.getTemperature()));
    temperature_text.setCharacterSize(30);
    temperature_text.setStyle(Text::Bold);
    temperature_text.setPosition(Vector2f(1400, 200));
    temperature_goal_text.setFont(font_arial);
    temperature_goal_text.setString("Objectif : " + to_string(TEMPERATURE_GOAL));
    temperature_goal_text.setCharacterSize(30);
    temperature_goal_text.setStyle(Text::Bold);
    temperature_goal_text.setPosition(Vector2f(1400, 250));
    temperature_goal_text.setFillColor(Color::Red);

    //----3.Boutique---------------------------------------
    //glacoon
    Vector2f pos_glacoon(1450, 600);
    RectangleShape glacoon_store(BLOC_SIZE);
    glacoon_store.setPosition(pos_glacoon);
    glacoon_store.setFillColor(Glacoon::getColor());
    //AirConditioner
    Vector2f pos_airConditioner(1550, 600);
    RectangleShape airConditionner_store(BLOC_SIZE);
    airConditionner_store.setPosition(pos_airConditioner);
    airConditionner_store.setFillColor(AirConditioner::getColor());
    //PowerStrip
    Vector2f pos_powerStrip(1550, 700);
    RectangleShape powerstrip_store(BLOC_SIZE);
    powerstrip_store.setPosition(pos_powerStrip);
    powerstrip_store.setFillColor(PowerStrip::getColor());

    //--------------boucle principale------------------
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            //position de la souris
            int MouseX, MouseY;

            //on scrute les evenements
            switch (event.type)
            {
            //clic sur la croix rouge
            case Event::Closed:
            {
                //on ferme la fenetre
                window.close();
                break;
            }
            //mouvement de la souris
            case Event::MouseMoved:
            {
                MouseX = event.mouseMove.x;
                MouseY = event.mouseMove.y;
            }
            //clic sur la souris
            case Event::MouseButtonPressed:
            {
                Mouse::Button button = event.mouseButton.button;

                if (button == Mouse::Left) // clic gauche
                {
                    //clic sur un des items de la boutique : le joueur tente d'acheter. Peut-on rajouter un objet dans la window?
                    if (pos_last_object.x != MAX_RAW_ITEM * BLOC_WIDTH && pos_last_object.y != MAX_COLUMN_ITEM * BLOC_WIDTH)
                    {

                        //clic sur le glacoon de la boutique
                        if (MouseX <= pos_glacoon.x + BLOC_WIDTH && MouseX >= pos_glacoon.x && MouseY <= pos_glacoon.y + BLOC_WIDTH && MouseY >= pos_glacoon.y)
                        {
                            if (player.buy(Glacoon(pos_last_object.x, pos_last_object.y, BLOC_WIDTH, BLOC_WIDTH)))
                            {

                                //mise à jour du nombre d'items
                                objects_count++;
                                pos_last_object = Vector2f(MAX_RAW_ITEM / objects_count, MAX_RAW_ITEM % objects_count);
                            }
                        }
                        //clic sur le airConditioner de la boutique
                        if (MouseX <= pos_airConditioner.x + BLOC_WIDTH && MouseX >= pos_airConditioner.x && MouseY <= pos_airConditioner.y + BLOC_WIDTH && MouseY >= pos_airConditioner.y)
                        {
                            if (player.buy(AirConditioner(pos_last_object.x, pos_last_object.y, BLOC_WIDTH, BLOC_WIDTH)))
                            {

                                //mise à jour du nombre d'items
                                objects_count++;
                                pos_last_object = Vector2f(MAX_RAW_ITEM / objects_count, MAX_RAW_ITEM % objects_count);
                            }
                        }
                        //clic sur le powerstrip de la boutique
                        if (MouseX <= pos_powerStrip.x + BLOC_WIDTH && MouseX >= pos_powerStrip.x && MouseY <= pos_powerStrip.y + BLOC_WIDTH && MouseY >= pos_powerStrip.y)
                        {
                            if (player.buy(PowerStrip(pos_last_object.x, pos_last_object.y, BLOC_WIDTH, BLOC_WIDTH)))
                            {

                                //mise à jour du nombre d'items
                                objects_count++;
                                pos_last_object = Vector2f(MAX_RAW_ITEM / objects_count, MAX_RAW_ITEM % objects_count);
                            }
                        }
                    }
                }
            }
            default:

                break;
            }
        }

        // Remplissage de l'ecran (couleur noire par défaut)
        window.clear();
        // Affichage de la fenetre à l'ecran et ses paramètres de bases
        window.draw(background);
        window.draw(game_title);
        window.draw(wallet_text);
        window.draw(temperature_text);
        window.draw(temperature_goal_text);
        window.draw(glacoon_store);
        window.draw(airConditionner_store);
        window.draw(powerstrip_store);

        //mise à jour des objets achetés -> a revoir

        /*list<EnergySupplyObject>::iterator it;
        for (it = player.getEnergySupplyObjects_list().begin(); it != player.getEnergySupplyObjects_list().end(); it++){
            RectangleShape tmp(BLOC_SIZE);
            tmp.setPosition(1,2);
            tmp.setFillColor(sf::Color::Green);
            window.draw(tmp);
        }*/
        /*list<CoolingObject>::iterator it2;
        for (it2 = player.getCoolingObjects_list().begin(); it2 != player.getCoolingObjects_list().end(); it2++){
            RectangleShape tmp(BLOC_SIZE);
            tmp.setPosition(it2->getX(),it2->getY());
            tmp.setFillColor(it2->getColor());
            window.draw(tmp);
        }*/
        window.display();
    }

    return 0;
}

