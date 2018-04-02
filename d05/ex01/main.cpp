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

	{
		std::cout << "======== ERREUR =======" << std::endl;
		try {
			Form good =  Form("Allan", 0, 0);
			std::cout << good;
		} catch (std::exception& e) {
			std::cout << "ERREUR HAPPEND" << std::endl;
		}
	}
	{
		std::cout << "======== ERREUR =======" << std::endl;
		try {
			Form good = Form("Allan", 151, 10);
			std::cout << good;
		} catch (std::exception& e) {
			std::cout << "ERREUR HAPPEND" << std::endl;
		}
	}
	{
		std::cout << "======== GOOD =======" << std::endl;
		try {
			Form good = Form("Allan", 140, 50);
			Bureaucrat b = Bureaucrat("Bureau", 140);
			b.signForm(&good);
			std::cout << good;
		} catch (std::exception& e) {
			std::cout << "ERREUR HAPPEND" << std::endl;
		}
	}
	{
		std::cout << "======== ERREUR =======" << std::endl;
		try {
			Form good = Form("Allan", 64, 54);
			Bureaucrat b = Bureaucrat("Bureau", 10);	
			b.signForm(&good);					
			std::cout << good;
		} catch (std::exception& e) {
			std::cout << "ERREUR HAPPEND" << std::endl;
		}
	}
	{
		std::cout << "======== GOOD =======" << std::endl;
		try {
			Form good = Form("Allan", 64, 54);
			Bureaucrat b = Bureaucrat("Bureau", 64);	
			b.signForm(&good);					
			std::cout << good;
		} catch (std::exception& e) {
			std::cout << "ERREUR HAPPEND" << std::endl;
		}
	}
	{
		std::cout << "======== GOOD =======" << std::endl;
		try {
			Form good = Form("Allan", 64, 54);
			Bureaucrat b = Bureaucrat("Bureau", 74);	
			b.signForm(&good);					
			std::cout << good;
		} catch (std::exception& e) {
			std::cout << "ERREUR HAPPEND" << std::endl;
		}
	}
	// {
	// 	std::cout << "======== GOOD =======" << std::endl;
	// 	try {
	// 		Form good = Form("Allan", 149);
	// 		std::cout << good;
	// 	} catch (std::exception& e) {
	// 		std::cout << "ERREUR HAPPEND" << std::endl;
	// 	}
	// }
	// {
	// 	std::cout << "======== ERREUR =======" << std::endl;
	// 	try {
	// 		Form good = Form("Allan", 1);
	// 		std::cout << good;
	// 	} catch (std::exception& e) {
	// 		std::cout << "ERREUR HAPPEND" << std::endl;
	// 	}
	// }
	// {
	// 	std::cout << "======== GOOD =======" << std::endl;
	// 	try {
	// 		Form good = Form("Allan", 2);
	// 		std::cout << good;
	// 	} catch (std::exception& e) {
	// 		std::cout << "ERREUR HAPPEND" << std::endl;
	// 	}
	// }
}
