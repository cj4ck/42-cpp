# Templated containers, iterators, algorithms
### Q: **What are containers?**

- **A:**
    
    Array is contiguous, has no defined interface. 
    
    A container in C++ is a class template in the Standard Library that provides data structures to store, access, and manage collections of elements, with various types of containers optimized for different uses, such as sequential access (like **`vector`**, **`list`**, **`deque`**), associative access (like **`set`**, **`map`**), and hashed access (like **`unordered_set`**, **`unordered_map`**), each offering different time and space complexities for operations such as insertion, deletion, and search.
    
    ---
    
    - A container is a `holder object` that stores a collection os other objects (its elements). They are implemented as `class templates`, which allows a great flexibility in the types supported as elements. The container manages the storage space for its elements and provides member functions to access them, either directly or through iterators (reference objects with similar properties to pointers).
    - The containers library is a collection of templates and algorithms that implement the common data structures that we work with as programmers. **A container is an object that stores a collection of elements (i.e. other objects)**. Each of these containers manages the storage space for their elements and provides access to each element through iterators and/or member functions.
    - Containers replicate structures very commonly used in programming: dynamic arrays (`vector`), queues (`queue`), stacks (`stack`), heaps (`priority_queue`), linked lists (`list`), trees (`set`), associative arrays (`map`)...
    - **Many containers have several member functions in common, and share functionalities**. The decision of which type of container to use for a specific need does not generally depend only on the functionality offered by the container, but also on `the efficiency of some of its members (complexity)`. This is especially true for sequence containers, which offer different trade-offs in complexity between inserting/removing elements and accessing them.

### Q: **STL containers overview:**

- **A:**
    - The standard containers
        - **Sequence containers** (used for data structures that store objects of the same type in a linear manner)
            - `array`: a static contiguous array
            - `vector`: a dynamic contiguous array
            - `forward_list`: a single-linked list
            - `list`: a doubly-linked list
            - `deque`: a double-ended queue, where elements can be added to the front or back of the queue
        - **Container adapters** (Not full container classes on their own, but wrappers around other container types. They encapsulate the underlying container type and limit the user interfaces accordingly.)
            - `stack`: provides an LIFO data structure
            - `queue`: provides a FILO data structure
            - `priority_queue`: provides a priority queue, which allows for constant-time lookup of the largest element (by default)
        - **Associative containers**
            - keys are unique
                - `set`: a collection of unique keys, sorted by keys
                - `map`: a collection of key-value pairs, sorted by keys
            - Multiple entries for the same key are permitted
                - `multiset`: a collection of unique keys, sorted by keys
                - `multimap`: a collection of key-value pairs, sorted by keys
        - **Unordered associative containers**
            - Keys are unique
                - `unordered set`: a collection of keys, hashed by keys
                - `unordered_map`: a collection of key-value pairs, hashed by keys
            - Multiple entries for the same key are permitted
                - `unordered_multiset`: a collection of keys, hashed by keys
                - `unordered_multimap`: a collection of key-value pairs, hashed by keys

### Q: **What is std::vector?**

- **A:**
    
    `sequence container`
    
    Vector is a dynamic array, meaning it can resize itself automatically when an element is inserted or deleted, with its storage being handled automatically by the container.
    
    - **`empty()`**: Returns whether the container is empty.
    - **`insert()`**: Inserts elements at the specified location in the container.
    - **`push_back()`**: Adds the element at the end of the container.
    - **`pop_back()`**: Removes the last element of the container.
    - **`erase()`**: Removes a range of elements from the container.
    - **`clear()`**: Removes all elements from the container.

### Q: **What is std::list?**

- **A:**
    
    `sequence container`
    
    - Internally, **`std::list`** is implemented as a `doubly linked list`. Each element keeps an address to the next and the previous elements. This allows efficient insertions and deletions at both ends and in the middle.
    - **No Random Access**: The main drawback of lists and forward_lists compared to these other sequence containers is that **they lack direct access to the elements by their position.** Unlike **`std::vector`** and arrays, **`std::list`** does not provide fast random access to its elements. Elements are accessed sequentially. This means that if you want to access the nth element, you have to iterate through n elements.
    - Compared to other base standard sequence containers (array, vector and deque), **lists perform generally better in inserting, extracting and moving elements in any position within the container for which an iterator has already been obtained, and therefore also in algorithms that make intensive use of these, like sorting algorithms,** which takes linear time in the distance between these. They also **consume some extra memory** to keep the linking information associated to each element (which may be an important factor for large lists of small-sized elements).
    - **Sorting**: **`std::list`** has its own **`sort`** member function which can be more efficient than **`std::sort`** for lists because it does not require random access iterators.
    - **Splicing**: **`std::list`** provides a **`splice`** function that allows you to transfer elements from one list to another. This operation is very efficient and does not involve copying or moving of the elements but rather, it re-links the nodes.
        - …
            
            ```cpp
            std::list<int> list1 = {1, 2, 3};
            std::list<int> list2 = {4, 5, 6};
            
            // Transfer all elements from list2 to the end of list1
            list1.splice(list1.end(), list2);
            
            // Now list1 contains {1, 2, 3, 4, 5, 6} and list2 is empty
            ```
            
            ```cpp
            std::list<int> list1 = {1, 2, 3};
            std::list<int> list2 = {4, 5, 6};
            
            // Transfer the first element from list2 to the beginning of list1
            list1.splice(list1.begin(), list2, list2.begin());
            
            // Now list1 contains {4, 1, 2, 3} and list2 contains {5, 6}
            ```
            
    - **Iterators**: **`std::list`** provides bidirectional iterators, which means you can iterate forward and backward through the list, but you cannot perform arithmetic operations on the iterators (like you can with random access iterators).
    - **Thread Safety**: Just like **`std::vector`**, **`std::list`** is not inherently thread-safe. You need to use synchronization primitives to ensure safe access in a multi-threaded context.
    

### Q: **What is std::deque?**

- **A:**
    
    **`std::deque`** is an indexed sequence container that allows fast insertion and deletion at both its beginning and its end. In contrast to the **`std::vector`**, the **`std::deque`** does not have a continuous storage.
    
    - **Insertion and Deletion**: Deques allow insertion and deletion of elements from both ends of the container. Functions **`push_front()`** and **`pop_front()`** are unique to **`std::deque`.**
    - **Memory Layout**: Unlike **`std::vector`**, the elements in a **`std::deque`** are not stored contiguously in memory. **`std::deque`** uses individual fixed-size arrays, with additional bookkeeping, meaning that insertion and deletion at the beginning and end are both constant-time operations. When a **`std::vector`** needs to grow, it may need to reallocate its entire block of memory, which can be an expensive operation. In contrast, a **`std::deque`** can grow by allocating new blocks of memory without needing to reallocate existing blocks.
        - …
            
            ```cpp
            #include <iostream>
            #include <deque>
            
            int main() {
                std::deque<int> mydeque;
            
                mydeque.push_back(1);
                mydeque.push_front(2);
            
                std::cout << "Front element: " << mydeque.front() << std::endl;
                std::cout << "Back element: " << mydeque.back() << std::endl;
            
                mydeque.pop_back();
                mydeque.pop_front();
            
                return 0;
            }
            ```
            

### Q: **What is std::map?**

- **A:**
    - Maps are `associative containers` that store elements formed by a combination of a key value and a mapped value, following a specific order. **No two mapped values can have the same key values.**
    - **Key-Value Pairs**: **`std::map`** stores elements as key-value pairs. The key is used to identify the element, and the value is the data associated with the key.
    - **Ordering**: By default, **`std::map`** sorts its elements in ascending order based on the key. It uses the less-than operator (**`<`**) for comparison. You can also provide your own comparison function if you want a different ordering.
    - The types of key and mapped value may differ, and are grouped together in member type value_type, which is a pair type combining both: `std::pair<const Key, T> value_type`The key is constant because once you insert an element into a map, you can't change its key (because that could potentially violate the map's sorting).
        
        ```cpp
        std::map<std::string, int> ages;
        ages["Alice"] = 20;
        
        // Get an iterator to an element
        std::map<std::string, int>::iterator it = ages.find("Alice");
        
        if (it != ages.end()) {
            // The element is a pair
            std::pair<const std::string, int>& element = *it;
        
            // You can access the key and value
            const std::string& name = element.first;
            int age = element.second;
        
            std::cout << name << " is " << age << " years old." << std::endl;
        }
        ```
        
    - map containers are generally slower than unordered_map containers to access individual elements by their key, but **they allow the direct iteration on subsets based on their order**.
    - **The mapped values in a map can be accessed directly by their corresponding key using the bracket operator (`operator[]`)**.
    - Maps are typically implemented as binary search trees. **//! Need to do more reasearch about data structures here**

### Q: **What is std::stack?**

- **A:**
    - The `std::stack` class is a container adapter that gives the programmer the functionality of a stack (a LIFO (last-in, first-out) data structure).
    - It's called a container adapter because it's implemented on top of other container types, such as **`std::deque`** or **`std::vector`**. By default, if no container is specified, **`std::deque`** is used.
    - The class template acts as a wrapper to the underlying container - **only a specific set of functions is provided**. The stack pushes and pops the element from the back of the underlying container, known as the top of the stack.
    - `stacks` are implemented as container adaptors, which are classes that use an encapsulated object of a specific container class as its underlying container, providing a specific set of member functions to access its elements
    - The following operations are supported:
        - `empty`: check if the stack is empty or not
        - `size`: returns the number of elements present in the stack
        - `push`: insert the element at the top of the stack
        - `pop`: removes single topmost element from the stack. It does not return anything
        - `top`: returns the topmost element of the stack. It returns the element but not removes it.
        - `swap`: swaps the elements of the two stacks
        
        ```cpp
        #include <iostream>
        #include <stack>
        
        int main() {
            std::stack<int> myStack;
        
            myStack.push(5);
            myStack.push(3);
            myStack.push(9);
        
            std::cout << "Top element is: " << myStack.top() << "\n";  // prints: Top element is: 9
        
            myStack.pop();
            std::cout << "Top element is: " << myStack.top() << "\n";  // prints: Top element is: 3
        
            return 0;
        }
        ```
        

### Q: **What are iterators?**

- **A:**
    - An iterator is an object designed to traverse through a container, providing access to each element along the way. A container may provide different kinds of iterators.
    - Once the appropriate type of iterator is created, the programmer can then use the interface provided by the iterator to traverse and access elements without having to worry about what kind of traversal is being done or how the data is being stored in the container. And because C++ iterators typically use the same interface for traversal (`operator++ to move to the next element`) and access (`operator* to access the current element`), we can iterate through a wide variety of different container types using a consistent method.
    - Iterators let us view a non-linear collection in a linear manner. The whole point of iterators was to **have a standard interface to iterate over data in any container**. But we still had to specify what type of data this iterator was pointing to.
    - Any type that fulfills its implicit interface is valid to use with a templatized function.
    - Every different collection comes equipped with its own type of iterator. We want to ultimately write generic functions to work with iterators over any sequence. With templates, we can!
        
        ```cpp
        vector<int> v;
        vector<int>::iterator itr = v.begin();
        
        vector<double> v;
        vector<double>::iterator itr = v.begin();
        
        deque<int> d;
        deque<int>::iterator itr = d.begin();
        ```
        
    - Common traits among all iterators:
        - Can be created from existing iterator
        - Can be incremented or decremented using `++` and `--`
        - Can be compared with `==` and `!=`
    - It's b**etter to pre-increment if you don't need the value before it increments** ([source](https://stackoverflow.com/questions/1303899/performance-difference-between-iterator-and-iterator))
        - Postincrement must return the value the iterator had BEFORE it was incrementing; so, that previous value needs to be copied somewhere before altering it with the increment proper, so it's available to return.
            - The extra work may be a little or a lot, but it certainly can't be less than zero, compared to a preincrement, which can simply perform the incrementing and then return the just-altered value `--` no copying, saving, etc. necessary.
            - So, **unless you specifically MUST have postincrement (because you're using "value before increment" in some way), you should always use preincrement instead**.

### Q: **What are the types of iterators?**

- **A:**
    - `Input`: For sequential, single-pass input Read only, can only be dereferenced on the right side of the expression. `int val = *itr;`
    - `Output`: For sequential, single pass output. Write only, can only be dereferenced on left side of expression. `itr = 12;`
    - `Forward`: same as input/output iterators, except it can make multiple passes. Can read from and write to (if not a const iterator). `int val1 = *itr; itr++; int val2 = *itr;`
    - `Bidirectional`: Same as forward iterators except they can also go backwards with `-`. `int val1 = *itr; --itr; int val2 = *itr;`
    - `Random access`. Same as directional iterators except can be incremented or decremented by arbitrary amounts using `+` and ``. `int val1 = *itr; itr = itr + 3; int val2 = *itr;`

### Q: **What are iterator adapters?**

- **A:**
    - Sometimes we need to form different types of iterators. They act like iterators (can be dereferenced with `` and can be advanced with `++`). However, they don't actually point to elements of a container.
    - `std::ostream_iterator`: whenever you dereference a `std::ostream_iterator` and assign a value to it, the value is printed to a specified `std::ostream`.
    
    ```cpp
    std::ostream_iterator<int> itr(cout, ", ")
    *itr = 3; // prints 3 to console
    ++itr;
    *itr = 1729; // prints 1729 to console
    ++itr;
    *itr = 13; // prints 13 to console
    ```
    
    - With this, you can treat streams like iterators and use algorithms with them
    
    ```cpp
    std::vector<int> v{3, 1, 4, 1, 5};
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(cout, ", "))
    ```
    
    - The STL provides insert iterators (`std::inserter`, `std::back_inserter`, `std::front_inserter`). Writing to these iterators inserts the value into a container using one of the `insert`, `push_back`, or `push_front`.
    
    ```cpp
    std::vector<int> v; // empty vec
    auto itr = std::back_inserter(v);
    
    *itr = 1729; // does v.push_back(1729)
    ++itr;
    *itr = 13; // does v.push_back(13)
    ++itr;
    *itr = 3; // does v.push_back(3)
    
    // v look like this: {1729, 13, 3}
    vector<int> v {561, 1105, 1729, 2465};
    vector<int> vCopy; // start with an empty vector
    std::copy(v.begin(), v.end(), std::back_inserter(vCopy));
    ```
    

### Q: **What are algorithms?**

- **A:**
    - The STL containers pre-written algorithms that operate on `iterators`. Doing so lets them work on many types of containers. Uses are determined by `types of iterators`. Rely heavily on `templates`
    - We won't always know how much space will be needed for the destination. We want to be able to copy into a collection by "inserting" into it, rather than making space for it first (eg. pushback).
    
    ```cpp
    #include <iostream>
    #include <algorithm>
    #include <list>
    
    void displayInt(int i)
    {
    	std::cout << i << std::endl;
    }
    
    int main()
    {
    	std::list<int>  lst;
    
    	lst.pushback(10);
    	lst.pushback(23);
    	lst.pushback(3);
    	lst.pushback(17);
    	lst.pushback(20);
    
    	for_each(lst.begin(), lst.end(), displayInt);
    
    	return (0);
    }
    ```