#include "XNumber.hpp"

XNbr::XNbr(): _nbrSystem(10), _capacity(0), _nbr(NULL) {};

XNbr::XNbr(unsigned nbrSystem, unsigned capacity): _nbrSystem(nbrSystem), _capacity(capacity) {
    _nbr = new unsigned[_capacity]; 
    for (size_t i = 0; i < _capacity; i++)
        _nbr[i] = 0;
};

XNbr::XNbr(std::string nbr, unsigned nbrSystem, unsigned capacity): _nbrSystem(nbrSystem), _capacity(capacity) {
    _nbr = new unsigned[_capacity];
    if (nbr == "max") {
        for (size_t i = 0; i < _capacity; i++) {
            _nbr[i] = _nbrSystem - 1;
        }
        return ;
    }
    for (size_t i = 0; i < _capacity; i++) {
        if (nbr[i] >= '0' && nbr[i] <= '9')
            _nbr[i] = nbr[i] - '0';
        else if (nbr[i] >= 'A' && nbr[i] <= 'Z')
            _nbr[i] = 10 + nbr[i] - 'A';
        else
            throw ;
    }
};

XNbr::XNbr(XNbr const& copy): _nbrSystem(copy._nbrSystem), _capacity(copy._capacity) {
    _nbr = new unsigned[_capacity];
    for (size_t i = 0; i < _capacity; i++)
        _nbr[i] = copy._nbr[i];
};

XNbr& XNbr::operator=(XNbr const& source) {
    if (this != &source) {
        _capacity = source._capacity;
        _nbr = new unsigned[_capacity];
        for (size_t i = 0; i < _capacity; i++)
            _nbr[i] = source._nbr[i];
    }
    return *this;
};

XNbr::~XNbr() {
    delete[] _nbr;
};

std::string XNbr::getNbr() const {
    std::string nbr = "";

    for (size_t i = 0; i < _capacity; i++) {
        if (_nbr[i] > 9)
            nbr += ('A' + _nbr[i] - A); 
        else
            nbr += ('0' + _nbr[i]);
    }
    return nbr;
};

unsigned XNbr::getCapacity() const {
    return _capacity;
};

unsigned XNbr::getNbrSystem() const {
    return _nbrSystem;
};

XNbr XNbr::operator+(int x) {
    _nbr[_capacity - 1] += x;
    for (int i = _capacity - 1; i >= 0; i--) {
        if (_nbr[i] >= _nbrSystem) {
            if (i == 0)
                throw ;
            _nbr[i - 1] += 1;
            _nbr[i] = 0;
        }
    }
    return *this;
};

XNbr XNbr::operator++(int) {
    XNbr prev = *this;
    operator+(1);
    return prev;
};

XNbr XNbr::operator++() {
   operator+(1);
   return *this;
};

bool XNbr::operator==(XNbr const& x) {
    for (size_t i = 0; i < _capacity; i++) {
        if (_nbr[i] != x._nbr[i])
            return false; 
    }
    return true;
};

bool XNbr::operator!=(XNbr const& x) {
    return !(*this == x);
};

bool XNbr::operator<(XNbr const& x) {
    for (size_t i = 0; i < _capacity; i++) {
        if (_nbr[i] < x._nbr[i])
            return true; 
    }
    return false;
};

bool XNbr::operator<=(XNbr const& x) {
    return (*this < x || *this == x);
};

unsigned XNbr::digitSum() {
    unsigned long sum = 0;
    for (size_t i = 0; i < _capacity; i++)
        sum += _nbr[i];
    return sum;
};