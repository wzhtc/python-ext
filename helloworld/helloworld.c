#include <Python.h>

static PyObject *helloworld(PyObject *self, PyObject *args){
    printf("hello world");
    return Py_None;
}

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