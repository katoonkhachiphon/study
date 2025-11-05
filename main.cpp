#include <iostream>
#include <vector>

struct A {
  // std::vector<int> v(8); // member variable initialization not work
  // Need C++11 direct list intialization
  // std::vector<int> v{std::vector<int>(8)};
};

int main() {
  std::cout << "start vector" << "\n";

  std::vector<int> v(5); // Use contructor instead of direct list initialization
  v[0] = 1000;

  std::cout << v[0] << "\n";
  std::cout << &v[0] << "\n";
  std::cout << &v[1] << "\n";
  std::cout << &v[5] << "\n";

  // Need C++17 CTAD
  // std::vector vowels{'a', 'e', 'i', 'o', 'u'};

  // Need C++11 direct list intialization
  // std::vector<char> vowels{'a', 'e', 'i', 'o', 'u'};

  // Need C++11 auto
  // for (auto i : vowels) {
  //   std::cout << i << "\n";
  // }

  int myArray[] = {1, 2, 3, 4, 5};
  std::vector<int> my_vector(myArray, myArray + 5);
  std::string my_string = "Hello, C++!";

  // Using vector::size_type
  std::vector<int>::size_type vector_size = my_vector.size();
  std::cout << "Vector size: " << vector_size << std::endl;

  // Using string::size_type
  std::string::size_type string_length = my_string.length();
  std::cout << "String length: " << string_length << std::endl;

  // Iterating with size_type
  for (std::vector<int>::size_type i = 0; i < my_vector.size(); ++i) {
    std::cout << my_vector[i] << " ";
  }

  int primeArray[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
  std::vector<int> prime(primeArray, primeArray + 10);
  std::cout << prime[3] << '\n'; // okay: 3 converted from int to std::size_t,
                                 // not a narrowing conversion

  // Need C++11 constexpr
  // constexpr int indexcx = 3;     // constexpr
  // okay: constexpr index implicitly converted to std::size_t, not a narrowing
  // conversion
  // std::cout << prime[indexcx] << '\n';

  std::size_t indexst = 3;             // non-constexpr
  std::cout << prime[indexst] << '\n'; // operator[] expects an index of type
                                       // std::size_t, no conversion required

  int index = 3; // non-constexpr
  std::cout << prime[index]
            << '\n'; // possible warning: index implicitly converted to
                     // std::size_t, narrowing conversion
  std::cout << prime.data()[index] << '\n'; // okay: no sign conversion warnings
}