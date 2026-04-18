#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm{
    private:
        std::string _target;
        
    public:
        ShrubberyCreationForm() = delete;
        explicit ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other) = delete;
        ~ShrubberyCreationForm();

        void executeAction() const;
        const std::string& getTarget() const override;
};