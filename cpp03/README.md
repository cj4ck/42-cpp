# Inheritance
### Q: **What is inheritance?**

- **A:**
    
    **Inheritance is the means by which you can create new classes by reusing and expanding on existing class definitions.**
    

### Q: **What are inheritance types?**

- **A:**
    
    ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/77668d93-7a37-4ea0-8248-60011b048b08/Untitled.png)
    
    1. **Single Inheritance**: 
    `subclass` inherits from a single `base class`, also known as a `superclass`.
        - `code example`
            
            ```cpp
            class Base {
            public:
            void baseFunction() { std::cout << "Base function.\n"; }
            };
            
            class Derived : public Base {
            public:
            void derivedFunction() { std::cout << "Derived function.\n"; }
            };
            ```
            
    2. **Hierarchical Inheritance**:
    One `superclass` is inherited by multiple `subclasses`
        - `code example`
            
            ```cpp
            #include <iostream>
            
            // Base class
            class Animal {
            public:
                void eat() { std::cout << "I can eat!\n"; }
            };
            
            // First derived class
            class Dog : public Animal {
            public:
                void bark() { std::cout << "I can bark! Woof! Woof!\n"; }
            };
            
            // Second derived class
            class Cat : public Animal {
            public:
                void meow() { std::cout << "I can meow! Meow!\n"; }
            };
            
            int main() {
                Dog d;
                d.eat();    // Inherited from Animal
                d.bark();   // Specific to Dog
            
                Cat c;
                c.eat();    // Inherited from Animal
                c.meow();   // Specific to Cat
            
                return 0;
            }
            ```
            
    3. **Multilevel Inheritance**:
    nInherits from a `base class`, which inherits from another `base class`.
        - `code example`
            
            ```cpp
            class Base {
            public:
                void baseFunction() { std::cout << "Base function.\n"; }
            };
            
            class Intermediate : public Base {
            public:
                void intermediateFunction() { std::cout << "Intermediate function.\n"; }
            };
            
            class Derived : public Intermediate {
            public:
                void derivedFunction() { std::cout << "Derived function.\n"; }
            };
            ```
            
    4. **Hybrid Inheritance**:
    Combination of more than one type of inheritance.
        - `code example`
            
            ```cpp
            #include <iostream>
            
            // Base class
            class Animal {
            public:
                void eat() { std::cout << "I can eat!\n"; }
            };
            
            // Intermediate base class
            class Mammal : public Animal {
            public:
                void breathe() { std::cout << "I can breathe!\n"; }
            };
            
            // Another intermediate base class
            class WingedAnimal : public Animal {
            public:
                void flap() { std::cout << "I can flap!\n"; }
            };
            
            // Multiple inheritance from Mammal and WingedAnimal
            class Bat : public Mammal, public WingedAnimal {
            public:
                void beBat() { std::cout << "I can eat, breathe, and flap!\n"; }
            };
            
            int main() {
                Bat b1;
                b1.eat();
                b1.breathe();
                b1.flap();
                b1.beBat();
                return 0;
            }
            ```
            
    5. **Multiple Inheritance**:
    `subclass` inherits from more than one base class
        - `code example`
            
            ```cpp
            class Base1 {
            public:
                void base1Function() { std::cout << "Base1 function.\n"; }
            };
            
            class Base2 {
            public:
                void base2Function() { std::cout << "Base2 function.\n"; }
            };
            
            class Derived : public Base1, public Base2 {
            public:
                void derivedFunction() { std::cout << "Derived function.\n"; }
            };
            ```
            
    6. **Virtual Inheritance**:
    When you use virtual inheritance, the compiler changes the way the class hierarchy is laid out in memory. Instead of each subclass having its own separate copy of the base class, all subclasses share a single instance of the base class.

### Q: **What are access specifiers in inheritance?**

- **A:**
    
    **Inheritance in C++ can be public, protected, or private, which determines how the members of the base class can be accessed in the derived class.**
    
    - …
        - Public Inheritance: Keep their access privileges in the derived class.
        - Private Inheritance: Public and protected members of the base class become private members of the derived class.
        - Protected Inheritance: All public and protected members of the base class are protected in the derived class.
        - `code example`
            
            ```cpp
            class MyClass {
            public: 
                int publicVar; // Can be accessed from anywhere
            
            private:
                int privateVar; // Can only be accessed within MyClass
            
            protected:
                int protectedVar; // Can be accessed within MyClass and subclasses of MyClass
            };
            
            class MyDerivedClass : public MyClass {
            public:
                void func() {
                    publicVar = 1; // OK: publicVar is public
                    // privateVar = 2; // Error: privateVar is private
                    protectedVar = 3; // OK: protectedVar can be accessed in subclass
                }
            };
            
            int main() {
                MyClass obj;
                obj.publicVar = 1; // OK: publicVar is public
                // obj.privateVar = 2; // Error: privateVar is private
                // obj.protectedVar = 3; // Error: protectedVar is protected
            
                return 0;
            }
            ```
            
        
        ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/a2c609b7-39af-46bc-9882-5c1345b61ec6/Untitled.png)
        

### Q: **What are Virtual Functions?**

- **A:**
    
    **These are functions in the base class that can be overridden in the derived class. This allows for dynamic binding, which is key for achieving polymorphism.**
    
    **A virtual function is a member function that you expect to be redefined in derived classes.**
    
    - When you refer to a derived class object using a pointer or a reference to the base class, you can call a virtual function for that object and execute the derived class's version of the function. This is known as dynamic linkage, or late binding.
        
        ```cpp
        class Base {
        public:
            virtual void print() { std::cout << "Base\n"; }
        };
        
        class Derived : public Base {
        public:
            void print() override { std::cout << "Derived\n"; } // Overrides Base's print function
        };
        
        int main() {
            Base* basePtr = new Derived();
            basePtr->print(); // Outputs "Derived"
            delete basePtr;
            return 0;
        }
        ```
        

### Q: **Abstract Classes and Pure Virtual Functions**

- **A:**
    
    **An abstract class is a class that has at least one pure virtual function (a function declared in the base class that has no implementation). Abstract classes cannot be instantiated, and are meant to be inherited by other classes. A pure virtual function is declared by assigning 0 in its declaration.**
    
    ```cpp
    class AbstractClass {
    public:
        virtual void pureVirtualFunction() = 0; // Pure virtual function
    };
    
    class ConcreteClass : public AbstractClass {
    public:
        void pureVirtualFunction() override { std::cout << "Implemented in ConcreteClass\n"; }
    };
    
    int main() {
        // AbstractClass a; // Error: Cannot create an instance of the abstract class
        ConcreteClass c;
        c.pureVirtualFunction(); // Outputs "Implemented in ConcreteClass"
        return 0;
    }
    ```
    

### Q: **Inheritance and Friendship**

- **A:**
    
    **Inheritance and friendship are orthogonal concepts it means they are independent of each other and changing one does not affect the other.** 
    
    **A derived class does not inherit the base class's friends. Friends of the base class are not necessarily friends of the derived class, and vice versa.**
    
    ```cpp
    class Base {
    private:
        int x;
    friend void friendFunction(Base& b);
    };
    
    void friendFunction(Base& b) {
        b.x = 10; // Can access private members because it's a friend
    }
    
    class Derived : public Base {
        // friendFunction is not a friend of Derived, even though it's a friend of Base
    };
    
    int main() {
        Base base;
        friendFunction(base); // OK
        Derived derived;
        // friendFunction(derived); // Error: friendFunction is not a friend of Derived
        return 0;
    }
    ```
    
    - **What is the concept of “friends” in CPP?**
        
        The concept of "friends" is related to the access control of class members. Normally, a class's `private` and `protected members` can only be accessed by methods that are part of that class. However, sometimes you might want an external function or class to be able to access these members. This is where `"friends"` come in.
        
        You can declare a function or a class as a `"friend"` of a class. **A friend function or class can access the `private` and `protected` members of the class it is a friend of.**
        
        ```cpp
        class MyClass {
        private:
            int secretValue;
        
        public:
            MyClass() : secretValue(42) {}
        
            // Declare an external function as a friend
            friend void revealSecret(MyClass& mc);
        };
        
        // This function is not a member of MyClass, but it can access secretValue because it's a friend
        void revealSecret(MyClass& mc) {
            std::cout << "The secret value is: " << mc.secretValue << std::endl;
        }
        
        int main() {
            MyClass mc;
            revealSecret(mc);  // Outputs: "The secret value is: 42"
            return 0;
        }
        ```
        
        ```cpp
        class MyClass {
        private:
            int secretValue;
        
        public:
            MyClass() : secretValue(42) {}
        
            // Declare an entire class as a friend
            friend class MyFriendClass;
        };
        
        class MyFriendClass {
        public:
            void revealSecret(MyClass& mc) {
                std::cout << "The secret value is: " << mc.secretValue << std::endl;
            }
        };
        
        int main() {
            MyClass mc;
            MyFriendClass mfc;
            mfc.revealSecret(mc);  // Outputs: "The secret value is: 42"
            return 0;
        }
        ```
        

### Q: **What are most common multiple inheritance Issues?**

- **A:**
    
    **Multiple inheritance can lead to complex situations and should be used with care.**
    
    - **What is a “diamond problem”?**
        
        This is the most classic problem with multiple inheritance. It occurs when a class inherits from two or more classes that have a common base class. This can lead to ambiguity and confusion about which parent class's method should be called, and it can also lead to inefficiencies due to duplicated inherited members.
        
        ```cpp
        class Grandparent {
        public:
            void foo() { std::cout << "Grandparent's foo\n"; }
        };
        
        class Parent1 : public Grandparent { };
        
        class Parent2 : public Grandparent { };
        
        class Child : public Parent1, public Parent2 { };
        ```
        
        In this case, if you create an object of type **`Child`** and call **`foo()`**, the compiler will not know whether to call **`Parent1`**'s **`foo()`** or **`Parent2`**'s **`foo()`**. This is the diamond problem.
        
        One solution to the diamond problem is to use virtual inheritance, which ensures that only one copy of the common base class (**`Grandparent`** in this case) is inherited.
        
        ```cpp
        class Grandparent {
        public:
            void foo() { std::cout << "Grandparent's foo\n"; }
        };
        
        class Parent1 : **virtual** public Grandparent { };
        
        class Parent2 : **virtual** public Grandparent { };
        
        class Child : public Parent1, public Parent2 { };
        
        int main() {
            Child c;
            c.foo(); // Outputs: "Grandparent's foo"
            return 0;
        }
        ```
        
    - **What is “name hiding”?**
        
        In multiple inheritance, a derived class inherits members from all of its base classes. If two base classes have members with the same name, then that name will be hidden in the derived class unless it is referred to explicitly.
        
        ```cpp
        class Base1 {
        public:
            void foo() { std::cout << "Base1's foo\n"; }
        };
        
        class Base2 {
        public:
            void foo() { std::cout << "Base2's foo\n"; }
        };
        
        class Derived : public Base1, public Base2 { };
        
        int main() {
            Derived d;
            // d.foo(); // Error: request for member 'foo' is ambiguous
            d.Base1::foo(); // OK: calls Base1's foo
            d.Base2::foo(); // OK: calls Base2's foo
            return 0;
        }
        ```
        
    - **What is “order of initialization”?**
        
        In multiple inheritance, base classes are initialized in the order they are declared in the class definition. This can lead to issues if one base class depends on another being already initialized.
        
        ```cpp
        class Base1 {
        public:
            Base1() { std::cout << "Base1's constructor\n"; }
        };
        
        class Base2 {
        public:
            Base2() { std::cout << "Base2's constructor\n"; }
        };
        
        class Derived : public Base2, public Base1 { };
        
        int main() {
            Derived d;
            // Outputs:
            // Base2's constructor
            // Base1's constructor
            return 0;
        }
        ```
        

### Q: **What are “Is-a” and “Has-a” tests?**

- **A:**
    
    **Is-a Test**: This test is used to verify inheritance relationships between classes. If you can say "Class B is a Class A", then Class B should inherit from Class A. In C++, you can use dynamic_cast or typeid to perform an "is-a" test.
    
    ```cpp
    class Base { /* ... */ };
    class Derived : public Base { /* ... */ };
    
    Base* b_ptr = new Derived;
    Derived* d_ptr = dynamic_cast<Derived*>(b_ptr);
    
    if (d_ptr != nullptr) {
        std::cout << "b_ptr is pointing to a Derived object\n";
    } else {
        std::cout << "b_ptr is not pointing to a Derived object\n";
    }
    ```
    
    **Has-a Test**: This test is used to verify composition relationships between classes. If you can say "Class A has a Class B", then Class A should have a member variable of type Class B. In C++, you can perform a "has-a" test by simply checking if a member function or variable exists.
    
    ```cpp
    class B { /* ... */ };
    
    class A {
    public:
        B b;
        // ...
    };
    
    A a;
    // If this line compiles, then A has a B
    B b = a.b;
    ```