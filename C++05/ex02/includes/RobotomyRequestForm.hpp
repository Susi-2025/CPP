
#pragma once
#include "AForm.hpp"
#include <random>

class RobotomyRequestForm : public AForm{
    private:
        std::string _target;
    
    public:
        RobotomyRequestForm() = delete;
        explicit RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other) = delete;

        ~RobotomyRequestForm();

        void executeAction() const;
        const std::string& getTarget() const override;
};