### Tasks to work on:

- For the class MyV discussed last time, overload the operator [] to give access to elements of the vector. The operator should return a reference to a given element.
- Provide protection agains mistakes in indexing. For example, when the index is out of range, write a message to cerr and return a reference to an additional element; you may also throw an exception.
- Define the assignment operator. Protect it from operations like a=a.
- Define the operator + (plus), adding two vectors of equal lengths. The result should be another object of the type MyV.