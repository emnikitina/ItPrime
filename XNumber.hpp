#pragma once

#include <string>

enum digiys { A = 10, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z};

class XNbr {
    private:
        unsigned _nbrSystem;
        unsigned _capacity;
        unsigned* _nbr;

    public:
        XNbr();
        XNbr(unsigned nbrSystem, unsigned capacity);
        XNbr(XNbr const& copy);
        XNbr& operator=(XNbr const& source);
        XNbr(std::string nbr, unsigned nbrSystem, unsigned capacity);
        ~XNbr();
        
        std::string getNbr() const;
        unsigned getCapacity() const;
        unsigned getNbrSystem() const;

        XNbr operator+(int x);
        XNbr operator++(int); // постфиксный
        XNbr operator++(); 
        bool operator==(XNbr const& x);
        bool operator!=(XNbr const& x);
        bool operator<(XNbr const& x);
        bool operator<=(XNbr const& x);
        unsigned digitSum();
};