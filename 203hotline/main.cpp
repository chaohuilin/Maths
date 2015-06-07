//
// main.cpp for main in /home/lin_c/Downloads/203hotline
// 
// Made by LIN Chaohui
// Login   <lin_c@epitech.net>
// 
// Started on  Sun Mar 29 14:08:52 2015 LIN Chaohui
// Last update Sun Mar 29 14:19:15 2015 LIN Chaohui
//

#include "hotline.h"

int     main(int ac, char **av)
{
  if (ac < 2)
    std::cout << "Usage: ./203hotline [arg1] [arg2]" << std::endl;
  else if (ac == 3)
    cas_one(av[1], av[2]);
  else
    cas_two(av[1]);
  return (EXIT_SUCCESS);
}
