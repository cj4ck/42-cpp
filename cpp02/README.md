# ad-hoc polymorphism, operator overloading and Orthodox Cononical class form
### Q: **What is ad-hoc polimorphizm / function overload?**

- **A:**
    - Function overloading is a C++ principle, which allows you to **define many functions having the same name, but accepting different parameters**
    - It is not just for class member functions, but also works on any function. The principle is that you have an `one-and-only` function name and different parameters for every overload. This will allow you to specialise the process of a function based on its parameters

### Q: **What is operator overload?**

- **A:**
    - **Operator overloading enables you to write function members that enable the basic operators to be applied to class objects**. To do this, you write a function that redefines each operator that you want to use with your class.
    - Groups operators in C++
        - Arithmetic operators
        - Assignment operators
        - Comparison operators
        - Logical operators
        - Bitwise operators
    - Operator overloading allows you to define or change the behaviour of an operator in your program. Operators are essentially just functions
    - C++ gives you full control on operator overloading, however this can lead to a bad use of the language. Only use operator overloading when it makes perfect sense
    - The overload must be related to the natural semantics of the operator. There are not many cases with operator overload. **Make sure there is a good use case for it, otherwise it's easy to make stupid mistakes with it**
    - …
        - Operator overloading usefull for:
            1. Operator overloading in c++ enables programmers to use notation closer to the target domain.
            2. They provide similar support to built-in types of user-defined types.
            3. Operator overloading in c++ makes the program easier to understand.

### Q: **Binary Point?**

- **A:**
    
    A binary point is like the decimal point in a decimal system. It acts as a divider between the integer and the fractional part of a number.
    
    - …
        - The very same concept of decimal point can be applied to our binary representation, making a "binary point". As in the decimal system, a binary point represents the coefficient of the term 2^0 = 1. All digits (or bits) to the left of the binary point carries a weight of 2^0, 2^1, 2^2, and so on. Digits (or bits) on the right of binary point carries a weight of 2^-1, 2^-2, 2^-3, and so on.

### Q: **What is class Canonical form?**

- **A:**
    - It includes:
        - A default constructor
        - A default destructor
        - A copy constructor
        - A assignation operator
    - …
        - A copy constructor
            - A copy constructor is a special member function in C++ that allows you to create a new object by initializing it with the values of an existing object of the same class. It performs a member-wise copy of the data from one object to another.
                - Use the **`const`** keyword in the copy constructor's parameter to ensure the original object is not modified.
                - deep copy
                - copy and swap idiom
                - we don’t copy `static const *int*    _farctional_bits;` because it’s shared among all objects of the class.
        - A assignation operator

### Q: **What are fractional bits?**

- **A:**
    
    In fixed-point number that represent the fractional portion of a value