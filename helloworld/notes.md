# Creating a simple "hello world" c extension for python  


## write a helloworld.c
```c
// include python.h is a library that contains python data structures
// for example, PyObject, Py_None.
#include <Python.h> 

static PyObject *helloworld(PyObject *self, PyObject *args){
// we don't consider parse the argument from python object to c data type.

    printf("hello world");
    return Py_None; //the function return a python data type null
}
```
we first define how the hello world function. this function simply print a greeting.

```c
static PyMethodDef myMethods[] = {
    {"helloworld", helloworld, METH_NOARGS, "prints hello world"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef myModule = {
    PyModuleDef_HEAD_INIT,
    "myModule",
    "test",
    -1,
    myMethods
};

PyMODINIT_FUNC PyInit_myModule(void){
    return PyModule_Create(&myModule);
}
```
These are a standard definitions to the module and method.  

## write python setup.py file  
```python
from distutils.core import setup, Extension

setup(name = 'myModule', version='1.0', 
    ext_modules=[Extension('myModule', ['helloworld.c'])])
```  

## build the extension  
```bash
python setup.py build_ext --inplace
```
This will create a .pyd file in Windows or .so file in Mac with name starting myModule  

## test if works  
at the same folder of the extension binary file
```python
import myModule
myModule.helloworld()
```