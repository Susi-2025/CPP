#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "========== ClapTrap Tests ==========" << std::endl;

    ClapTrap A("Hive");
    ClapTrap B(A);
    ClapTrap C("Byyyy");
	C = A;

    std::cout << std::endl;

    A.attack("CPP");
    A.takeDamage(5);
    A.beRepaired(9);

    std::cout << std::endl;

    B.attack("Helsin");
    B.takeDamage(20);
    B.beRepaired(9);

    std::cout << std::endl;


    std::cout << "========== ScavTrap Tests ==========" << std::endl;

    ScavTrap D("Bocal");

    D.attack("Joensu");
    D.takeDamage(5);
    D.beRepaired(9);
    D.guardGate();

    std::cout << std::endl;

    ScavTrap E(D);

    E.takeDamage(200);
    E.beRepaired(9);
    E.guardGate();

    std::cout << std::endl;


    std::cout << "========== FragTrap Tests ==========" << std::endl;

    FragTrap F("Fraggy");

    F.attack("Enemy");
    F.takeDamage(30);
    F.beRepaired(20);
    F.highFivesGuys();

    std::cout << std::endl;


    std::cout << "========== DiamondTrap Tests ==========" << std::endl;

    DiamondTrap G("Dia");

    G.attack("Boss");   
    G.takeDamage(40);
    G.beRepaired(25);

    G.whoAmI();

    std::cout << std::endl;

    std::cout << "========== DiamondTrap Copy ==========" << std::endl;

    DiamondTrap H(G);
    H.whoAmI();

    std::cout << std::endl;

    std::cout << "========== End of tests ==========" << std::endl;

    return 0;
}