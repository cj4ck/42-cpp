# Subtype polymorphism, abstract classes, interfaces
### Q: **What is subtyping polimorphism?**

- **A:**
    - Form of polymorphism where a subclass can be substituted in any situation where a parent class is expected, meaning that methods defined in the base class can be overridden by methods in the derived class, allowing for different behaviors while maintaining the same instance.
    
    A virtual function is a member function in the base class that you redefine in a derived class. It is declared using the keyword **`virtual`** in the base class, and can be redefined in any derived class. The decision on which function version to use (base vs derived) is made dynamically at runtime based on the actual type of the object, not its static type. 
    
    ```cpp
    #include <iostream>
    class Base {
    public:
        Base() { std::cout << "Base Constructor" << std::endl; }
    	virtual ~Base() { std::cout << "Base Destructor" << std::endl; }  // Destructor should be virtual for dynamic memory allocation
        virtual void foo() {
            std::cout << "Base::foo()" << std::endl;
        }
    	void	helo() { std::cout << "hello_test" << std::endl; }
    };
    
    class Derived : public Base {
    public:
        void foo() {
            std::cout << "Derived::foo()" << std::endl;
        }
        Derived() { std::cout << "Derived Constructor" << std::endl; }
        ~Derived() { std::cout << "Derived Destructor" << std::endl; }  // This will be called correctly now
    };
    
    int main() {
        Base* a = new Derived();
        Derived b;
    	a->foo();  // Outputs: "Base::foo()"
    	b.foo();
    	delete a;
        return 0;
    }
    ```
    

### Q: **What is pure virtual function?**

- **A:**
    
    A pure virtual function is a function declared in a base class that has no definition relative to the base. A pure virtual function is declared by assigning 0 in the declaration. For example: **`virtual void function() = 0;`**. Any class that contains a pure virtual function is considered an abstract class. Subclasses of an abstract class must provide definitions for the pure virtual function, otherwise, they too will become abstract classes.
    

### Q: **What is an abstract class?**

- **A:**
    
    Class that has at least one `pure virtual function`.
    
    Abstract classes and interfaces allow you to program at a more general level, making your code more flexible and adaptable to future changes.
    
    A class with only pure virtual functions can act as an interface. In this case, the interface sets up a kind of contract for the classes that implement it, enforcing them to provide certain functionality, but allowing them to do so in their own way.
    
    ### **Abstract classes cannot be instantiated**
    
    - Abstract classes are meant to be inherited and provide a blueprint for derived classes. They cannot be instantiated themselves.
    
    ### **Derived classes must implement all pure virtual functions**
    
    - Any class that inherits from an abstract class must implement all of its pure virtual functions. If it doesn't, then the derived class is also considered abstract.
    
    ### **Abstract classes can have constructors, non-virtual functions data members.**
    
    - Even though you can't instantiate an abstract class, it can still have constructors and non-virtual functions. These can be used by derived classes.
    
    ### The destructor of a virtual class has to be virtual, otherwise the destructor of derived class won't be called, which leads to resource leaks.
    
    - Always add virtual to a destructor while creating an abstract class
    - `coding example`
        
        ```cpp
        #include <iostream>
        
        // Abstract base class
        class Shape {
        public:
            virtual float area() = 0; // Pure virtual function
            virtual float perimeter() = 0; // Pure virtual function
        };
        
        // Derived class: Circle
        class Circle : public Shape {
        private:
            float radius;
        public:
            Circle(float r) : radius(r) {}
        
            float area() override {
                return 3.14159 * radius * radius;
            }
        
            float perimeter() override {
                return 2 * 3.14159 * radius;
            }
        };
        
        // Derived class: Rectangle
        class Rectangle : public Shape {
        private:
            float width, height;
        public:
            Rectangle(float w, float h) : width(w), height(h) {}
        
            float area() override {
                return width * height;
            }
        
            float perimeter() override {
                return 2 * (width + height);
            }
        };
        
        int main() {
            Circle c(5);
            std::cout << "Circle area: " << c.area() << ", perimeter: " << c.perimeter() << std::endl;
        
            Rectangle r(4, 5);
            std::cout << "Rectangle area: " << r.area() << ", perimeter: " << r.perimeter() << std::endl;
        
            return 0;
        }
        ```
        

### Q: **What is virtual destructor?**

- **A:**
    
    We use a virtual destructor in a base class when we want to ensure that the correct derived class's destructor is called when an object is deleted **through a pointer-to-base-class**.
    
    ```cpp
    class Base {
    public:
        Base() { }
        virtual ~Base() { }  // Virtual destructor
    };
    
    class Derived : public Base {
    public:
        Derived() { }
        ~Derived() { }
    };
    
    int main() {
        Base* base = new Derived();
        delete base;  // This will correctly call Derived's destructor because Base's destructor is virtual
        return 0;
    }
    ```
    

### Q: **What are types of polimorphyzm?**

- **A:**
    1. **Compile-time polymorphism (early binding / static polymorphism)**: This type of polymorphism is resolved during compile time. The decision about which function to call is made when the code is compiled. The two main ways this is achieved in C++ are through function overloading and operator overloading.
        - **Function Overloading**: This occurs when multiple functions have the same name but different parameters (either different number of parameters, or different types of parameters). The compiler determines the correct function to call based on the function arguments.
        - **Operator Overloading**: This allows operators to be redefined and used where one or both of the operands are of a user-defined class. This is resolved at compile time.
    2. **Runtime polymorphism (late binding / dynamic polymorphism)**: This type of polymorphism is resolved during runtime. The decision about which function to call is made at runtime. This is achieved in C++ through virtual functions and inheritance.
        - **Virtual Functions**: A virtual function is a function in a base class that is declared using the keyword virtual. Defining in a base class a virtual function, with another version in a derived class, signals to the compiler that we don't want static linkage for this function.
        - **Inheritance**: It's a mechanism where you can to derive a class from another class for a hierarchy of classes that share a set of attributes and behaviors. The class being inherited from is called the parent or base class, and the class inheriting is called the child or derived class.

### Q: **Shallow vs Deep copy?**

- **A:**
    
    **Shallow Copy**: A shallow copy of an object is a bit-wise copy of an object's fields. **For fields that are pointers, this means the addresses are copied, not the objects they point to.** **If the original object and its copy share a pointer to the same memory location, changes made to the memory through one object will affect the other.** This is usually not what you want, especially when the objects are destroyed and their destructors free the same memory, leading to undefined behavior and memory leaks. 
    
    In a shallow copy, the data members are copied directly from one object to another. If the data members are simple types like int, char, float, etc., this works fine. **But if the data members include pointers, then only the addresses are copied, not the objects they point to. This can lead to problems, especially when the objects are destroyed and their destructors free the same memory.**
    
    - `coding example`
        
        ```cpp
        #include <iostream>
        
        class ShallowCopy {
        public:
            int* data;
            ShallowCopy(int val) {
                data = new int;
                *data = val;
                std::cout << "  \033[1;32m Shallow constructor called\033[0m" << std::endl;
            }
            ShallowCopy(const ShallowCopy& source) {
                data = source.data;
                std::cout << "  \033[38;5;123m Shallow copy constructor called\033[0m" << std::endl;
            }
            ~ShallowCopy() {
                std::cout << "  \033[38;5;160m Shallow destrucotr called\033[0m" << std::endl;
                delete data;
            }
        };
        
        class DeepCopy {
        public:
            int* data;
            DeepCopy(int val) {
                std::cout << "  \033[1;32m Deep constructor called\033[0m" << std::endl;
                data = new int;
                *data = val;
            }
            DeepCopy(const DeepCopy& source) {
                std::cout << "  \033[38;5;123m Deep copy constructor called\033[0m" << std::endl;
                data = new int;
                *data = *source.data;
            }
            ~DeepCopy() {
                std::cout << "  \033[38;5;160m Deep destrucotr called\033[0m" << std::endl;
                delete data;
            }
        };
        
        int main() {
            {
                std::cout << "\033[45m" << "Deep copy example:" << "\033[0m" << std::endl;
                DeepCopy obj1(10);
                DeepCopy obj2 = obj1;
                std::cout << "\t> Before modification, obj1 data: " << *obj1.data << ", obj2 data: " << *obj2.data << std::endl;
                *obj1.data = 20;
                std::cout << "\t> After modification, obj1 data: " << *obj1.data << ", obj2 data: " << *obj2.data << std::endl;
            }
            {
                std::cout << "\033[45m" << "Shallow copy example:" << "\033[0m"<< std::endl;
                ShallowCopy obj1(10);
                ShallowCopy obj2 = obj1;
                std::cout << "\t> Before modification, obj1 data: " << *obj1.data << ", obj2 data: " << *obj2.data << std::endl;
                *obj1.data = 20;
                std::cout << "\t> After modification, obj1 data: " << *obj1.data << ", obj2 data: " << *obj2.data << std::endl ;
        		//!now the destructor is called and it is leaking beacue pointer is being freed twice cuz they share it.
            }
            return 0;
        }
        ```
        
        Destructor is called twice for shallow copy object and because of that it tries to free same pointer twice