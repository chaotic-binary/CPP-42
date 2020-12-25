/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeria <valeria@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 04:07:48 by valeria           #+#    #+#             */
/*   Updated: 2020/12/25 04:07:48 by valeria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP
# include <iostream>

class Sorcerer
{
public:
	Sorcerer();
	Sorcerer(const Sorcerer &copy);
	~Sorcerer();
	Sorcerer &operator=(const Sorcerer &copy);

private:
};

#endif
