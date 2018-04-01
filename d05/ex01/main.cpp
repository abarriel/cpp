#include "Bureaucrat.hpp"

int main() {
	{
		// erreur 
		std::cout << "======== ERREUR =======" << std::endl;
		try {
			Bureaucrat good =  Bureaucrat("Allan", 0);
			std::cout << good;
		} catch (std::exception& e) {
			std::cout << "ERREUR HAPPEND" << std::endl;
		}
	}
	{
		std::cout << "======== ERREUR =======" << std::endl;
		try {
			Bureaucrat good = Bureaucrat("Allan", 151);
			std::cout << good;
		} catch (std::exception& e) {
			std::cout << "ERREUR HAPPEND" << std::endl;
		}
	}
	{
		std::cout << "======== GOOD =======" << std::endl;
		try {
			Bureaucrat good = Bureaucrat("Allan", 140);
			std::cout << good;
		} catch (std::exception& e) {
			std::cout << "ERREUR HAPPEND" << std::endl;
		}
	}
	{
		std::cout << "======== ERREUR =======" << std::endl;
		try {
			Bureaucrat good = Bureaucrat("Allan", 150);
			good.decGrade();
			std::cout << good;
		} catch (std::exception& e) {
			std::cout << "ERREUR HAPPEND" << std::endl;
		}
	}
	{
		std::cout << "======== GOOD =======" << std::endl;
		try {
			Bureaucrat good = Bureaucrat("Allan", 149);
			good.decGrade();
			std::cout << good;
		} catch (std::exception& e) {
			std::cout << "ERREUR HAPPEND" << std::endl;
		}
	}
	{
		std::cout << "======== ERREUR =======" << std::endl;
		try {
			Bureaucrat good = Bureaucrat("Allan", 1);
			good.incGrade();
			std::cout << good;
		} catch (std::exception& e) {
			std::cout << "ERREUR HAPPEND" << std::endl;
		}
	}
	{
		std::cout << "======== GOOD =======" << std::endl;
		try {
			Bureaucrat good = Bureaucrat("Allan", 2);
			good.incGrade();
			std::cout << good;
		} catch (std::exception& e) {
			std::cout << "ERREUR HAPPEND" << std::endl;
		}
	}
}
