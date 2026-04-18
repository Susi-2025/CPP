
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    std::cout << "1------------SHRUBBERY NOT SIGN CASES-----------------" << std::endl;
    try{
        ShrubberyCreationForm sf("school");
        Bureaucrat bocal("Bocal", 15); // grade is higher than exec_grade but not sign: 137

        std::cout << sf << std::endl;
        std::cout << bocal << std::endl;
        sf.execute(bocal);
    }catch (std::exception& e){
        std::cout << "[ERROR 1]: " << e.what() << std::endl;
    }
    std::cout << "-----------------------------" << std::endl;
    std::cout << "2------------SHRUBBERY SIGNED CASES and EXECUTE-----------------" << std::endl;
    try{
        ShrubberyCreationForm sf1("Hive");
        Bureaucrat bocal1("Students", 136); // grade is higher than exec_grade: 137

        std::cout << sf1<< std::endl;
        std::cout << bocal1 << std::endl;

        bocal1.signForm(sf1);
        sf1.execute(bocal1);
    } catch (std::exception& e){
        std::cout << "[ERROR 2]: " << e.what() << std::endl;
    }
    std::cout << "-----------------------------" << std::endl;
    std::cout << "3------------SHRUBBERY SIGNED CASES and NOT EXECUTE-----------------" << std::endl;
    try{
        ShrubberyCreationForm sf2("Hive");
        Bureaucrat bocal2("Students", 145);// grade is lower than exec_grade: 137

        std::cout << sf2<< std::endl;
        std::cout << bocal2 << std::endl;

        bocal2.signForm(sf2);
        sf2.execute(bocal2);
    } catch (std::exception& e){
        std::cout << "[ERROR 3]: " << e.what() << std::endl;
    }
    std::cout << "-----------------------------" << std::endl;
    std::cout << "4------------ROBOTOMY NOT SIGN CASES-----------------" << std::endl;
    try{
        RobotomyRequestForm rf("CHINA");
        Bureaucrat bocal("Turku", 40); // grade is higher than exec_grade: 45 but not sign

        std::cout << rf << std::endl;
        std::cout << bocal << std::endl;
        rf.execute(bocal);
    }catch (std::exception& e){
        std::cout << "[ERROR 4]: " << e.what() << std::endl;
    }
    std::cout << "-----------------------------" << std::endl;
    std::cout << "5------------ROBOTOMY SIGNED CASES and EXECUTE----------------" << std::endl;
    try{
        RobotomyRequestForm rf2("Job");
        Bureaucrat bocal2("Helsinki", 44);  // grade is higher than exec_grade: 45

        std::cout << rf2 << std::endl;
        std::cout << bocal2 << std::endl;
        bocal2.signForm(rf2);
        rf2.execute(bocal2);
    }catch (std::exception& e){
        std::cout << "[ERROR 5]: " << e.what() << std::endl;
    }
    std::cout << "-----------------------------" << std::endl;
    std::cout << "6------------ROBOTOMY SIGNED CASES and NOT EXECUTE-----------------" << std::endl;
    try{
        RobotomyRequestForm rf3("IT");
        Bureaucrat bocal3("Helsinki", 50);  // grade is lower than exec_grade: 45

        std::cout << rf3 << std::endl;
        std::cout << bocal3 << std::endl;
        bocal3.signForm(rf3);
        rf3.execute(bocal3);
    }catch (std::exception& e){
        std::cout << "[ERROR 6]: " << e.what() << std::endl;
    }
    std::cout << "-----------------------------" << std::endl;
    std::cout << "7------------PRESIDENTIAL NOT SIGN CASES-----------------" << std::endl;
    try{
        PresidentialPardonForm pf1("Trump");
        Bureaucrat bocal4("Helsinki", 4); // grade is higher than exec_grade: 5 but not sign

        std::cout << pf1 << std::endl;
        std::cout << bocal4 << std::endl;
        pf1.execute(bocal4);
    }catch (std::exception& e){
        std::cout << "[ERROR 7]: " << e.what() << std::endl;
    }
    std::cout << "-----------------------------" << std::endl;
    std::cout << "8-----------PRESIDENTIAL SIGNED CASES and EXECUTE---------------" << std::endl;
    try{
        PresidentialPardonForm pf2("Trump");
        Bureaucrat bocal5("Helsinki", 4); // grade is higher than exec_grade: 5

        std::cout << pf2 << std::endl;
        std::cout << bocal5 << std::endl;
        bocal5.signForm(pf2);
        pf2.execute(bocal5);
    }catch (std::exception& e){
        std::cout << "[ERROR 8]: " << e.what() << std::endl;
    }
    std::cout << "-----------------------------" << std::endl;
    std::cout << "9------------PRESIDENTIAL SIGNED CASES and NOT EXECUTE------------------" << std::endl;
    try{
        PresidentialPardonForm pf3("Aliah");
        Bureaucrat bocal5("Joensuu", 6); // grade is lower than exec_grade: 5

        std::cout << pf3 << std::endl;
        std::cout << bocal5 << std::endl;
        bocal5.signForm(pf3);
        pf3.execute(bocal5);
    }catch (std::exception& e){
        std::cout << "[ERROR 9]: " << e.what() << std::endl;
    }
    return 0;
}