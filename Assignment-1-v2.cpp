/*
________________TITLE____________________
PHYS30762 - Assignment 1 - The Bohr Atom
_________________________________________
This C++ script calculates transition energy using simple Bohr formula.

Created by Kuba Kane (ID: 11019699)
Created on Mon 9 Feb 2026
Last updated on Tue 10 Feb 2026
*/

#include<iostream>
#include<string>
#include<cmath>
using std::string;

const double ELECTRON_CHARGE = 1.602176634e-19;


int valid_int_input()
{
    int value;
    std::cin>>value;

    while(std::cin.fail() || value <= 0 || std::cin.peek() != '\n') //While the input (cin) is a fail, i.e. is not an integer since we are storing to an integer variable year
    {
        std::cout<<" Input must be a valid positive integer. Please try again: "; //Asks the user again to input
        std::cin.clear(); //Clears the flag of fail
        std::cin.ignore(1000, '\n');  //Ignores the failed input value
        std::cin>>value; //Resets the variable
    }

    return value;
    
}


double photon_energy(double Z, double n_i, double n_j)
{
    double energy{};
    energy = 13.6 * (pow(Z, 2)) * ((1.0/pow(n_j, 2))-(1.0/pow(n_i, 2)));

    return energy;
 }


int main()
{
    //Declaration of string variables (integer values declared via function "valid_int_input")
    string energy_unit{};
    string repeat{"y"};
    double energy_output{};

    std::cout<<"CALCULATION OF PHOTON ENERGY OF A GIVEN ELECTRON TRANSITION"<<std::endl;

    //While the user asks to repeat the calculation
    while(repeat=="y")
    {
        //Store user inputs
        std::cout<<"Enter the atomic number of the atom: ";
        int atomic_number = valid_int_input(); 

        std::cout<<"Enter the initial quantum number: ";
        int initial_quantum_number = valid_int_input();

        std::cout<<"Enter the final quantum number: ";
        int final_quantum_number = valid_int_input();

        //Loop to reject case where final quantum number > initial quantum number 
        while(final_quantum_number > initial_quantum_number)
        {
            std::cout<<"The final quantum number must be less than the initial quantum number. Enter these again."<<std::endl;
            std::cout<<" Enter the initial quantum number: ";
            initial_quantum_number = valid_int_input();

            std::cout<<" Enter the final quantum number: ";
            final_quantum_number = valid_int_input();
        }

        //Ask user for transition energy units
        std::cout<<"Enter units for the transition energy ('J' for Joules or 'eV' for electron volts): ";
        std::cin>>energy_unit;

        //Loop to reject strings which are not "J" or "eV"
        while(energy_unit!="J" && energy_unit!="eV")
        {
            std::cout<<" Units must be 'J' or 'eV'. Please try again: ";
            std::cin.ignore(1000, '\n');  //Ignores the failed input value
            std::cin>>energy_unit;
        }

        //Calculate energy with inputted values
        energy_output = photon_energy(atomic_number, initial_quantum_number, final_quantum_number);

        //Convert output if energy units are J
        if(energy_unit == "J")
        {
            energy_output*=ELECTRON_CHARGE;
        }
        
        //Print out photon energy
        std::cout<<"Calculated photon energy = "<<energy_output<<" "<<energy_unit<<std::endl;
        
        //Ask to repeat calculation
        std::cout<<std::endl;
        std::cout<<"Do you want to repeat this calculation (y/n)? ";
        std::cin>>repeat;

        //Check repeat is "y" or "n"
        while(repeat!="y" && repeat!="n")
        {
            std::cout<<" Enter only 'y' or 'n'. Try again: ";
            std::cin.ignore(1000, '\n');
            std::cin>>repeat;
        }
    }

    return 0;
}