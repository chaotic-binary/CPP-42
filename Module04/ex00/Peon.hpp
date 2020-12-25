/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeria <valeria@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 04:07:48 by valeria           #+#    #+#             */
/*   Updated: 2020/12/25 04:07:48 by valeria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP
# include <iostream>

class Peon
{
public:
	Peon();
	Peon(const Peon &copy);
	~Peon();
	Peon &operator=(const Peon &copy);

private:
};

#endif
