/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeria <valeria@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 04:07:48 by valeria           #+#    #+#             */
/*   Updated: 2020/12/25 04:07:48 by valeria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP
# include <iostream>

class Victim
{
public:
	Victim();
	Victim(const Victim &copy);
	~Victim();
	Victim &operator=(const Victim &copy);

private:
};

#endif
