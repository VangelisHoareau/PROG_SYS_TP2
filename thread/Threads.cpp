/*
 * Cursus CentraleSupélec - Dominante Informatique et numérique
 * 3IF1020 - Programmations système - TP n°2
 *
 * Threads.cpp
 * c++ -std=c++20 Threads.cpp -o Threads -lpthread
 */

#include <iostream>
#include <sstream>
#include <thread>
#include <condition_variable>
#include <mutex>
 
 
#include "../Random.hpp"
#include "../osyncstream.hpp"

#include "Producer.hpp"
#include "Consumer.hpp"
#include "MessageBox.hpp"
 
/*
 * Test avec 1 producteur et 1 consommateur
 */
int main() {
    // Créer un générateur de nombres aléatoires
    // Créer une boîte à lettres
    // Créer un producteur et un consommateur
    // Créer les threads correspondants
    // Attendre la fin des threads

    
    
    MessageBox boiteAuxLettres{};
    Random generator{100};

    Consumer consumer{1, boiteAuxLettres, generator, 20};
    Producer producer{2, boiteAuxLettres, generator, 20};

    std::thread c(consumer);
    std::thread p(producer);
    
    c.join();
    p.join();
 
    return 0;
}

