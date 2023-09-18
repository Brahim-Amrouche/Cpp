/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:25:36 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/17 17:11:55 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(string new_name);
        FragTrap(const FragTrap &cpy_frag);
        FragTrap &operator=(const FragTrap &cpy_frag);
        void     highFivesGuys(void);
        ~FragTrap();
};
