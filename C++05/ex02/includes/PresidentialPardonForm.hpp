
#pragma once
#include "AForm.hpp"

class PresidentialPardonForm: public AForm{
    private:
        std::string _target;
    
    public:
        PresidentialPardonForm() = delete;
        explicit PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other) = delete;
        ~PresidentialPardonForm();

        void executeAction() const;

        const std::string& getTarget() const override;
};