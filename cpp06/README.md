# Repetition and Exceptions
### Q: **What are templates in cpp?**

- **A:**
    
    Templates allow functions and classes to operate with generic types. This means you can write one function or class that works with many different data types. The compiler generates the appropriate function or class definition at compile time based on the data type used. Templates are a form of compile-time polymorphism.
    

### Q: **What are exceptions in cpp and how to handle them?**

- **A:**
    - **Throwing an Exception**: Exceptions are thrown when an error or other condition that the programmer has decided is exceptional occurs. This is done using the **`throw`** keyword. For example, **`throw "Division by zero condition!";`**
    - **Catching an Exception**: When an exception is thrown, it propagates up the call stack until it is caught by an exception handler. If it is not caught, the program will terminate. Exceptions are caught in a **`try/catch`** block. The **`try`** block contains the code that might throw an exception, and the **`catch`** block contains the code to execute if an exception is thrown.
    - You can program exception handling by **struct**:
        
        ```
        struct GradeTooHighException : public std::exception {
        		virtual const char* what() const _NOEXCEPT;
        	};
        
        	struct GradeTooLowException : public std::exception {
        		virtual const char* what() const _NOEXCEPT; 
        	};
        ```
        
    - You can also do it by creating a class if you would like to use it more widely
        
        ```cpp
        #include <exception>
        #include <iostream>
        
        class MyException : public std::exception {
        public:
            virtual const char* what() const throw() {
                return "MyException occurred";
            }
        };
        
        int main() {
            try {
                throw MyException();
            } catch(const MyException& e) {
                std::cout << e.what() << std::endl;
            }
            return 0;
        }
        ```
        
    - `code example`
        
        ```cpp
        try {
            // code that might throw an exception
        } catch (const char* e) {
            // code to execute if an exception of type const char* is thrown
            std::cerr << "Caught exception: " << e << std::endl;
        } catch (...) {
            // code to execute if an exception of any other type is thrown
            std::cerr << "Caught unknown exception" << std::endl;
        }
        ```
        

### Q: **What is `what()` method?**

- **A:**
    
    The **`what()`** method is a public method of the **`std::exception`** class. It returns a null-terminated character sequence (a C-string) that can be used to describe the exception. By default, it returns an implementation-defined string. A derived class can override this function to provide more information about the exception. When you catch an exception, you can call **`what()`** to get a string that describes the exception.
    
    ```cpp
    try {
        // code here
        throw MyException();
    }
    catch (MyException& e) {
        std::cout << e.what() << std::endl;
    }
    ```