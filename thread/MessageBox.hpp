/*
 * Cursus CentraleSupélec - Dominante Informatique et numérique
 * 3IF1020 - Programmations système - TP n°2
 *
 * MessageBox.hpp
 */

#pragma once

#include <array>
#include <algorithm>
#include <mutex>
#include <condition_variable>

#include "../BasicMessageBox.hpp"

/*
 * FIFO d'echange de messages entre producteurs et consommateurs
 * Version pour synchronisation entre threads
 */
std::mutex data_mutex;
std::condition_variable cond_place_not_empty;
std::condition_variable cond_place_not_full;
int nb_data=0;
int nb_gets=0;
int test=0;

class MessageBox : public BasicMessageBox {
public:
    void put( int message ) {
        // TODO : ajouter les mecanismes de synchronisation
        std::unique_lock< std::mutex > lock(data_mutex);
        while(nb_data==box_size_){
            cond_place_not_full.wait(lock);
        }
        basic_put( message );
        nb_data++;
        cond_place_not_empty.notify_all();
      
    }
 
    int get() {
        // TODO : ajouter les mecanismes de synchronisation
        std::unique_lock< std::mutex > lock(data_mutex);
        while (nb_data==0){
            cond_place_not_empty.wait(lock);
        }
        nb_gets++;
        int message{ basic_get() };
        cond_place_not_full.notify_all();
        nb_data--;
        return message;
    }
private:
    // TODO : ajouter les objets de synchronisation
};
 
