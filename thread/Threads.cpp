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

    Consumer consumer1{1, boiteAuxLettres, generator, 20};
    Consumer consumer2{2, boiteAuxLettres, generator, 20};
    Producer producer1{1, boiteAuxLettres, generator, 10};
    Producer producer2{2, boiteAuxLettres, generator, 10};
    Producer producer3{3, boiteAuxLettres, generator, 10};
    Producer producer4{4, boiteAuxLettres, generator, 10};

    std::thread c1(consumer1);
    std::thread c2(consumer2);
    std::thread p1(producer1);
    std::thread p2(producer2);
    std::thread p3(producer3);
    std::thread p4(producer4);
    
    c1.join();
    c2.join();
    p1.join();
    p2.join();
    p3.join();
    p4.join();
 
    return 0;
}

