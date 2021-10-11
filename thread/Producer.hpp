/*
 * Cursus CentraleSupélec - Dominante Informatique et numérique
 * 3IF1020 - Programmations système - TP n°2
 *
 * Producer.hpp
 */

#pragma once

#include <iostream>
#include <thread>
#include <chrono>
#include <stdio.h>

#include "../osyncstream.hpp"

#include "ProdOrCons.hpp"
#include "../Random.hpp"

/*
 * Producteur de messages
 */
class Producer : public ProdOrCons {
public:
    // Le constructeur de ProdOrCons peut être utilisé pour Producer
    using ProdOrCons::ProdOrCons;

    void operator()() override {
        // TODO : déposer dans box nb_messages nombres entiers positifs avec attente
        // aléatoire entre chaque. Afficher des messages pour suivre l'avancement.
        
        Random generator2{ 1000 };
        int alea;
        for (int i=0; i<nb_messages_; i++){
             alea = random_engine_();
             box_.put(alea);

             using milliseconds = std::chrono::duration< int, std::milli >;

             std::this_thread::sleep_for(milliseconds{generator2()});
        }
    }
};
 
