
#include "ConcretForms.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm("",72, 45), flip(false)
{}

RobotomyRequestForm::RobotomyRequestForm(string new_name):AForm(new_name, 72, 45), flip(false)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy_robotomy):AForm(cpy_robotomy.getName(), 72, 45), flip(cpy_robotomy.flip)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &eq_robotomy)
{
    AForm::operator=(eq_robotomy);
    flip = eq_robotomy.flip;
    return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &bureau)
{
    AForm::execute(bureau);
    cout << "Drilling..." << endl;
    cout << "Robotomy on " << bureau.getName();
    if (flip)
        cout << " succeeded" << endl;
    else
        cout << " failed" << endl;
    flip = !flip;
}   

RobotomyRequestForm::~RobotomyRequestForm()
{}
