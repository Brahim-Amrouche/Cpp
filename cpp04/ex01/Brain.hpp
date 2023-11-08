/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:13:51 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/08 20:13:54 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"


class   Brain
{
    private:
        string ideas[100];
    public:
        Brain();
        Brain(const Brain &cpy_brain);
        Brain &operator=(const Brain &eq_brain);
        string    get_idea(size_t i);
        void      set_idea(string idea, size_t i);
        ~Brain();
};