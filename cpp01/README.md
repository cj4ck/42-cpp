# New, pointers to members, references, switch statement
### Q: **How to use `new` and `delete`?**

- **A:**
    - `malloc()` an object does not work in C++, because it does not call the constructor of the object. Similarly, if you `free()` an object, it also won't call the destructor
    - `new()` and `delete()` use `malloc()` and `free()` in reality, but they also call the constructor and destructor in an appropriate way
    - `new()` does not take parameters. So need to think of ways to initialise values
    - …
        
        ```cpp
        #include <string>
        #include <iostream>
        
        class Student
        {
        	private:
        		std::string _login;
        
        	public:
        		Student(std::string login) :_login(login)
        		{
        			std::cout << "Student " << this->_login << " is born" << std::endl;
        		}
        
        		~Student()
        		{
        			std::cout << "Student " << this->_login << " died" << std::endl;
        		}
        };
        
        int main()
        {
        	Student		bob = Student("bfubar");
        	Student*	jim = new Student("jfubar");
        
        	// Do some stuff here
        
        	delete jim; // jim is destroyed
        
        	return (0); // bob is destroyed
        }
        ```
        
        ### `New` operator
        
        - The **`new`** operator is used to dynamically allocate memory for an object or an array of objects.
        - Syntax for allocating a single object: **`pointer = new DataType;`**
        - Syntax for allocating an array of objects: **`pointer = new DataType[size];`**
        - It's important to note that memory allocated using **`new`** must be explicitly deallocated using **`delete`** (or **`delete[]`** for arrays) to prevent memory leaks.
        
        ```cpp
        #include <string>
        #include <iostream>
        
        class Student
        {
        	private:
        		std::string _login;
        
        	public:
        		Student() :_login("ldefault")
        		{
        			std::cout << "Student " << this->_login << " is born" << std::endl;
        		}
        
        		~Student()
        		{
        			std::cout << "Student " << this->_login << " died" << std::endl;
        		}
        };
        
        int main()
        {
        	Student*	students = new Student[5]; // new() does not take parameters
        
        	// Do some stuff here
        
        	delete [] students;
        
        	return (0);
        }
        ```
        
        ### `delete` operator
        
        - The **`delete`** operator is used to release the dynamically allocated memory.
        - Syntax for deallocating a single object: **`delete pointer;`**
        - Syntax for deallocating an array of objects: **`delete[] pointer;`**
    - When using **`new`**, if the memory allocation fails (due to insufficient memory), the **`new`** operator throws a **`std::bad_alloc`** exception. You can handle this exception using **`try-catch`** blocks.
        
        ```cpp
        try {
            int* numPtr = new int;  // Attempt dynamic memory allocation
            // ...
            delete numPtr;  // Release the memory allocated for a single int
        } catch (std::bad_alloc& ex) {
            // Handle the exception
            std::cerr << "Memory allocation failed: " << ex.what() << std::endl;
        }
        ```
        

### Q: **What is the difference between heap and stack?**

- **A:**
    - Both of these memories locate in the RAM. The way the memory will be assigned is different.
    - …
        - **Stack**
            - Has predefined size (around 2GB)
            - **When we want to use stack memory, the stack pointer moves and allocate the size of the memory that we want, and return the stack pointer.** So the values we assign on stack will be close to each other and be assigned backwards. A stack memory allocation is one CPU instruction and very fast
            - Once the scope in which you allocated that stack memory ends, all the memory allocated in the stack will be reclaimed
            - Stack overflow happens when all the memory in the stack has been allocated, in which case further allocations begin overflowing into other sections of memory
            - If you can allocate on the stack, choose stack
        - **Heap**
            - Has a predefined size but it can grow
            - Use `new` keyword to allocate on the heap
            - **Sequential memory requests may not result in sequential memory addresses being allocated**
            - The heap allocated memory needs to be manually freed
            - Dynamically allocated memory must be accessed through a pointer. **Dereferencing a pointer is slower than accessing a variable directly**

### Q: **What are pointers?**

- **A:**
    - Pointers are extremely important for managing and manipulating memory
    - **A pointer is an integer that stores a memory address**. It is the address of where that specific memory is.
    - The types of that pointer do not matter. It only indicates the type of data that's presumably holding. It's something we write to make our lives easier syntatically. Type does not change what a pointer is
    - Pointing to an invalid memory address (like 0) is perfectly fine for pointer
    - When putting `&` before a variable, we are asking the address of that variable
    - Dereferencing (*ptr) means accessing the data. In this way, you can write to or read from the data
    - Pointers themselves are also variables and stored in memory
    
    ```cpp
    int main()
    {
    	// allocate 8 chars
    	// point the pointer buffer to the beginning of the array
    	char* buffer = new char[8];
    	memset(buffer, 0, 8);
    
    	// pointer to pointer
    	char** ptr = &buffer;
    
    	delete[] buffer;
    	return (0)
    }
    ```
    

### Q: **What are references?**

- **A:**
    - References are aliases for existing variables. It is a pointer that is `constant` and always `dereferenced` and `never void`
    - Reference
        - A way for us to reference an existing variable. But pointer can be pointing to a non-existing address
        - References are not new variables. they don't really occupy memory or have storage
        - `int& ref = a;` `&` is part of the type. We actually created an alias
        - When you pass a value to a function, you are passing a copy of the value. For the destination function to change the value, you need to pass the memory address of that variable (using a reference or a pointer).
        - `value++`; Because of the order of operation, it will increment first and then dereference it. What's correct is to dereference first and increment it later - `(*value)++`
        - If you can, use reference and it will make the source code looks cleaner
        - Once you define a reference, you can't change what a reference is
    - References vs. pointer
        - You can't change where the reference is pointing to. It will always point to the same variable
        - You can't create a reference and let it point to nothing (uninitialised reference). Because it is constant, you can't point to something else later. But a reference can't point to nothing
        - Advantage: when you have a reference, you are sure that it's pointing to something
        - Reference is like a dereferenced pointer. So you don't need to add any symbol to access it
    - References are complimentary to pointers but they don't replace pointers. However, you can't have a reference and not initialise it to something. In comparison, using a pointer, you can point it to something that does not exist in the beginning, and change what it points to later
    - Pointers and references are essentially the same thing, regarding how the computer will do with them. Pointers are more flexible than references. **If something should always exist and never change, use a references. But if it should not always exist and can change, use a pointer.**
    
    ```cpp
    #include <iostream>
    
    int	main()
    {
    	int		numberOfBalls = 42;
    
    	int*	ballsPtr = &numberOfBalls;
    	int&	ballsRef = numberOfBalls;
    	// the reference will be pointing to the variable
    	// from this point on, you can't change what your reference is pointing to
    
    	std::cout << numberOfBalls << " " << *ballsPtr << " " << ballsRef << std::endl;
    
    	*ballsPtr = 21;
    	std::cout << numberOfBalls << std::endl;
    	ballsRef = 84;
    	std::cout << numberOfBalls << std::endl;
    
    	return (0);
    }
    ```
    
    ```cpp
    #include <iostream>
    #include <string>
    
    void byPtr(std::string* str)
    {
    	*str += " and ponies";  // Append " and ponies" to the string pointed by str
    }
    
    void byConstPtr(std::string const* str)
    {
    	std::cout << *str << std::endl;  // Print the value of the string pointed by str
    }
    
    void byRef(std::string& str)
    {
    	str += " and ponies";  // Append " and ponies" to the string referred by str
    }
    
    void byConstRef(std::string const& str)
    {
    	std::cout << str << std::endl;  // Print the value of the string referred by str
    }
    
    int main()
    {
    	std::string str = "i like butterflies";  // Declare and initialize a string variable
    
    	std::cout << str << std::endl;  // Print the value of str
    	byPtr(&str);  // Pass the address of str as a pointer to byPtr function
    	byConstPtr(&str);  // Pass the address of str as a constant pointer to byConstPtr function
    
    	str = "i like otters";  // Reassign a new value to str
    
    	std::cout << str << std::endl;  // Print the updated value of str
    	byRef(str);  // Pass str as a reference to byRef function
    	byConstRef(str);  // Pass str as a constant reference to byConstRef function
    
    	return 0;  // Exit the program with a return value of 0
    }
    ```
    
    ```cpp
    #include <iostream>
    #include <string>
    
    class Student
    {
    	private:
    		std::string _login;
    
    	public:
    		Student(std::string const & login) : _login(login)
    		{
    		}
    
    		std::string&	getLoginRef()
    		{
    			return this->_login;
    		}
    
    		std::string const & getLoginRefConst() const
    		{
    			return this->_login;
    		}
    
    		std::string*	getLoginPtr()
    		{
    			return &(this->_login);
    		}
    
    		std::string const * getLoginPtrConst() const
    		{
    			return &(this->_login);
    		}
    };
    
    int main()
    {
    	Student 	bob = Student("bfubar");
    	Student const jim = Student("jfubar");
    
    	// use a const function on a non-const variable is not a problem
    	std::cout << bob.getLoginRefConst() << " " << jim.getLoginRefConst() << std::endl;
    	std::cout << *(bob.getLoginPtrConst()) << " " << *(jim.getLoginPtrConst()) << std::endl;
    
    	bob.getLoginRef() = "bobfubar";
    	std::cout << bob.getLoginRefConst() << std::endl;
    
    	*(bob.getLoginPtr()) = "bobbyfubar";
    	std::cout << bob.getLoginRefConst() << std::endl;
    
    	return (0);
    }
    ```
    

### Q: **Destructor called without a constructor?**

- **A:**
    - Passing an instance of a class by value (not by pointer or reference) invokes the copy constructor. The compiler implements the copy constructor by default if the class definition does not explicitly supply one
    - The compiler-generated copy constructor will not call one of the other constructors you've implemented. But the destructor will be invoked to clean up the copy when done.
    - When you pass an instance to another function, when the function runs, it's added to the stack to process. A copy of the instance is sent to the stack, not the actual instance. Therefore, the system will use a copy constructor to create a copy and when the local copy is out of scope, the destructor will be called. However, in this case, the default constructor is not called.
    - **In order to actually change the original instance, you need to pass the instance with a pointer or a reference**. So the function can actually access the location of the original instance and make change to that instance/data member. If such case exists, a decision needs to be made between a reference and a pointer

### Q: **What are file streams?**

- **A:**
    - Streams that interact with files. There are three types of stream objects for working with files: `ifstream`, `ofstream`, and `fstream`
        - These classes have istream, ostream, and iostream as base classes, respectively
        - An `istream` object represents a file input stream so you can only read it
        - An `ofstream` object represents a file output stream that you can only write to it
        - An `fstream` is a file stream that you can read or write
    - You can associate a file stream object with a physical file when you create it. You can also create a file stream object that isn't assciated with a file, and then call a function member to establish the connection with a specific file
    - In order to read or write a file, you must "open" the file; this attaches the file to your program via the operating system with a set of permissions that determine what you can do with it. If you create a file stream object with an initial association to a file, the file is opened and available for use immediately
    - A file stream has some important properties. It has a `length`, which corresponds to the number of characters in the stream; it has a `beginning`, which is index position of the first character in the stream; and it has an `end`, which is the index position one beyond the last character in the stream. It also has a `current position`, which is the index position of the character in the stream where the next read or write operation will start. The `first character` in a file stream is at index position 0. These properties provide a way for you to move around a file to read the particular parts that you’re interested in or to overwrite selected areas of the file.
        
        ```cpp
        #include <iostream>
        #include <fstream>
        
        int main()
        {
        	//ifstream: input file stream
        	std::ifstream	ifs("numbers");
        	unsigned int	dst;
        	unsigned int	dst2;
        	ifs >> dst >> dst2;
        
        	std::cout << dst << " " << dst2 << std::endl;
        	ifs.close();
        
        	//-------------------------
        	//ofstream: output file stream
        	std::ofstream	ofs("test.out");
        	ofs << "i like ponies a whole damn lot" << std::endl;
        	ofs.close();
        	return (0);
        }
        ```