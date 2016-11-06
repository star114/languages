#include <Python/Python.h>

int main()
{
	Py_Initialize();
	PyRun_SimpleString("x = 'brave + sir + robin'");
	PyRun_SimpleString("print (x)");
	return 0;
}