#pragma once 
#include <vector>
#include <stdexcept>

template <typename T>

class ManagerResurse{
    private:
        std::vector<T> elemente;

    public:
        void adauga(const T& element){
            elemente.push_back(element);
        }

        void stergeUltimul(){
            if(!elemente.empty()){
                elemente.pop_back();
            }
        }

        size_t dimensiune() const{
            return elemente.size();
        }

        bool esteGol() const{
            return elemente.empty();
        }

        void goleste(){
            elemente.clear();
        }

        T& ultimul(){
            if (elemente.empty()) throw std::out_of_range("Containerul este gol!");
                return elemente.back();
        }

        T& operator[](size_t index) {
            if (index >= elemente.size()) {
                throw std::out_of_range("Index invalid in ManagerResurse!");
            }
            return elemente[index];
        }

        const T& operator[](size_t index) const {
            if (index >= elemente.size()) {
                throw std::out_of_range("Index invalid in ManagerResurse!");
            }
            return elemente[index];
        }
};