/*
** EPITECH PROJECT, 2020
** JAM_streetart_2019
** File description:
** utils
*/

#include "../include/include.hpp"

int random(int minimum_number, int max_number)
{
    return (rand() % (max_number + 1 - minimum_number) + minimum_number);
}