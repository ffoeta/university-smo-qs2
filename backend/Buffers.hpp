#ifndef BUFFERS_HPP
#define BUFFERS_HPP

#include "Package.hpp"
#include "Base.hpp"
#include <vector>
#include <iostream>

class Buffer
{
public:
    Buffer();
    //  пакет
    Package * package();
    //  получить и распределить пакет
    void placeIn(Package * package);
    //  отдать пакет
    Package * takeOut();
    //  пустой ли буфер
    bool empty();
    //  номер источника пакета
    int getN();
private:  
    //  номер пакета
    int n_of_source_;
    //  смотритель
    Base * superviser_;
    //  пакет
    Package * package_;
};

//__________________________________________________________________
//__________________________________________________________________


class Buffers
{
public:
    Buffers(Base * superviser, int n_of_buffers);
    //  положить заявку
    void placeIn(Package * package);
    // отдать заявку
    Package * takeOut();
    //  есть ли в буфере заявки
    bool ready();
    //  заявки в буферах
    std::vector<int> state();
    //  получить время
    void getTime(float time);
private:
    //  время
    float time_;
    //  смотритель
    Base * superviser_;
    //  текущий элемент
    int current_;
    //  управление
    void inc();
    void dec();
    //  кол-во буферов
    int n_of_buffers_;
    //  буферы
    std::vector<Buffer> buffers_;
};




#endif