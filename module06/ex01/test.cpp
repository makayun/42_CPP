#include <iostream>
#include <stdint.h>

int main() {
int a = 42;
void* ptr = &a; // Pointer to an integer
uintptr_t int_ptr = reinterpret_cast<uintptr_t>(ptr); // Convert pointer to uintptr_t

std::cout << "Pointer value: " << ptr << std::endl;
std::cout << "Integer representation: " << int_ptr << std::endl;

void* new_ptr = reinterpret_cast<void*>(int_ptr); // Convert back to pointer
std::cout << "New pointer value: " << new_ptr << std::endl;

return 0;
}
