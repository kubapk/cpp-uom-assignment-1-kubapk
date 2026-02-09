/*
________________TITLE____________________
PHYS30762- Assignment 1 - The Bohr Atom
_________________________________________
This C++ script calculates transition energy using simple Bohr formula

Created by Kuba Kane (ID: 11019699)
Created on Mon 9 Feb 2026
Last updated on XX Feb 2026
*/

#include<iostream>
#include<string>
#include<cmath>
using std::string;

double photon_energy(double Z, double n_i, double n_j)
{
    double energy{};
    energy = 13.6 * (pow(Z, 2)) * ((1.0/pow(n_j, 2))-(1.0/pow(n_i, 2)));

    return energy;
 }

int main()
{
    double atomic_number{};
    double initial_quantum_number{};
    double final_quantum_number{};
    string energy_unit{};

    std::cout<<"CALCULATION OF PHOTON ENERGY OF A GIVEN ELECTRON TRANSITION"<<std::endl;
    std::cout<<"Enter the atomic number of the atom: ";
    std::cin>>atomic_number;
    std::cout<<"Enter the initial quantum number: ";
    std::cin>>initial_quantum_number;
    std::cout<<"Enter the final quantum number: ";
    std::cin>>final_quantum_number;
    std::cout<<"Enter units for the transition energy ('J' for Joules or 'e' for electron volts): ";
    std::cin>>energy_unit;

    std::cout<<atomic_number<<" "<<initial_quantum_number<<" "<<final_quantum_number<<" "<<energy_unit<<std::endl;
    
    double energy_output{};
    energy_output = photon_energy(atomic_number, initial_quantum_number, final_quantum_number);
    std::cout<<energy_output<<std::endl;

    return 0;
}