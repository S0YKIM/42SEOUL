/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:26:17 by sokim             #+#    #+#             */
/*   Updated: 2022/07/25 19:01:01 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("Default"), grade_(LOWEST_GRADE) {
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name_(name), grade_(grade) {

	if (grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &origin) {
	*this = origin;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &origin) {
	if (this != &origin) {
		*(const_cast<std::string *>(&name_)) = origin.getName();
		grade_ = origin.grade_;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {
}

const std::string	&Bureaucrat::getName() const {
	return (name_);
}

const int	&Bureaucrat::getGrade() const {
	return (grade_);
}

void	Bureaucrat::incrementGrade() {
	if (grade_ - 1 < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	grade_ -= 1;
}

void	Bureaucrat::decrementGrade() {
	if (grade_ + 1 > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	grade_ += 1;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &origin) {
	out << origin.getName() << ", bureaucrat grade " << origin.getGrade();
	return (out);
}
