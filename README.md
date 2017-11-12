# Kata - Pencils

ABOUT:

A simple program that allows the user to write, erase, and edit paper with a pencil.

Includes a test suite that first tests basic functionality, then runs specific error handling cases.

When choosing between a simple and complex + fast design, I chose simple every time.  So for example, the paper erase function uses a linear string search instead of using a multimap to lookup and store locations of words.

Similarly, I chose not to litter the code with try/catches and throws for simplicity.  I included one throw where it is particularly useful (trying to erase a string that doesn't exist), but otherwise when trying to do something illegal, the pencil/paper simply will not let you.  A more robust sample would want to include thorough error message handling to improve maintainability.


HOW TO RUN:

*Requires c++11

A) Add files into your favorite IDE
   Run main_test.cpp

or

B) Run linux commmand "make kataexe"
   Run linux command ".\kataexe"
