
#include "Bureaucrat.hpp"
#include "Form.hpp"
int main()
{
	 // 1. Successful signing
    try {
        Bureaucrat alice("Alice", 5);              // High rank
        Form taxForm("Tax Form", 10, 20);          // Needs grade <= 10 to sign
        std::cout << taxForm << std::endl;
        std::cout << alice << std::endl;

        alice.signForm(taxForm);                   // Should succeed
        std::cout << taxForm << std::endl;
    } catch (std::exception &e) {
        std::cout << "[ERROR 1] " << e.what() << std::endl;
    }

    std::cout << "------------------------------" << std::endl;
    // 2. Unsuccessful signing
    try {
        Bureaucrat bob("Bob", 50);                 // Lower rank
        Form passport("Passport Form", 25, 30);    // Needs grade <= 25 to sign
        std::cout << passport << std::endl;
        std::cout << bob << std::endl;

        bob.signForm(passport);                    // Should fail
        std::cout << passport << std::endl;
    } catch (std::exception &e) {
        std::cout << "[ERROR 2] " << e.what() << std::endl;
    }

    std::cout << "------------------------------" << std::endl;

    // 3. Invalid form creation: grade too high
    try {
        std::cout << "[Trying to create an invalid high form, grade to sign = 0]" << std::endl;
        Form invalidHigh("Invalid High", 0, 20);   // gradeSign = 0 (too high)
    } catch (std::exception &e) {
        std::cout << "[ERROR 3] " << e.what() << std::endl;
    }

    // 4. Invalid form creation: grade too low
    try {
        std::cout << "[Trying to create an invalid low form, grade to sign = 151]" << std::endl;
        Form invalidLow("Invalid Low", 10, 151);   // gradeExec = 151 (too low)
    } catch (std::exception &e) {
        std::cout << "[ERROR 4] " << e.what() << std::endl;
    }

    std::cout << "------------------------------" << std::endl;

    // 5. Multiple bureaucrats
    try {
        Bureaucrat carl("Carl", 30);
        Bureaucrat dana("Dana", 3);
        Form project("Project Proposal", 5, 10);
        std::cout << project << std::endl;
        std::cout << carl << std::endl;
        std::cout << dana << std::endl;

        std::cout << "[Carl tried to sign and failed -> Dana never got the chance to try to sign (throw already!)]" << std::endl;
        carl.signForm(project); // Should fail
        dana.signForm(project); // Should succeed
        std::cout << project << std::endl;
    } catch (std::exception &e) {
        std::cout << "[ERROR 5] " << e.what() << std::endl;
    }

    return 0;
}