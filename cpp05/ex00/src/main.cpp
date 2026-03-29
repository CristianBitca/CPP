/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 18:16:48 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/24 20:45:08 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
 
int main(void)
{
	std::cout << "========================================" << std::endl;
	std::cout << "      BUREAUCRAT CLASS TESTS - 42       " << std::endl;
	std::cout << "========================================" << std::endl;
 
	// ========================================================================
	// TEST 1: Normal Construction
	// ========================================================================
	{
		std::cout << "\n[TEST 1] Normal Construction" << std::endl;
		std::cout << "------------------------------------" << std::endl;
		try
		{
			Bureaucrat alice("Alice", 50);
			std::cout << alice << std::endl;
			std::cout << "✓ Construction successful" << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "✗ Unexpected exception: " << e.what() << std::endl;
		}
	}
 
	// ========================================================================
	// TEST 2: Constructor with Grade Too High (< 1)
	// ========================================================================
	{
		std::cout << "\n[TEST 2] Constructor with Grade Too High" << std::endl;
		std::cout << "------------------------------------" << std::endl;
		try
		{
			Bureaucrat invalid("BadGrade", 0);
			std::cout << "✗ Should have thrown GradeTooHighException" << std::endl;
		}
		catch (const Bureaucrat::GradeTooHighException& e)
		{
			std::cout << "✓ Correctly caught GradeTooHighException: " << e.what() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "✗ Wrong exception type: " << e.what() << std::endl;
		}
	}
 
	// ========================================================================
	// TEST 3: Constructor with Grade Too Low (> 150)
	// ========================================================================
	{
		std::cout << "\n[TEST 3] Constructor with Grade Too Low" << std::endl;
		std::cout << "------------------------------------" << std::endl;
		try
		{
			Bureaucrat invalid("BadGrade", 151);
			std::cout << "✗ Should have thrown GradeTooLowException" << std::endl;
		}
		catch (const Bureaucrat::GradeTooLowException& e)
		{
			std::cout << "✓ Correctly caught GradeTooLowException: " << e.what() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "✗ Wrong exception type: " << e.what() << std::endl;
		}
	}
 
	// ========================================================================
	// TEST 4: Boundary Test - Grade 1 (Best)
	// ========================================================================
	{
		std::cout << "\n[TEST 4] Boundary Test - Grade 1 (Best)" << std::endl;
		std::cout << "------------------------------------" << std::endl;
		try
		{
			Bureaucrat bestGrade("BestBureaucrat", 1);
			std::cout << bestGrade << std::endl;
			std::cout << "✓ Grade 1 accepted" << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "✗ Unexpected exception: " << e.what() << std::endl;
		}
	}
 
	// ========================================================================
	// TEST 5: Boundary Test - Grade 150 (Worst)
	// ========================================================================
	{
		std::cout << "\n[TEST 5] Boundary Test - Grade 150 (Worst)" << std::endl;
		std::cout << "------------------------------------" << std::endl;
		try
		{
			Bureaucrat worstGrade("WorstBureaucrat", 150);
			std::cout << worstGrade << std::endl;
			std::cout << "✓ Grade 150 accepted" << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "✗ Unexpected exception: " << e.what() << std::endl;
		}
	}
 
	// ========================================================================
	// TEST 6: Increment Grade (Improve Rank)
	// ========================================================================
	{
		std::cout << "\n[TEST 6] Increment Grade (Improve Rank)" << std::endl;
		std::cout << "------------------------------------" << std::endl;
		try
		{
			Bureaucrat bob("Bob", 50);
			std::cout << "Before increment: " << bob << std::endl;
			bob.incrementGrade();
			std::cout << "After increment:  " << bob << std::endl;
			if (bob.getGrade() == 49)
				std::cout << "✓ Grade correctly decreased from 50 to 49" << std::endl;
			else
				std::cout << "✗ Grade is " << bob.getGrade() << ", expected 49" << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "✗ Unexpected exception: " << e.what() << std::endl;
		}
	}
 
	// ========================================================================
	// TEST 7: Decrement Grade (Worsen Rank)
	// ========================================================================
	{
		std::cout << "\n[TEST 7] Decrement Grade (Worsen Rank)" << std::endl;
		std::cout << "------------------------------------" << std::endl;
		try
		{
			Bureaucrat charlie("Charlie", 50);
			std::cout << "Before decrement: " << charlie << std::endl;
			charlie.decrementGrade();
			std::cout << "After decrement:  " << charlie << std::endl;
			if (charlie.getGrade() == 51)
				std::cout << "✓ Grade correctly increased from 50 to 51" << std::endl;
			else
				std::cout << "✗ Grade is " << charlie.getGrade() << ", expected 51" << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "✗ Unexpected exception: " << e.what() << std::endl;
		}
	}
 
	// ========================================================================
	// TEST 8: Increment at Maximum (Grade 1) - Should Throw
	// ========================================================================
	{
		std::cout << "\n[TEST 8] Increment at Maximum (Grade 1)" << std::endl;
		std::cout << "------------------------------------" << std::endl;
		try
		{
			Bureaucrat maxGrade("MaxGrade", 1);
			std::cout << "Current grade: " << maxGrade << std::endl;
			maxGrade.incrementGrade();
			std::cout << "✗ Should have thrown GradeTooHighException" << std::endl;
		}
		catch (const Bureaucrat::GradeTooHighException& e)
		{
			std::cout << "✓ Correctly caught GradeTooHighException: " << e.what() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "✗ Wrong exception type: " << e.what() << std::endl;
		}
	}
 
	// ========================================================================
	// TEST 9: Decrement at Minimum (Grade 150) - Should Throw
	// ========================================================================
	{
		std::cout << "\n[TEST 9] Decrement at Minimum (Grade 150)" << std::endl;
		std::cout << "------------------------------------" << std::endl;
		try
		{
			Bureaucrat minGrade("MinGrade", 150);
			std::cout << "Current grade: " << minGrade << std::endl;
			minGrade.decrementGrade();
			std::cout << "✗ Should have thrown GradeTooLowException" << std::endl;
		}
		catch (const Bureaucrat::GradeTooLowException& e)
		{
			std::cout << "✓ Correctly caught GradeTooLowException: " << e.what() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "✗ Wrong exception type: " << e.what() << std::endl;
		}
	}
    return 0;
}