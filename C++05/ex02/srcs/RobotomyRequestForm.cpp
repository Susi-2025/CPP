
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm("RobotomyRequestForm", 72, 45), _target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm(other),_target(other._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executeAction() const
{
    static std::mt19937 gen(std::random_device{}());
    static std::bernoulli_distribution dist(0.5);

    if (dist(gen) == true)
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else
        std::cout << " Robotomy failed" << std::endl;
}

const std::string& RobotomyRequestForm::getTarget() const
{
    return _target;
}