
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm("ShrubberyCreatioForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: AForm(other),_target(other._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const {
    std::string out_file = _target + "_shrubbery";
    std::ofstream ostr(out_file);
    if(!ostr.is_open()){
        throw std::runtime_error("failed to open" + out_file + "\n");
    }
    ostr <<
"          /\\\n"
"         /**\\\n"
"        /****\\\n"
"       /******\\\n"
"      /********\\\n"
"     /**********\\\n"
"    /************\\\n"
"          ||\n"
"          ||\n";
}

const std::string& ShrubberyCreationForm::getTarget() const {
    return _target;
}