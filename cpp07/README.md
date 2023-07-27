# C++ casts
### Q: **What is casting?**

- **A:**
    
    Casting in C++ is a way of telling the compiler to treat a variable of one type as if it were another type.
    

### Q: **What are the types of casting?**

- **A:**
    
    ### **Static Cast**
    
    This is the most commonly used cast, and it can be used for things like converting a **`double`** to an **`int`**, or converting a **`void*`** to a **`char*`**. It performs no runtime checks. This should be used if you know that you're casting to the correct type. You probably used it during your core many times.
    
    ```cpp
    double d = 3.14;
    int i = static_cast<int>(d); // i becomes 3
    ```
    
    ### **Dynamic Cast**
    
    This is primarily used for handling polymorphism. You can use it to cast a superclass pointer into a subclass pointer. It includes runtime type checking, it will return **`nullptr`** if the object referred to doesn't contain the type we're casting to.
    
    In C++, **`dynamic_cast`** performs a runtime type check to determine whether the given pointer or reference can be safely downcasted to a specific derived type. If the downcast is valid, the **`dynamic_cast`** returns a pointer or reference to the derived type. If the downcast is not valid (e.g., the object is not of the specified derived type), the **`dynamic_cast`** returns a null pointer or throws a **`std::bad_cast`** exception when working with references.
    
    ```cpp
    Base* basePtr = new Derived();
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr); // This is okay
    ```
    
    - …
        - **Use cases:**
        Dynamic casting is used when we want to work with an object of a class hierarchy and we need to ensure that the pointer or reference to a base class actually points to a specific derived class.
        - **Tips:**
        It's often better to use virtual functions when you can, as they provide a way to use derived functionality through a base pointer without needing to know the exact type of the class.
        - **What problem does it solve?**
        Dynamic casting is used to solve the problem of downcasting, which is the process of converting a pointer/reference of a base class to one of its derived classes. In C++, downcasting is not safe, because if the base class pointer/reference does not actually point/refer to a derived class, the program may crash or behave unexpectedly. Dynamic casting provides a safe way to perform downcasting. If the downcast is not possible, a dynamic cast will return a `null pointer` when used with pointers, or throw a **`std::bad_cast`** exception when used with references.
        
        ```cpp
        class Base {
        public:
            virtual ~Base() {} // Always include virtual destructor in base classes
        };
        
        class Derived : public Base {
        public:
            void print() { std::cout << "Derived\n"; }
        };
        
        int main() {
            Base* basePtr = new Derived();
        
            // We know that basePtr actually points to a Derived object, but the compiler doesn't.
            // So, we use dynamic_cast to safely attempt the cast.
            Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
        
            if (derivedPtr) { // If the dynamic_cast is successful, derivedPtr will not be null.
                derivedPtr->print(); // Now we can use it as a Derived*.
            }
        
            delete basePtr; // Clean up
        }
        ```
        
    
    ### **Const Cast**
    
    This is used to add or remove the **`const`** qualifier from a variable. It's generally a bad idea to remove the **`const`** qualifier from a variable that was declared **`const`** (it leads to undefined behavior if you modify the variable), but it can be useful in certain situations with function overloading.
    
    ```cpp
    const int a = 10;
    const int* b = &a;
    int* c = const_cast<int*>(b); // Now c is a pointer to a non-const int
    ```
    
    - …
        - **Use cases:**
        **`const_cast`** is used when we need to pass a **`const`** variable to a function that doesn't accept **`const`** parameters, but we know that function will not modify the variable. It's also used when we need to modify a **`const`** variable in a context where we know it's safe to do so.
        - **Tips:**
        Removing the **`const`** qualifier and modifying the value can lead to undefined behavior, especially if the original variable is **`const`**. It's often better to design your code so that **`const_cast`** isn't necessary.
        - **What problem does it solve?
        `const_cast`** is used to solve the problem of modifying a **`const`** variable or passing a **`const`** variable to a function that doesn't accept **`const`** parameters.
        
        ```cpp
        void print(int* val) {
            *val += 1; // This function modifies the value pointed to by val
            std::cout << *val << std::endl;
        }
        
        int main() {
            const int value = 10;
            print(const_cast<int*>(&value)); // This would be a compile error without the const_cast
        }
        ```
        
    
    ### **Reinterpret Cast**
    
    This is the most dangerous cast. It tells the compiler to treat the variable as an entirely different type. It basically just treats the bit pattern of the object as representing another type, which can lead to all sorts of strange effects.
    
    ```cpp
    int i = 10;
    double* dp = reinterpret_cast<double*>(&i);
    ```
    
    - …
        - **Use cases:**
        **`reinterpret_cast`** is used when we need to convert types at a low level. It can be used to convert between pointers to different types, or between an integral type and a pointer type. It's often used in systems programming and other low-level tasks.
            1. **Object Persistence**: When you need to save and reload objects from storage, such as databases or files, serialization allows you to store the object's state including its pointer references. By serializing the pointers, you can maintain the relationships between objects when reloading them later.
            2. **Interprocess Communication**: When communicating between different processes or systems, serialization can help transfer object data. By serializing pointers, you can send or receive object references across different processes or systems, allowing them to share information and collaborate.
            3. **Caching and Memoization**: In caching systems or memoization techniques, serialized pointers can be used as cache keys. By serializing the pointers, you can identify and retrieve previously computed or fetched results based on the object they reference, avoiding redundant computations or expensive operations.
            4. **Deep Copying**: In some cases, you may need to create deep copies of complex object graphs. By serializing the pointers and then deserializing them, you can create new copies of the objects while preserving the relationships between them.
            5. **Memory Optimization**: In memory-constrained environments, serializing pointers can help optimize memory usage. By storing the objects as serialized data, you can free up memory by removing the actual objects from memory and only keeping the serialized representations. This can be useful when dealing with large object graphs or when temporary persistence is needed.
        - **Tips:**
        It doesn't perform any type checking or safe conversion, so it can easily lead to bugs if not used correctly. It's often better to use safer casts like **`static_cast`** or **`dynamic_cast`** when possible.
        - **What problem does it solve?
        `reinterpret_cast`** is used to solve the problem of converting types at a low level. It allows for more control over the conversion process than other casts, but also requires more care to use correctly.
        
        ```cpp
        int main() {
            int i = 10;
            int* p = &i;
            long int* lp = reinterpret_cast<long int*>(p);
            std::cout << "*lp: " << *lp << std::endl;
        }
        ```
        
        - **(regarding ex01)**
        When you serialize a pointer, you're storing the information necessary to identify the memory location where the object resides. This allows you to later reconstruct the object by deserializing the integer value back into a pointer. For example char is too small to hold the pointer to a class Data
        

### Q: **What is C++ Literal?**

- **A:**
    
    Notation for representing a fixed value in the source code. They are constants because their values cannot be changed after they are defined.
    
    - **Integer literals**: These are whole numbers without a fractional component, such as 5, -7, 42, etc.
    - **Floating-point literals**: These are numbers with a fractional component, such as 1.23, -3.45, 4.2e-10, etc.
    - **Character literals**: These are individual characters enclosed in single quotes, such as 'a', 'Z', '9', etc.
    - **String literals**: These are sequences of characters enclosed in double quotes, such as "hello", "C++", etc.
    - **Boolean literals**: The two boolean literals are **`true`** and **`false`**.
    - **Pointer literals**: The only pointer literal is the null pointer, which is written as **`nullptr`** in C++.
    - **User-defined literals**: C++11 introduced the ability to define your own literals by defining a literal operator. For example, you could define a literal for complex numbers so that you can write **`1.23i`** to mean **`std::complex<double>(0, 1.23)`**.

### Q: **What is a static class?**

- **A:**
    
    Class where all the methods are static.