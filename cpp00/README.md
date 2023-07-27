# Classes, member fucntions, and some basic stuff..

## Namespaces
### Q: What are namespaces?

- **A:**
    
    P**rovides a method for preventing name conflicts in large projects**
    
    - …
        - It allows you to group symbols that are related together
        - **Using namespaces**
            - **Namespace declatation:**
                
                ```cpp
                namespace MyNamespace { // Declarations go here }
                ```
                
            - **Accessing Entities:**
                
                ```cpp
                MyNamespace::myFunction();  // Accessing a function in MyNamespace
                ```
                
            - **Using Declarations and Directives:**
                
                ```cpp
                using MyNamespace::myVariable;  // Using a specific variable from MyNamespace
                using namespace MyNamespace;    // Using all entities from MyNamespace
                ```
                
            - **Anonymous Namespace**
                
                ```cpp
                namespace {
                    // Declarations go here
                }
                ```
                
        - **Reasons to use namespace**
            - Avoiding Naming Collisions:
            By encapsulating declarations within namespaces, you can ensure that similarly named entities from different sources do not clash.
            - Organizing Code:
            Namespaces allow you to organize your code into logical units, making it easier to manage and understand. For example, you can have separate namespaces for different components or modules of your program.
            - Third-Party Libraries:
            When using third-party libraries or frameworks, namespaces are often employed to encapsulate their functionality and prevent naming clashes with your own code.
            - Versioning and Extension:
            Namespaces can be used to introduce new versions or extensions to existing code without modifying the original namespace. This allows for backward compatibility and easy migration.

### Q: **What are strems?**

- **A:**
    
    Streams are objects that can be used to read data from and write data to various sources, such as the console, files, and other input/output devices.
    
    - …
        - **Stream Classes:** 
        Streams are implemented using a hierarchy of classes. The two fundamental stream classes are:
            - **`std::istream`:** Used for reading input from a source.
            - **`std::ostream`:** Used for writing output to a destination.
            
            <aside>
            💡 These classes are further derived into more specialized classes, such as **`std::ifstream`** (input file stream) and **`std::ofstream`** (output file stream).
            
            </aside>
            
        - **Stream Objects:**
        Stream objects are instances of the stream classes and are associated with specific sources or destinations. Common stream objects include:
            - **`std::cin`**: Standard input stream for reading from the console.
            - **`std::cout`**: Standard output stream for writing to the console.
            - **`std::ifstream`**: Stream object for reading from a file.
            - **`std::ofstream`**: Stream object for writing to a file.
        - **Stream Extraction and Insertion:**
            - `>>` Extraction operator is used to read data from the stream.
            - `<<` Insertion operator is used to write data to the stream.
        - **Error Handling:**
        Streams have error state flags that indicate the success or failure of input/output operations.
            - **`good()`:** This member function is used to check if the stream is in a good state, meaning no error has occurred. It returns **`true`** if the stream is good, and **`false`** otherwise. Example:
                
                ```cpp
                std::ifstream file("data.txt");
                if (file.good()) {
                    // Stream is in a good state
                }
                ```
                
            - **`fail()`:** This member function is used to check if a failure has occurred during the last input or output operation. It returns **`true`** if a failure has occurred, and **`false`** otherwise.
                
                ```cpp
                int num;
                std::cin >> num;
                if (std::cin.fail()) {
                    // Failed to read an integer from input
                }
                ```
                
            - **`eof()`:** This member function is used to check if the end-of-file (EOF) has been reached during input operations. It returns **`true`** if the EOF has been reached, and **`false`** otherwise.
                
                ```cpp
                std::ifstream file("data.txt");
                int num;
                while (!file.eof()) {
                    file >> num;
                    // Process the read numbers
                }
                ```
                
            - **`bad()`:** This member function is used to check if a non-recoverable error has occurred during the last operation on the stream. It returns **`true`** if a non-recoverable error has occurred, and **`false`** otherwise.
                
                ```cpp
                std::ofstream file("output.txt");
                if (file.bad()) {
                    // Failed to open the file for writing
                }
                ```
                
        - **Stream Manipulators:**
            - **`std::endl`:** This manipulator is used to insert a newline character (**`'\n'`**) into the output stream and flush the stream's buffer.
            - **`std::setw`:** This manipulator is used to set the field width for the next output value. It ensures that the output is padded with spaces to match the specified width.
        - **Stream Member Functions:**
            - **`ignore`:** This member function is used to discard characters from the input stream. It can be used to skip over a certain number of characters or until a specific delimiter is encountered.
                
                ```cpp
                std::cin.ignore(100, '\n');  // Ignore up to 100 characters or until a newline is encountered
                ```
                
            - **`peek`:** This member function is used to peek at the next character in the input stream without extracting it. It allows you to check the upcoming character without consuming it.
                
                ```cpp
                char nextChar = std::cin.peek();  // Peek at the next character in the input stream
                ```
                
            - **`putback`:** This member function is used to put a character back into the input stream. It is typically used after peeking at a character to return it to the stream.
                
                ```cpp
                char nextChar = std::cin.get();   // Read the next character from the input stream
                std::cin.putback(nextChar);       // Put the character back into the input stream
                ```
                
            - **`seekg` and `seekp`:** These member functions are used to set the position of the input and output stream pointers, respectively. They allow you to move to a specific position within the stream.
                
                ```cpp
                std::ifstream file("data.txt");     // Open a file for reading
                file.seekg(10);                     // Move the input stream position to the 10th character
                ```
                
        

### Q: **What are classes and instances?**

- **A:**
    
    **A class is a blueprint that defines the structure and behavior of objects, while an instance is a specific realization of that class with its own unique identity, attributes, and behavior.**
    
    **Classes:**
    In OOP, a class is a blueprint or a template that defines the characteristics (attributes) and behaviors (methods) of a particular type of object. It serves as a blueprint for creating instances of that class. A class defines the common structure and behavior that its instances will possess.
    
    - …
        - **Attributes:**
        Also known as member variables or data members, attributes represent the properties or characteristics of objects in the class. They define the state of the objects. For example, a `Person` class may have attributes like `name`, `age`, and `gender`.
        - **Methods:**
        Also known as member functions, methods define the behaviors and actions that objects of the class can perform. They encapsulate the logic and operations associated with the class. For example, a `Person` class may have methods like `sayHello()` or `calculateAge()`.
        - **Encapsulation:**
        Classes provide encapsulation, which means that the attributes and methods are bundled together within the class, making them accessible only to the class and its instances. This allows for data hiding and separation of concerns.
        - **Inheritance:**
        Classes can participate in inheritance, where one class can derive properties and behaviors from another class. This promotes code reuse and facilitates the creation of specialized classes based on existing ones.
        - C**lass vs struct:**
            - A class can also contain functions (called `methods` in C++). The member attributes and methods are hidden from the outside world, unless their declaration follows a public label
            - Special methods (`constructor` and `destructor`) in C++. They run automatically when an object (an instance of the class) is created and destroyed
            - Operators to work on the new data type can be defined using special methods (`member functions`)
            - One class can be used as the basis for the definition of another (`inheritance`)
            - Declaring a variable of the new type (an object) requires just the name of the class. The keyword `class` is not required
            - `struct` and `class` work almost the same way in C++. The difference is that the default accessibility / scope of member variables and methods is `private` in a class, while it's `public` in a struct. The use of `class` is generally preferred
    
    **Instances:**
    An instance, also referred to as an object, is a specific occurrence or realization of a class. It is created using the blueprint provided by the class. Each instance of a class has its own set of attributes and can execute the methods defined in the class.
    
    - …
        - **Creation:**
        To create an instance of a class, you use a process called instantiation. This involves allocating memory for the instance and initializing its attributes. For example, you might create a `Person` instance with the name "John" and age 30.
        - **Unique Identity:**
        Each instance of a class has a unique identity, allowing you to distinguish one object from another. You can have multiple instances of the same class, each with its own attribute values.
        - **Accessing Attributes and Methods:**
        Once an instance is created, you can access its attributes and invoke its methods using the dot notation. For example, if you have a **`Person`** instance called **`person1`**, you can access its **`name`** attribute as **`person1.name`** and invoke its methods like **`person1.sayHello()`**.
            
            <aside>
            💡 **When to use Pointer to Object (Arrow Operator) `->` instead of the (Direct Object Access) dot (`.`)?**
            The **`->`** operator is used in C++ when working with pointers to objects to access attributes and invoke methods. It is used specifically when accessing attributes and methods through a pointer to an object instead of directly with the object itself. (object should be dynamicly allocated)
            
            </aside>
            
        - **State and Behavior:**
        Instances have their own state, represented by the values of their attributes. They can exhibit behavior by executing the methods defined in the class.

### Q: **What are constructors and destructors?**

- **A:**
    
    **A constructor:**
    Is a special member function of a class that is automatically called when an instance (object) of the class is created.
    
    - …
        - **Initialization:** 
        Constructors initialize the attributes of an object to specific values when the object is created. They ensure that the object is in a valid state right from the start.
        - **Name and Syntax:**
        Constructors have the same name as the class and do not have a return type, not even **`void`**. They are defined within the class declaration and are typically implemented in the class definition.
        - **Overloading:**
        Constructors can be overloaded, which means you can define multiple constructors with different parameter lists. This allows for object creation with different initialization options.
        - **Default Constructor:**
        If no constructors are explicitly defined, C++ provides a default constructor that takes no arguments. It initializes the object with default values (e.g., zero or null).
        - **Copy Constructor:**
        A copy constructor is a constructor that creates an object by copying the values of another object of the same class. It is used when a new object needs to be created as a copy of an existing object.
    
    **A destructor:**
    Is another special member function of a class that is automatically called when an object goes out of scope or is explicitly destroyed. Its purpose is to release resources, perform cleanup operations, or deallocate memory associated with the object.
    
    - …
        - **Cleanup Operations:** 
        Destructors are responsible for performing cleanup tasks, such as releasing dynamically allocated memory, closing files, or releasing other resources acquired by the object during its lifetime.
        - **Name and Syntax:**
        Destructors have the same name as the class, preceded by a tilde (**`~`**). They do not have any return type, including **`void`**. Like constructors, they are defined within the class declaration and are typically implemented in the class definition.
        - **Order of Execution:**
        Destructors are called automatically in reverse order of object creation when objects go out of scope or are explicitly destroyed. This ensures proper cleanup and resource deallocation.

### Q: **What are member attributes & functions?**

- **A:**
    
    Member functions are integral parts of a class, defining its data and behavior.
    
    - **Member Functions (Methods):**
        - **Non-Static vs Static Member Functions**
            - **Non-Static Member Functions:**
            Non-static member functions are associated with individual objects (instances) of a class. They have access to the member attributes and other member functions of the class through the **`this`** pointer. They operate on object-specific data and behavior.
                
                ```cpp
                class Circle {
                private:
                    double radius;
                
                public:
                    void setRadius(double r) {
                        radius = r;
                    }
                
                    double getArea() const {
                        return 3.14159 * radius * radius;
                    }
                };
                
                int main() {
                    Circle myCircle;
                    myCircle.setRadius(5.0);
                    double area = myCircle.getArea();
                    // 'area' will be 78.53975
                }
                ```
                
            - **Static Member Functions:**
            Static member functions are associated with the class as a whole, rather than individual objects. They operate on class-level data and behavior. Static member functions do not have access to non-static member attributes or functions, as they are independent of object instances.
                - A static method is called without a class instance and it `doesn't have access to a class instance`
                - Within static methods, you `can't refer to a class instance`, since you don't have that class instance to refer to
                - A static methods `can not access non static variables`, because a static method does not have a class instance
                - In comparison, every non-static method inside a class always gets an instance of the current class as a parameter (`this->`). Classes are functions with a hidden parameter. A static method does not get that parameter
            
            ```cpp
            class MathUtils {
            public:
                static int max(int a, int b) {
                    return (a > b) ? a : b;
                }
            };
            
            int main() {
                int maxValue = MathUtils::max(10, 20);
                // 'maxValue' will be 20
            }
            ```
            
            - **Comparison:**
                1. **Access to Data:** Non-static member functions can access non-static member attributes and other member functions using the **`this`** pointer, while static member functions cannot directly access non-static member attributes or functions.
                2. **Invocation:** Non-static member functions are called on specific object instances, while static member functions are called using the class name.
                3. **Associated Data:** Non-static member functions operate on object-specific data, while static member functions operate on class-level data that is shared among all objects.
                4. **Use Cases:** Non-static member functions are useful for operations specific to individual objects, whereas static member functions are useful for utility functions or operations that do not rely on specific object instances.
        - **Declaration and Definition:** 
        Member functions are declared within the class declaration and defined outside the class using the scope resolution operator (**`::`**).
        - **Access Modifiers:** 
        Like member attributes, member functions can also have different access modifiers (**`public`**, **`private`**, or **`protected`**). The access specifier determines whether the member function can be accessed from outside the class.
        - **Object Interaction:** 
        Member functions can access and manipulate the member attributes of an object. They can perform operations, modify attribute values, and provide interfaces for interacting with the object's data.
        - **This Pointer:** 
        Inside a member function, the **`this`** pointer is implicitly available. It points to the object that invoked the member function, allowing access to its attributes and enabling object-specific operations.
            - **Implicit Availability:** The **`this`** pointer is implicitly available in non-static member functions of a class. It is automatically created when a member function is called, and you can use it without explicitly declaring or initializing it.
            - **Pointer to Current Object:** The **`this`** pointer holds the memory address of the current object, allowing direct access to the object's attributes and member functions. It provides a way to distinguish the current object from other objects of the same class.
            - **Use Cases:**
                - Accessing Member Attributes: You can use the **`this`** pointer to access member attributes within a member function. It is particularly useful when there is a naming conflict between a member attribute and a function parameter or local variable. Using **`this->attribute`** explicitly refers to the member attribute.
                - Returning the Current Object: Member functions can return the current object using the **`this`** pointer. This allows method chaining, where multiple member function calls can be chained together in a single statement.
                - Passing the Current Object: The **`this`** pointer can be passed as an argument to other member functions or external functions that expect a pointer to the current object.
                
                ```cpp
                class MyClass {
                private:
                    int myAttribute;
                
                public:
                    void setAttribute(int value) {
                        this->myAttribute = value;   // Accessing member attribute using 'this' pointer
                    }
                
                    void printAttribute() {
                        std::cout << "Attribute: " << this->myAttribute << std::endl;  // Printing member attribute
                    }
                
                    MyClass* getThis() {
                        return this;   // Returning the current object
                    }
                };
                ```
                
            
    - **Member Attributes (Variables):**
        - There will only be `one instance of that variable`, no mater how many objects you've instantiated. If one instance changes the variable, the change will be reflected on all instances
        - Therefore, it does not make sense to refer to the attributes inside an instance, but rather by `className::attributeName`
        - It is still different from a global variable because this static attribute is still inside a class
        - **Declaration:** 
        Member attributes are declared within the class declaration, typically at the top, following the access specifier (**`public`**, **`private`**, or **`protected`**).
            
            ```cpp
            class MyClass {
            private:
                int myInt;          // Member attribute declaration
                double myDouble;    // Another member attribute declaration
            
            public:
                // Member functions go here
            };
            ```
            
        - **Access Modifiers:** 
        Member attributes can be declared with different access modifiers (**`public`**, **`private`**, or **`protected`**) to control their accessibility from outside the class. By default, member attributes are **`private`**, meaning they can only be accessed within the class.
        - **Instance-Specific Data:** 
        Each object (instance) of the class has its own set of attribute values. Modifying an attribute of one object does not affect the attribute values of other objects.
        - **Initialization:**
        Member attributes can be initialized using constructors or through direct assignment within member functions.
        - **Encapsulation:** 
        Member attributes are typically encapsulated (made **`private`** or **`protected`**) to enforce data encapsulation and to control access to them via member functions.

### Q: **What is initialization list?**

- **A:**
    
    An initialization list is used to initialize the data members of a class within the constructor. It allows you to specify the initial values of the class's attributes before the body of the constructor executes. The initialization list is specified after the constructor's parameter list, using a colon (**`:`**) followed by a comma-separated list of member-initializer pairs. Each member initializer consists of the member name followed by the value to initialize it with.
    
    - …
        - **Efficiency:** 
        Initialization list allows direct initialization of member attributes, avoiding the need for default initialization followed by assignment within the constructor body. This can be more efficient and avoids unnecessary temporary objects.
        - **Initialization Order:** 
        The initialization list allows you to control the order of initialization for the members. The order of the members in the initialization list determines the order in which they are initialized, regardless of their order in the class declaration.
        - **Initialization of `const` and reference members:** 
        Initialization list is necessary to initialize **`const`** and reference member attributes, as they cannot be assigned a value after their initialization.
        - **Initialization of base class and virtual base class:** 
        Initialization list is used to initialize base class and virtual base class attributes before entering the constructor body.

### Q: **What is `const` keyword?**

- **A:**
    
    This keyword can be used in classes to specify that a member variable or member function should not modify the object's state
    
    - …
        - **Member Variables:** 
        When a member variable is declared as **`const`**, it means that its value cannot be modified once it is initialized. **`const`** member variables must be initialized in the constructor initialization list since they cannot be assigned a value inside the constructor body. **`const`** member variables are useful when you want to ensure that certain data remains constant throughout the object's lifetime.
        - **Member Functions:** 
        When a member function is declared as **`const`**, it promises not to modify the object's state. This allows the member function to be safely called on **`const`** objects. **`const`** member functions are particularly useful when you want to provide read-only access to the object's data.
            - **Copy Constructor Behavior:** 
            When a class has **`const`** data members, the default copy constructor generated by the compiler performs a member-wise copy of all the data members. This ensures that the **`const`** data members in the original object are also **`const`** in the copied object. It acts as a form of copy constructor for the **`const`** data members.

### Q: **What are access modifiers?**

- **A:**
    
    Access modifiers, specifically **`public`** and **`private`**, are used in C++ to control the visibility and accessibility of class members (attributes and member functions) from inside and outside the class. They play a crucial role in encapsulation, allowing you to determine what should be accessible to users of the class and what should be hidden as implementation details.
    
    - …
        - **Public Access Modifier:**
            - Attributes and functions declared as **`public`** are accessible from both inside and outside the class.
            - Public attributes can be accessed, modified, or assigned values directly from outside the class.
            - Public member functions can be called on class objects from outside the class to perform specific operations or retrieve information.
            - The public interface of a class represents the contract or API exposed to users, defining how they interact with the class.
                
                ```cpp
                class MyClass {
                public:
                    int publicAttribute;
                };
                
                int main() {
                    MyClass obj;
                    obj.publicAttribute = 42;  // Accessing and assigning a value to the public attribute
                    
                    int value = obj.publicAttribute;  // Accessing the value of the public attribute
                    
                    // Using a pointer/reference to access the public attribute
                    MyClass* pObj = &obj;
                    pObj->publicAttribute = 100;  // Accessing and assigning a value using the pointer
                    
                    return 0;
                }
                ```
                
        - **Private Access Modifier:**
            - Attributes and functions declared as **`private`** are only accessible from inside the class.
            - Private attributes cannot be accessed or modified directly from outside the class. Attempting to do so will result in a compilation error.
            - Private member functions can only be called from within the class. They are typically used for internal operations, computations, or helper functions that are not meant to be exposed or accessed directly by users.
            
            ```cpp
            class MyClass {
            private:
                int privateAttribute;
            
            public:
                void setPrivateAttribute(int value) {
                    privateAttribute = value;
                }
            
                int getPrivateAttribute() const {
                    return privateAttribute;
                }
            };
            
            int main() {
                MyClass obj;
                obj.setPrivateAttribute(42);  // Accessing the private attribute indirectly through a public member function
            
                int value = obj.getPrivateAttribute();  // Accessing the private attribute indirectly through a public member function
            
                return 0;
            }
            ```
            
        - **Protected Acces Modifier:**
            - **Inheritance and Derived Classes:**
            Protected members of a class are accessible to the derived classes. Derived classes can access and modify the protected members directly as if they were public members. This enables the derived classes to reuse and extend the functionality of the base class. Default class inharitance is private therefore you need to use public inheritance in order to keep the access for derived class.
            - **Encapsulation within the Class Hierarchy:**
            Protected members are encapsulated within the class hierarchy. They are not accessible from outside the class or unrelated classes, maintaining data encapsulation and information hiding. Only the base class and its derived classes have access to protected members.
            - **Restricted Access from Outside the Class Hierarchy:**
            Protected members cannot be accessed or modified directly from outside the class hierarchy (i.e., outside the base class or its derived classes). Attempting to do so will result in a compilation error.
            - **Public Interface:**
            Public member functions of the base class can provide controlled access to the protected members, enabling users to interact with the class through a well-defined interface. Users of the class can access the protected members indirectly through the public member functions.
            
            ```cpp
            class Base {
            protected:
                int protectedAttribute;
            
            public:
                void setProtectedAttribute(int value) {
                    protectedAttribute = value;
                }
            
                int getProtectedAttribute() const {
                    return protectedAttribute;
                }
            };
            
            class Derived : public Base {
            public:
                void modifyProtectedAttribute(int value) {
                    protectedAttribute = value;  // Accessing the protected member directly in the derived class
                }
            };
            
            int main() {
                Base baseObj;
                baseObj.setProtectedAttribute(42);  // Accessing the protected attribute through a public member function
            
                Derived derivedObj;
                derivedObj.modifyProtectedAttribute(100);  // Accessing the protected attribute in the derived class
            
                return 0;
            }
            ```
            

### Q: **What are accessors(getters) and mutators(setters)?**

- **A:**
    - …
        - Accessors, or getter methods, are used to retrieve the values of private or protected attributes from a class. They provide read-only access to the attributes and do not modify the state of the object. Accessors typically have a return type that matches the attribute they retrieve.
        - Setters, or setter methods, are used to modify the values of private or protected attributes within a class. They provide a controlled way to update the attribute values, often performing validation or enforcing specific constraints before allowing the change.

### Q: **What is structural vs. physical comparison?**

- **A:**
    
    Structural comparison focuses on the content or structure of objects or values, determining equality based on their internal state, while physical comparison focuses on the physical identity or memory location, determining equality based on whether they refer to the same memory location.
    
    - …
        
        **Structural Comparison Example:**
        
        ```cpp
        #include <iostream>
        #include <string>
        
        int main() {
            std::string str1 = "Hello";
            std::string str2 = "Hello";
            std::string str3 = "World";
        
            if (str1 == str2) {
                std::cout << "str1 and str2 are equal." << std::endl;
            } else {
                std::cout << "str1 and str2 are not equal." << std::endl;
            }
        
            if (str1 == str3) {
                std::cout << "str1 and str3 are equal." << std::endl;
            } else {
                std::cout << "str1 and str3 are not equal." << std::endl;
            }
        
            return 0;
        }
        ```
        
        **Physical Comparison Example:**
        
        ```cpp
        #include <iostream>
        
        int main() {
            int num1 = 42;
            int num2 = 42;
            int* ptr1 = &num1;
            int* ptr2 = &num2;
        
            if (ptr1 == ptr2) {
                std::cout << "ptr1 and ptr2 are physically equal." << std::endl;
            } else {
                std::cout << "ptr1 and ptr2 are not physically equal." << std::endl;
            }
        
            return 0;
        }
        ```
        

### Q: **What are non-member attributes and functions?**

- **A:**
    
    They are declared outside of any class and can be accessed globally throughout the program without the need for an object or instance of a class. Non-member attributes and functions are sometimes referred to as global variables and functions.
    
    - …
        - **Member** **attributes and functions:** 
        Are present inside a class and are associated with individual instances of that class. They are accessed through an instance of the class or an object, and each instance of the class has its own set of member attributes. Member attributes store data specific to each instance, while member functions operate on that instance's data.
            - Terminology: Instance variables/Instance functions are alternative terms that refer to member attributes/functions.
        - **Non-Member Attributes:**
            
            ```cpp
            #include <iostream>
            
            int globalVariable;  // Non-member attribute
            
            int main() {
                globalVariable = 42;  // Accessing and modifying the global variable
                std::cout << globalVariable << std::endl;  // Output: 42
            
                return 0;
            }
            ```
            
        - **Non-Member Functions:**
            
            ```cpp
            #include <iostream>
            
            void globalFunction() {
                std::cout << "Hello from global function!" << std::endl;
            }
            
            int main() {
                globalFunction();  // Calling the global function
            
                return 0;
            }
            ```
            

### Q: **What are pointers to members, how to use them?**

- **A:**
    
    Pointers to members in C++ are used to refer to members (attributes or functions) of a class. They allow you to store the address of a member and later use the pointer to access or invoke that member. Pointers to members are useful when you need to dynamically select or invoke members based on certain conditions or at runtime.
    
    - …
        - **Pointers to Data Members:**
            - Pointers to data members store the memory address of a data member within a class.
            - They are declared with the syntax: **`data_type Class::*pointer_name;`**
            - To access the member via the pointer, you need an object or instance of the class.
            - Use the **`.*`** or **`>*`** operator to access the member through the pointer.
        - **Pointers to Member Functions:**
            - Pointers to member functions store the memory address of a member function within a class.
            - They are declared with the syntax: **`return_type (Class::*pointer_name)(parameters);`**
            - To invoke the member function via the pointer, you need an object or instance of the class.
            - Use the **`.*`** or **`>*`** operator to invoke the member function through the pointer.
        
        ```cpp
        #include <iostream>
        #include "Sample.class.hpp"
        
        int main(void)
        {
            // allocated on the stack
            Sample instance;
            // declared a pointer to the address of instance,
            // which is stored in a variable (instancep)
            Sample *instancep = &instance;
        
            // declaring a pointer on an integer attribute of a Sample class
            int Sample::*p = NULL;
            // declaring a pointer on a const member function of a Sample class
            void (Sample::*f)(void) const;
        
            p = &Sample::foo; // this is not specific about which instance that p refers to
        
            std::cout << "Value of member foo = " << instance.foo << std::endl;
            // .* operator to specify the instance that p refers to
            instance.*p = 21; // directly using the instance
            std::cout << "Value of member foo = " << instance.foo << std::endl;
            instancep->*p = 42; // pointer to an instance
            std::cout << "Value of member foo = " << instance.foo << std::endl;
        
            f = &Sample::bar; // can't tell which instance that it's referring to
        
            (instance.*f)(); // use .* operator to specify the instance
            (instancep->*f)(); // or use ->* a pointer to refer to the instance
        
            return 0;
        }
        ```
        

### Q: **How does C++ strings works?**

- **A:**
    - …
        - **`str.length()`:**
        Function returns the number of characters in a string. It can be used to determine the length of the string dynamically.
        - **`str[]`:**
        The square brackets **`[]`** can be used to access individual characters within a string. However, it doesn't perform range-checking. It's important to ensure that the index used is within the valid range of the string.
        - **`str.at(int index)`:**
        The **`at()`** function allows retrieving the character at a specified position in the string with built-in range-checking. If the index is out of bounds, it throws an exception (**`std::out_of_range`**).
        - **`==` / `!=`:**
        The equality operators **`==`** and **`!=`** can be used to compare two strings for equality. They return **`true`** if the strings are equal and **`false`** otherwise.
        - **`s1 + s2` / `+=`:**
        The **`+`** operator and **`+=`** operator can be used to concatenate two strings (**`s1 + s2`**) or append another string or a single character to the end of a string (**`s1 += s2`** or **`s1 += 'c'`**).
        - **`str.find(key)` / `str.find(key, n)`:**
        The **`find()`** member function allows searching within a string for a particular string or character specified by **`key`**. It returns the position of the first occurrence of **`key`** within the string. An optional second parameter **`n`** can be used to specify the starting position of the search.
        - **`str.substr(start, length)`:**
        The **`substr()`** member function is used to extract substrings from a larger string. It creates a new string that contains a copy of the characters specified by the starting position **`start`** and the length **`length`** from the original string. The receiver string remains unchanged.
        - **`str1.insert(start, str2)` / `str1.replace(start, length, str2)`:**
        The **`insert()`** and **`replace()`** member functions allow modifying a string by inserting or replacing portions of it. **`insert()`** inserts the characters of **`str2`** at the specified position **`start`** in **`str1`**, while **`replace()`** replaces the characters in **`str1`** starting at position **`start`** with the characters of **`str2`**. These functions modify the receiver string.
        - **C-style string:**
        While C++ strings offer more functionality and are generally preferred, C-style strings (char*) can coexist in a program. However, C++ strings are recommended due to their richer set of operations and better error handling. In certain cases, such as working with file streams, C-style strings may still be used.
        - **Parameter Passing:**
        When passing a **`std::string`** as a parameter, it's important to consider the most efficient way. If the string is not going to be modified within the function, it is recommended to pass it as a **`const<int>&<foo>`** (const reference) to avoid unnecessary copying.

### Q: **What is the difference between `std::cin` and `getline()`?**

- **A:**
    - `std::cin >> string`
        - Each extracted character is appended to the string
        - The extraction operations use whitespaces as separators. Therefore, this operation will only extract what can be considered as a word from the stream
    - `getline`
        - To extract entire lines of text
        - The extraction stops until the delimitation character, or the end of file is reached, or some other error occurs during the input operation