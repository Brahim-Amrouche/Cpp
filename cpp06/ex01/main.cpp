/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:37:21 by bamrouch          #+#    #+#             */
/*   Updated: 2023/10/02 13:47:34 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "string"

using std::string;

int main()
{
    
    string content("hello serializer");
    Data node(NULL, &content);
    uintptr_t node_ptr = Serializer::serialize(&node);
    Data    *deser_ptr = Serializer::deserialize(node_ptr);
    
    cout << "The actual pointer to the node: " << &node << endl;
    cout << "The serialized version of the node pointer: " << node_ptr << endl;
    cout << "The deserialized version of the node pointer: " << deser_ptr << endl;
    cout << "this is the content after deserialization: " << *(reinterpret_cast<string *>(deser_ptr->getContent()))  << endl;
}


