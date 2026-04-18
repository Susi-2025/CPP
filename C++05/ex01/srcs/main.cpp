
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    std::cout << "-------------NORMAL CASES-----------------" << std::endl;
    try{
        Form f("new form", 5, 20);
        std::cout << "form is " << f << std::endl;
    } catch (std::exception& e) {
        std::cout << "[ERROR 0] " << e.what() << std::endl;
    }

    std::cout << "-------------TOO HIGH CASES 1-----------------" << std::endl;
    try{
        Form f1("new form", -5, 20);
        std::cout << "f form is: " << f1 << std::endl;
    } catch (std::exception& e) {
        std::cout << "[ERROR 1] " << e.what() << std::endl;
    }

    std::cout << "-------------TOO HIGH CASES 2-----------------" << std::endl;
    try{
        Form f2("new form", 5, 0);
        std::cout << "f form is: " << f2 << std::endl;
    } catch (std::exception& e) {
        std::cout << "[ERROR 1] " << e.what() << std::endl;
    }

    std::cout << "-------------TOO LOW CASES 1----------------" << std::endl;
    try{
        Form f3("new form", 151, 20);
        std::cout << "f form is: " << f3 << std::endl;
    } catch (std::exception& e) {
        std::cout << "[ERROR 1] " << e.what() << std::endl;
    }

    std::cout << "-------------TOO LOW CASES 2----------------" << std::endl;
    try{
        Form f4("new form", 1, 151);
        std::cout << "f form is: " << f4 << std::endl;
    } catch (std::exception& e) {
        std::cout << "[ERROR 1] " << e.what() << std::endl;
    }

    std::cout << "-------------NORMAL SIGN CASES-----------------" << std::endl;
    try{
        Bureaucrat a("A", 8);
        std::cout << "a bureaucrat is: " << a << std::endl;
        std::cout << a << std::endl;
        Bureaucrat b("B", 8);

        std::cout << "b bureaucrat is: " << b << std::endl;
        a.incrementGrade();
        std::cout << "new a bureaucrat is: " << a << std::endl;
        b.decrementGrade();
        std::cout << "new b bureaucrat is: " << b << std::endl;
        Form f("new form", 8, 20);
        Form fb("new form", 8, 20);
        std::cout << "form for A is " << f << std::endl;
        std::cout << "form for B is " << fb << std::endl;
        a.signForm(f);
        b.signForm(fb);
    } catch (std::exception& e) {
        std::cout << "[ERROR 0] " << e.what() << std::endl;
    }

    std::cout << "-------------TEST SIGNED ALREADY-----------------" << std::endl;
    try{
        Bureaucrat at("AAA", 5);
        Bureaucrat bt("BBB", 5);

        Form f("test form", 8, 20);
        at.signForm(f);
        bt.signForm(f);
    } catch (std::exception& e) {
        std::cout << "[ERROR 0] " << e.what() << std::endl;
    }
}