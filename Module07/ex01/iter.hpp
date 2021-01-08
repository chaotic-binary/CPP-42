#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void iter(T *arr, size_t len, void (*func)(const T  &));

#endif
