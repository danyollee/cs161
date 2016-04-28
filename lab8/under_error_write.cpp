/*

removed a semicolon from line 14. We didn't finish the command so compiler freaks out.

removed curly brace from line 5. We never told where the function is to start.

added the '&' in line 27 when calling the function. The '&' changes the object type.

removed the asterisk on line 18. The function doesn't

removed the function type in line 5. Compiler says "under_error.cpp:5: error: ISO C++ forbids declaration of ‘is_equal’ with no type"

removed a parameter in line 5. Compiler says "under_error.cpp: In function ‘bool is_equal(char*)’:
under_error.cpp:7: error: ‘str1’ was not declared in this scope
under_error.cpp:11: error: ‘str1’ was not declared in this scope
under_error.cpp: In function ‘int main()’:
under_error.cpp:5: error: too many arguments to function ‘bool is_equal(char*)’
under_error.cpp:26: error: at this point in file"

commented out line 6. Compiler says	"under_error.cpp:7: error: ‘i’ was not declared in this scope"

