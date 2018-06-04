/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.19
 * 
 * This file is not intended to be easily readable and contains a number of 
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG 
 * interface file instead. 
 * ----------------------------------------------------------------------------- */

#define SWIGPYTHON

#ifdef __cplusplus
template<class T> class SwigValueWrapper {
    T *tt;
public:
    inline SwigValueWrapper() : tt(0) { }
    inline ~SwigValueWrapper() { if (tt) delete tt; } 
    inline SwigValueWrapper& operator=(const T& t) { tt = new T(t); return *this; }
    inline operator T&() const { return *tt; }
    inline T *operator&() { return tt; }
};                                                    
#endif


#include "Python.h"

/***********************************************************************
 * common.swg
 *
 *     This file contains generic SWIG runtime support for pointer
 *     type checking as well as a few commonly used macros to control
 *     external linkage.
 *
 * Author : David Beazley (beazley@cs.uchicago.edu)
 *
 * Copyright (c) 1999-2000, The University of Chicago
 * 
 * This file may be freely redistributed without license or fee provided
 * this copyright message remains intact.
 ************************************************************************/

#include <string.h>

#if defined(_WIN32) || defined(__WIN32__)
#       if defined(_MSC_VER)
#               if defined(STATIC_LINKED)
#                       define SWIGEXPORT(a) a
#                       define SWIGIMPORT(a) extern a
#               else
#                       define SWIGEXPORT(a) __declspec(dllexport) a
#                       define SWIGIMPORT(a) extern a
#               endif
#       else
#               if defined(__BORLANDC__)
#                       define SWIGEXPORT(a) a _export
#                       define SWIGIMPORT(a) a _export
#               else
#                       define SWIGEXPORT(a) a
#                       define SWIGIMPORT(a) a
#               endif
#       endif
#else
#       define SWIGEXPORT(a) a
#       define SWIGIMPORT(a) a
#endif

#ifdef SWIG_GLOBAL
#define SWIGRUNTIME(a) SWIGEXPORT(a)
#else
#define SWIGRUNTIME(a) static a
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef void *(*swig_converter_func)(void *);
typedef struct swig_type_info *(*swig_dycast_func)(void **);

typedef struct swig_type_info {
  const char             *name;                 
  swig_converter_func     converter;
  const char             *str;
  void                   *clientdata;	
  swig_dycast_func        dcast;
  struct swig_type_info  *next;
  struct swig_type_info  *prev;
} swig_type_info;

#ifdef SWIG_NOINCLUDE

SWIGIMPORT(swig_type_info *) SWIG_TypeRegister(swig_type_info *);
SWIGIMPORT(swig_type_info *) SWIG_TypeCheck(char *c, swig_type_info *);
SWIGIMPORT(void *)           SWIG_TypeCast(swig_type_info *, void *);
SWIGIMPORT(swig_type_info *) SWIG_TypeDynamicCast(swig_type_info *, void **);
SWIGIMPORT(const char *)     SWIG_TypeName(const swig_type_info *);
SWIGIMPORT(swig_type_info *) SWIG_TypeQuery(const char *);
SWIGIMPORT(void)             SWIG_TypeClientData(swig_type_info *, void *);

#else

static swig_type_info *swig_type_list = 0;

/* Register a type mapping with the type-checking */
SWIGRUNTIME(swig_type_info *)
SWIG_TypeRegister(swig_type_info *ti)
{
  swig_type_info *tc, *head, *ret, *next;
  /* Check to see if this type has already been registered */
  tc = swig_type_list;
  while (tc) {
    if (strcmp(tc->name, ti->name) == 0) {
      /* Already exists in the table.  Just add additional types to the list */
      if (tc->clientdata) ti->clientdata = tc->clientdata;	
      head = tc;
      next = tc->next;
      goto l1;
    }
    tc = tc->prev;
  }
  head = ti;
  next = 0;

  /* Place in list */
  ti->prev = swig_type_list;
  swig_type_list = ti;

  /* Build linked lists */
 l1:
  ret = head;
  tc = ti + 1;
  /* Patch up the rest of the links */
  while (tc->name) {
    head->next = tc;
    tc->prev = head;
    head = tc;
    tc++;
  }
  if (next) next->prev = head;  /**/
  head->next = next;
  return ret;
}

/* Check the typename */
SWIGRUNTIME(swig_type_info *) 
SWIG_TypeCheck(char *c, swig_type_info *ty)
{
  swig_type_info *s;
  if (!ty) return 0;        /* Void pointer */
  s = ty->next;             /* First element always just a name */
  do {
    if (strcmp(s->name,c) == 0) {
      if (s == ty->next) return s;
      /* Move s to the top of the linked list */
      s->prev->next = s->next;
      if (s->next) {
	s->next->prev = s->prev;
      }
      /* Insert s as second element in the list */
      s->next = ty->next;
      if (ty->next) ty->next->prev = s;
      ty->next = s;
      s->prev = ty;  /**/
      return s;
    }
    s = s->next;
  } while (s && (s != ty->next));
  return 0;
}

/* Cast a pointer up an inheritance hierarchy */
SWIGRUNTIME(void *) 
SWIG_TypeCast(swig_type_info *ty, void *ptr) 
{
  if ((!ty) || (!ty->converter)) return ptr;
  return (*ty->converter)(ptr);
}

/* Dynamic pointer casting. Down an inheritance hierarchy */
SWIGRUNTIME(swig_type_info *) 
SWIG_TypeDynamicCast(swig_type_info *ty, void **ptr) 
{
  swig_type_info *lastty = ty;
  if (!ty || !ty->dcast) return ty;
  while (ty && (ty->dcast)) {
     ty = (*ty->dcast)(ptr);
     if (ty) lastty = ty;
  }
  return lastty;
}

/* Return the name associated with this type */
SWIGRUNTIME(const char *)
SWIG_TypeName(const swig_type_info *ty) {
  return ty->name;
}

/* Search for a swig_type_info structure */
SWIGRUNTIME(swig_type_info *)
SWIG_TypeQuery(const char *name) {
  swig_type_info *ty = swig_type_list;
  while (ty) {
    if (ty->str && (strcmp(name,ty->str) == 0)) return ty;
    if (ty->name && (strcmp(name,ty->name) == 0)) return ty;
    ty = ty->prev;
  }
  return 0;
}

/* Set the clientdata field for a type */
SWIGRUNTIME(void)
SWIG_TypeClientData(swig_type_info *ti, void *clientdata) {
  swig_type_info *tc, *equiv;
  if (ti->clientdata == clientdata) return;
  ti->clientdata = clientdata;
  equiv = ti->next;
  while (equiv) {
    if (!equiv->converter) {
      tc = swig_type_list;
      while (tc) {
	if ((strcmp(tc->name, equiv->name) == 0))
	  SWIG_TypeClientData(tc,clientdata);
	tc = tc->prev;
      }
    }
    equiv = equiv->next;
  }
}
#endif

#ifdef __cplusplus
}

#endif

/***********************************************************************
 * python.swg
 *
 *     This file contains the runtime support for Python modules
 *     and includes code for managing global variables and pointer
 *     type checking.
 *
 * Author : David Beazley (beazley@cs.uchicago.edu)
 ************************************************************************/

#include "Python.h"

#ifdef __cplusplus
extern "C" {
#endif

#define SWIG_PY_INT     1
#define SWIG_PY_FLOAT   2
#define SWIG_PY_STRING  3
#define SWIG_PY_POINTER 4
#define SWIG_PY_BINARY  5

/* Flags for pointer conversion */

#define SWIG_POINTER_EXCEPTION     0x1
#define SWIG_POINTER_DISOWN        0x2

/* Exception handling in wrappers */
#define SWIG_fail   goto fail

/* Constant information structure */
typedef struct swig_const_info {
    int type;
    char *name;
    long lvalue;
    double dvalue;
    void   *pvalue;
    swig_type_info **ptype;
} swig_const_info;

#ifdef SWIG_NOINCLUDE

SWIGEXPORT(PyObject *)        SWIG_newvarlink(void);
SWIGEXPORT(void)              SWIG_addvarlink(PyObject *, char *, PyObject *(*)(void), int (*)(PyObject *));
SWIGEXPORT(int)               SWIG_ConvertPtr(PyObject *, void **, swig_type_info *, int);
SWIGEXPORT(int)               SWIG_ConvertPacked(PyObject *, void *, int sz, swig_type_info *, int);
SWIGEXPORT(char *)            SWIG_PackData(char *c, void *, int);
SWIGEXPORT(char *)            SWIG_UnpackData(char *c, void *, int);
SWIGEXPORT(PyObject *)        SWIG_NewPointerObj(void *, swig_type_info *,int own);
SWIGEXPORT(PyObject *)        SWIG_NewPackedObj(void *, int sz, swig_type_info *);
SWIGEXPORT(void)              SWIG_InstallConstants(PyObject *d, swig_const_info constants[]);
#else

/* -----------------------------------------------------------------------------
 * global variable support code.
 * ----------------------------------------------------------------------------- */

typedef struct swig_globalvar {   
  char       *name;                  /* Name of global variable */
  PyObject *(*get_attr)(void);       /* Return the current value */
  int       (*set_attr)(PyObject *); /* Set the value */
  struct swig_globalvar *next;
} swig_globalvar;

typedef struct swig_varlinkobject {
  PyObject_HEAD
  swig_globalvar *vars;
} swig_varlinkobject;

static PyObject *
swig_varlink_repr(swig_varlinkobject *v) {
  v = v;
  return PyString_FromString("<Global variables>");
}

static int
swig_varlink_print(swig_varlinkobject *v, FILE *fp, int flags) {
  swig_globalvar  *var;
  flags = flags;
  fprintf(fp,"Global variables { ");
  for (var = v->vars; var; var=var->next) {
    fprintf(fp,"%s", var->name);
    if (var->next) fprintf(fp,", ");
  }
  fprintf(fp," }\n");
  return 0;
}

static PyObject *
swig_varlink_getattr(swig_varlinkobject *v, char *n) {
  swig_globalvar *var = v->vars;
  while (var) {
    if (strcmp(var->name,n) == 0) {
      return (*var->get_attr)();
    }
    var = var->next;
  }
  PyErr_SetString(PyExc_NameError,"Unknown C global variable");
  return NULL;
}

static int
swig_varlink_setattr(swig_varlinkobject *v, char *n, PyObject *p) {
  swig_globalvar *var = v->vars;
  while (var) {
    if (strcmp(var->name,n) == 0) {
      return (*var->set_attr)(p);
    }
    var = var->next;
  }
  PyErr_SetString(PyExc_NameError,"Unknown C global variable");
  return 1;
}

statichere PyTypeObject varlinktype = {
  PyObject_HEAD_INIT(0)              
  0,
  (char *)"swigvarlink",                      /* Type name    */
  sizeof(swig_varlinkobject),         /* Basic size   */
  0,                                  /* Itemsize     */
  0,                                  /* Deallocator  */ 
  (printfunc) swig_varlink_print,     /* Print        */
  (getattrfunc) swig_varlink_getattr, /* get attr     */
  (setattrfunc) swig_varlink_setattr, /* Set attr     */
  0,                                  /* tp_compare   */
  (reprfunc) swig_varlink_repr,       /* tp_repr      */    
  0,                                  /* tp_as_number */
  0,                                  /* tp_as_mapping*/
  0,                                  /* tp_hash      */
};

/* Create a variable linking object for use later */
SWIGRUNTIME(PyObject *)
SWIG_newvarlink(void) {
  swig_varlinkobject *result = 0;
  result = PyMem_NEW(swig_varlinkobject,1);
  varlinktype.ob_type = &PyType_Type;    /* Patch varlinktype into a PyType */
  result->ob_type = &varlinktype;
  result->vars = 0;
  result->ob_refcnt = 0;
  Py_XINCREF((PyObject *) result);
  return ((PyObject*) result);
}

SWIGRUNTIME(void)
SWIG_addvarlink(PyObject *p, char *name,
	   PyObject *(*get_attr)(void), int (*set_attr)(PyObject *p)) {
  swig_varlinkobject *v;
  swig_globalvar *gv;
  v= (swig_varlinkobject *) p;
  gv = (swig_globalvar *) malloc(sizeof(swig_globalvar));
  gv->name = (char *) malloc(strlen(name)+1);
  strcpy(gv->name,name);
  gv->get_attr = get_attr;
  gv->set_attr = set_attr;
  gv->next = v->vars;
  v->vars = gv;
}

/* Pack binary data into a string */
SWIGRUNTIME(char *)
SWIG_PackData(char *c, void *ptr, int sz) {
  static char hex[17] = "0123456789abcdef";
  int i;
  unsigned char *u = (unsigned char *) ptr;
  register unsigned char uu;
  for (i = 0; i < sz; i++,u++) {
    uu = *u;
    *(c++) = hex[(uu & 0xf0) >> 4];
    *(c++) = hex[uu & 0xf];
  }
  return c;
}

/* Unpack binary data from a string */
SWIGRUNTIME(char *)
SWIG_UnpackData(char *c, void *ptr, int sz) {
  register unsigned char uu = 0;
  register int d;
  unsigned char *u = (unsigned char *) ptr;
  int i;
  for (i = 0; i < sz; i++, u++) {
    d = *(c++);
    if ((d >= '0') && (d <= '9'))
      uu = ((d - '0') << 4);
    else if ((d >= 'a') && (d <= 'f'))
      uu = ((d - ('a'-10)) << 4);
    d = *(c++);
    if ((d >= '0') && (d <= '9'))
      uu |= (d - '0');
    else if ((d >= 'a') && (d <= 'f'))
      uu |= (d - ('a'-10));
    *u = uu;
  }
  return c;
}

/* Convert a pointer value */
SWIGRUNTIME(int)
SWIG_ConvertPtr(PyObject *obj, void **ptr, swig_type_info *ty, int flags) {
  swig_type_info *tc;
  char  *c;
  static PyObject *SWIG_this = 0;
  int    newref = 0;
  PyObject  *pyobj = 0;

  if (!obj) return 0;
  if (obj == Py_None) {
    *ptr = 0;
    return 0;
  }
#ifdef SWIG_COBJECT_TYPES
  if (!(PyCObject_Check(obj))) {
    if (!SWIG_this)
      SWIG_this = PyString_FromString("this");
    pyobj = obj;
    obj = PyObject_GetAttr(obj,SWIG_this);
    newref = 1;
    if (!obj) goto type_error;
    if (!PyCObject_Check(obj)) {
      Py_DECREF(obj);
      goto type_error;
    }
  }  
  *ptr = PyCObject_AsVoidPtr(obj);
  c = (char *) PyCObject_GetDesc(obj);
  if (newref) Py_DECREF(obj);
  goto cobject;
#else
  if (!(PyString_Check(obj))) {
    if (!SWIG_this)
      SWIG_this = PyString_FromString("this");
    pyobj = obj;
    obj = PyObject_GetAttr(obj,SWIG_this);
    newref = 1;
    if (!obj) goto type_error;
    if (!PyString_Check(obj)) {
      Py_DECREF(obj);
      goto type_error;
    }
  } 
  c = PyString_AsString(obj);
  /* Pointer values must start with leading underscore */
  if (*c != '_') {
    *ptr = (void *) 0;
    if (strcmp(c,"NULL") == 0) {
      if (newref) { Py_DECREF(obj); }
      return 0;
    } else {
      if (newref) { Py_DECREF(obj); }
      goto type_error;
    }
  }
  c++;
  c = SWIG_UnpackData(c,ptr,sizeof(void *));
  if (newref) { Py_DECREF(obj); }
#endif

#ifdef SWIG_COBJECT_TYPES
cobject:
#endif

  if (ty) {
    tc = SWIG_TypeCheck(c,ty);
    if (!tc) goto type_error;
    *ptr = SWIG_TypeCast(tc,(void*) *ptr);
  }

  if ((pyobj) && (flags & SWIG_POINTER_DISOWN)) {
      PyObject *zero = PyInt_FromLong(0);
      PyObject_SetAttrString(pyobj,(char*)"thisown",zero);
      Py_DECREF(zero);
  }
  return 0;

type_error:
  if (flags & SWIG_POINTER_EXCEPTION) {
    if (ty) {
      char *temp = (char *) malloc(64+strlen(ty->name));
      sprintf(temp,"Type error. Expected %s", ty->name);
      PyErr_SetString(PyExc_TypeError, temp);
      free((char *) temp);
    } else {
      PyErr_SetString(PyExc_TypeError,"Expected a pointer");
    }
  }
  return -1;
}

/* Convert a packed value value */
SWIGRUNTIME(int)
SWIG_ConvertPacked(PyObject *obj, void *ptr, int sz, swig_type_info *ty, int flags) {
  swig_type_info *tc;
  char  *c;

  if ((!obj) || (!PyString_Check(obj))) goto type_error;
  c = PyString_AsString(obj);
  /* Pointer values must start with leading underscore */
  if (*c != '_') goto type_error;
  c++;
  c = SWIG_UnpackData(c,ptr,sz);
  if (ty) {
    tc = SWIG_TypeCheck(c,ty);
    if (!tc) goto type_error;
  }
  return 0;

type_error:

  if (flags) {
    if (ty) {
      char *temp = (char *) malloc(64+strlen(ty->name));
      sprintf(temp,"Type error. Expected %s", ty->name);
      PyErr_SetString(PyExc_TypeError, temp);
      free((char *) temp);
    } else {
      PyErr_SetString(PyExc_TypeError,"Expected a pointer");
    }
  }
  return -1;
}

/* Create a new pointer object */
SWIGRUNTIME(PyObject *)
SWIG_NewPointerObj(void *ptr, swig_type_info *type, int own) {
  PyObject *robj;
  if (!ptr) {
    Py_INCREF(Py_None);
    return Py_None;
  }
#ifdef SWIG_COBJECT_TYPES
  robj = PyCObject_FromVoidPtrAndDesc((void *) ptr, (char *) type->name, NULL);
#else
  {
    char result[1024];
    char *r = result;
    *(r++) = '_';
    r = SWIG_PackData(r,&ptr,sizeof(void *));
    strcpy(r,type->name);
    robj = PyString_FromString(result);
  }
#endif
  if (!robj || (robj == Py_None)) return robj;
  if (type->clientdata) {
    PyObject *inst;
    PyObject *args = Py_BuildValue((char*)"(O)", robj);
    Py_DECREF(robj);
    inst = PyObject_CallObject((PyObject *) type->clientdata, args);
    Py_DECREF(args);
    if (inst) {
      if (own) {
	PyObject *n = PyInt_FromLong(1);
	PyObject_SetAttrString(inst,(char*)"thisown",n);
	Py_DECREF(n);
      }
      robj = inst;
    }
  }
  return robj;
}

SWIGRUNTIME(PyObject *)
SWIG_NewPackedObj(void *ptr, int sz, swig_type_info *type) {
  char result[1024];
  char *r = result;
  if ((2*sz + 1 + strlen(type->name)) > 1000) return 0;
  *(r++) = '_';
  r = SWIG_PackData(r,ptr,sz);
  strcpy(r,type->name);
  return PyString_FromString(result);
}

/* Install Constants */
SWIGRUNTIME(void)
SWIG_InstallConstants(PyObject *d, swig_const_info constants[]) {
  int i;
  PyObject *obj;
  for (i = 0; constants[i].type; i++) {
    switch(constants[i].type) {
    case SWIG_PY_INT:
      obj = PyInt_FromLong(constants[i].lvalue);
      break;
    case SWIG_PY_FLOAT:
      obj = PyFloat_FromDouble(constants[i].dvalue);
      break;
    case SWIG_PY_STRING:
      obj = PyString_FromString((char *) constants[i].pvalue);
      break;
    case SWIG_PY_POINTER:
      obj = SWIG_NewPointerObj(constants[i].pvalue, *(constants[i]).ptype,0);
      break;
    case SWIG_PY_BINARY:
      obj = SWIG_NewPackedObj(constants[i].pvalue, constants[i].lvalue, *(constants[i].ptype));
      break;
    default:
      obj = 0;
      break;
    }
    if (obj) {
      PyDict_SetItemString(d,constants[i].name,obj);
      Py_DECREF(obj);
    }
  }
}

#endif

#ifdef __cplusplus
}
#endif








/* -------- TYPES TABLE (BEGIN) -------- */

#define  SWIGTYPE_p_float swig_types[0] 
#define  SWIGTYPE_p_floatp swig_types[1] 
#define  SWIGTYPE_p_floatArray swig_types[2] 
#define  SWIGTYPE_p_intp swig_types[3] 
#define  SWIGTYPE_p_int swig_types[4] 
static swig_type_info *swig_types[6];

/* -------- TYPES TABLE (END) -------- */


/*-----------------------------------------------
              @(target):= _swilk.so
  ------------------------------------------------*/
#define SWIG_init    init_swilk

#define SWIG_name    "_swilk"

  /* Put headers and other declarations here */

extern void swilkf(int &,float *,int &,int &,int &,float *,float &,float &,int &);

typedef int intp;

intp *new_intp(){
  return new int();
}
void delete_intp(intp *self){
  if (self) delete self;
}
void intp_assign(intp *self,int value){
  *self = value;
}
int intp_value(intp *self){
  return *self;
}
int *intp_cast(intp *self){
  return self;
}
intp *intp_frompointer(int *t){
  return (intp *) t;
}

typedef float floatp;

floatp *new_floatp(){
  return new float();
}
void delete_floatp(floatp *self){
  if (self) delete self;
}
void floatp_assign(floatp *self,float value){
  *self = value;
}
float floatp_value(floatp *self){
  return *self;
}
float *floatp_cast(floatp *self){
  return self;
}
floatp *floatp_frompointer(float *t){
  return (floatp *) t;
}

typedef float floatArray;

floatArray *new_floatArray(int nelements){
  return new float[nelements];
}
void delete_floatArray(floatArray *self){
  delete [] self;
}
float floatArray_getitem(floatArray *self,int index){
  return self[index];
}
void floatArray_setitem(floatArray *self,int index,float value){
  self[index] = value;
}
float *floatArray_cast(floatArray *self){
  return self;
}
floatArray *floatArray_frompointer(float *t){
  return (floatArray *) t;
}
#ifdef __cplusplus
extern "C" {
#endif
static PyObject *_wrap_swilkf(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    int *arg1 = 0 ;
    float *arg2 = (float *) 0 ;
    int *arg3 = 0 ;
    int *arg4 = 0 ;
    int *arg5 = 0 ;
    float *arg6 = (float *) 0 ;
    float *arg7 = 0 ;
    float *arg8 = 0 ;
    int *arg9 = 0 ;
    PyObject * obj0 = 0 ;
    PyObject * obj1 = 0 ;
    PyObject * obj2 = 0 ;
    PyObject * obj3 = 0 ;
    PyObject * obj4 = 0 ;
    PyObject * obj5 = 0 ;
    PyObject * obj6 = 0 ;
    PyObject * obj7 = 0 ;
    PyObject * obj8 = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"OOOOOOOOO:swilkf",&obj0,&obj1,&obj2,&obj3,&obj4,&obj5,&obj6,&obj7,&obj8)) goto fail;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_int,SWIG_POINTER_EXCEPTION | 0 )) == -1) SWIG_fail;
    if (arg1 == NULL) {
        PyErr_SetString(PyExc_TypeError,"null reference"); SWIG_fail; 
    }
    if ((SWIG_ConvertPtr(obj1,(void **) &arg2, SWIGTYPE_p_float,SWIG_POINTER_EXCEPTION | 0 )) == -1) SWIG_fail;
    if ((SWIG_ConvertPtr(obj2,(void **) &arg3, SWIGTYPE_p_int,SWIG_POINTER_EXCEPTION | 0 )) == -1) SWIG_fail;
    if (arg3 == NULL) {
        PyErr_SetString(PyExc_TypeError,"null reference"); SWIG_fail; 
    }
    if ((SWIG_ConvertPtr(obj3,(void **) &arg4, SWIGTYPE_p_int,SWIG_POINTER_EXCEPTION | 0 )) == -1) SWIG_fail;
    if (arg4 == NULL) {
        PyErr_SetString(PyExc_TypeError,"null reference"); SWIG_fail; 
    }
    if ((SWIG_ConvertPtr(obj4,(void **) &arg5, SWIGTYPE_p_int,SWIG_POINTER_EXCEPTION | 0 )) == -1) SWIG_fail;
    if (arg5 == NULL) {
        PyErr_SetString(PyExc_TypeError,"null reference"); SWIG_fail; 
    }
    if ((SWIG_ConvertPtr(obj5,(void **) &arg6, SWIGTYPE_p_float,SWIG_POINTER_EXCEPTION | 0 )) == -1) SWIG_fail;
    if ((SWIG_ConvertPtr(obj6,(void **) &arg7, SWIGTYPE_p_float,SWIG_POINTER_EXCEPTION | 0 )) == -1) SWIG_fail;
    if (arg7 == NULL) {
        PyErr_SetString(PyExc_TypeError,"null reference"); SWIG_fail; 
    }
    if ((SWIG_ConvertPtr(obj7,(void **) &arg8, SWIGTYPE_p_float,SWIG_POINTER_EXCEPTION | 0 )) == -1) SWIG_fail;
    if (arg8 == NULL) {
        PyErr_SetString(PyExc_TypeError,"null reference"); SWIG_fail; 
    }
    if ((SWIG_ConvertPtr(obj8,(void **) &arg9, SWIGTYPE_p_int,SWIG_POINTER_EXCEPTION | 0 )) == -1) SWIG_fail;
    if (arg9 == NULL) {
        PyErr_SetString(PyExc_TypeError,"null reference"); SWIG_fail; 
    }
    swilkf(*arg1,arg2,*arg3,*arg4,*arg5,arg6,*arg7,*arg8,*arg9);
    
    Py_INCREF(Py_None); resultobj = Py_None;
    return resultobj;
    fail:
    return NULL;
}


static PyObject *_wrap_new_intp(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    intp *result;
    
    if(!PyArg_ParseTuple(args,(char *)":new_intp")) goto fail;
    result = (intp *)new_intp();
    
    resultobj = SWIG_NewPointerObj((void *) result, SWIGTYPE_p_intp, 1);
    return resultobj;
    fail:
    return NULL;
}


static PyObject *_wrap_delete_intp(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    intp *arg1 = (intp *) 0 ;
    PyObject * obj0 = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"O:delete_intp",&obj0)) goto fail;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_intp,SWIG_POINTER_EXCEPTION | 0 )) == -1) SWIG_fail;
    delete_intp(arg1);
    
    Py_INCREF(Py_None); resultobj = Py_None;
    return resultobj;
    fail:
    return NULL;
}


static PyObject *_wrap_intp_assign(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    intp *arg1 = (intp *) 0 ;
    int arg2 ;
    PyObject * obj0 = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"Oi:intp_assign",&obj0,&arg2)) goto fail;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_intp,SWIG_POINTER_EXCEPTION | 0 )) == -1) SWIG_fail;
    intp_assign(arg1,arg2);
    
    Py_INCREF(Py_None); resultobj = Py_None;
    return resultobj;
    fail:
    return NULL;
}


static PyObject *_wrap_intp_value(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    intp *arg1 = (intp *) 0 ;
    int result;
    PyObject * obj0 = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"O:intp_value",&obj0)) goto fail;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_intp,SWIG_POINTER_EXCEPTION | 0 )) == -1) SWIG_fail;
    result = (int)intp_value(arg1);
    
    resultobj = PyInt_FromLong((long)result);
    return resultobj;
    fail:
    return NULL;
}


static PyObject *_wrap_intp_cast(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    intp *arg1 = (intp *) 0 ;
    int *result;
    PyObject * obj0 = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"O:intp_cast",&obj0)) goto fail;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_intp,SWIG_POINTER_EXCEPTION | 0 )) == -1) SWIG_fail;
    result = (int *)intp_cast(arg1);
    
    resultobj = SWIG_NewPointerObj((void *) result, SWIGTYPE_p_int, 0);
    return resultobj;
    fail:
    return NULL;
}


static PyObject *_wrap_intp_frompointer(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    int *arg1 = (int *) 0 ;
    intp *result;
    PyObject * obj0 = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"O:intp_frompointer",&obj0)) goto fail;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_int,SWIG_POINTER_EXCEPTION | 0 )) == -1) SWIG_fail;
    result = (intp *)intp_frompointer(arg1);
    
    resultobj = SWIG_NewPointerObj((void *) result, SWIGTYPE_p_intp, 0);
    return resultobj;
    fail:
    return NULL;
}


static PyObject * intp_swigregister(PyObject *self, PyObject *args) {
    PyObject *obj;
    if (!PyArg_ParseTuple(args,(char*)"O", &obj)) return NULL;
    SWIG_TypeClientData(SWIGTYPE_p_intp, obj);
    Py_INCREF(obj);
    return Py_BuildValue((char *)"");
}
static PyObject *_wrap_new_floatp(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    floatp *result;
    
    if(!PyArg_ParseTuple(args,(char *)":new_floatp")) goto fail;
    result = (floatp *)new_floatp();
    
    resultobj = SWIG_NewPointerObj((void *) result, SWIGTYPE_p_floatp, 1);
    return resultobj;
    fail:
    return NULL;
}


static PyObject *_wrap_delete_floatp(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    floatp *arg1 = (floatp *) 0 ;
    PyObject * obj0 = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"O:delete_floatp",&obj0)) goto fail;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_floatp,SWIG_POINTER_EXCEPTION | 0 )) == -1) SWIG_fail;
    delete_floatp(arg1);
    
    Py_INCREF(Py_None); resultobj = Py_None;
    return resultobj;
    fail:
    return NULL;
}


static PyObject *_wrap_floatp_assign(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    floatp *arg1 = (floatp *) 0 ;
    float arg2 ;
    PyObject * obj0 = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"Of:floatp_assign",&obj0,&arg2)) goto fail;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_floatp,SWIG_POINTER_EXCEPTION | 0 )) == -1) SWIG_fail;
    floatp_assign(arg1,arg2);
    
    Py_INCREF(Py_None); resultobj = Py_None;
    return resultobj;
    fail:
    return NULL;
}


static PyObject *_wrap_floatp_value(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    floatp *arg1 = (floatp *) 0 ;
    float result;
    PyObject * obj0 = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"O:floatp_value",&obj0)) goto fail;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_floatp,SWIG_POINTER_EXCEPTION | 0 )) == -1) SWIG_fail;
    result = (float)floatp_value(arg1);
    
    resultobj = PyFloat_FromDouble(result);
    return resultobj;
    fail:
    return NULL;
}


static PyObject *_wrap_floatp_cast(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    floatp *arg1 = (floatp *) 0 ;
    float *result;
    PyObject * obj0 = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"O:floatp_cast",&obj0)) goto fail;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_floatp,SWIG_POINTER_EXCEPTION | 0 )) == -1) SWIG_fail;
    result = (float *)floatp_cast(arg1);
    
    resultobj = SWIG_NewPointerObj((void *) result, SWIGTYPE_p_float, 0);
    return resultobj;
    fail:
    return NULL;
}


static PyObject *_wrap_floatp_frompointer(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    float *arg1 = (float *) 0 ;
    floatp *result;
    PyObject * obj0 = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"O:floatp_frompointer",&obj0)) goto fail;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_float,SWIG_POINTER_EXCEPTION | 0 )) == -1) SWIG_fail;
    result = (floatp *)floatp_frompointer(arg1);
    
    resultobj = SWIG_NewPointerObj((void *) result, SWIGTYPE_p_floatp, 0);
    return resultobj;
    fail:
    return NULL;
}


static PyObject * floatp_swigregister(PyObject *self, PyObject *args) {
    PyObject *obj;
    if (!PyArg_ParseTuple(args,(char*)"O", &obj)) return NULL;
    SWIG_TypeClientData(SWIGTYPE_p_floatp, obj);
    Py_INCREF(obj);
    return Py_BuildValue((char *)"");
}
static PyObject *_wrap_new_floatArray(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    int arg1 ;
    floatArray *result;
    
    if(!PyArg_ParseTuple(args,(char *)"i:new_floatArray",&arg1)) goto fail;
    result = (floatArray *)new_floatArray(arg1);
    
    resultobj = SWIG_NewPointerObj((void *) result, SWIGTYPE_p_floatArray, 1);
    return resultobj;
    fail:
    return NULL;
}


static PyObject *_wrap_delete_floatArray(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    floatArray *arg1 = (floatArray *) 0 ;
    PyObject * obj0 = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"O:delete_floatArray",&obj0)) goto fail;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_floatArray,SWIG_POINTER_EXCEPTION | 0 )) == -1) SWIG_fail;
    delete_floatArray(arg1);
    
    Py_INCREF(Py_None); resultobj = Py_None;
    return resultobj;
    fail:
    return NULL;
}


static PyObject *_wrap_floatArray___getitem__(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    floatArray *arg1 = (floatArray *) 0 ;
    int arg2 ;
    float result;
    PyObject * obj0 = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"Oi:floatArray___getitem__",&obj0,&arg2)) goto fail;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_floatArray,SWIG_POINTER_EXCEPTION | 0 )) == -1) SWIG_fail;
    result = (float)floatArray_getitem(arg1,arg2);
    
    resultobj = PyFloat_FromDouble(result);
    return resultobj;
    fail:
    return NULL;
}


static PyObject *_wrap_floatArray___setitem__(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    floatArray *arg1 = (floatArray *) 0 ;
    int arg2 ;
    float arg3 ;
    PyObject * obj0 = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"Oif:floatArray___setitem__",&obj0,&arg2,&arg3)) goto fail;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_floatArray,SWIG_POINTER_EXCEPTION | 0 )) == -1) SWIG_fail;
    floatArray_setitem(arg1,arg2,arg3);
    
    Py_INCREF(Py_None); resultobj = Py_None;
    return resultobj;
    fail:
    return NULL;
}


static PyObject *_wrap_floatArray_cast(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    floatArray *arg1 = (floatArray *) 0 ;
    float *result;
    PyObject * obj0 = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"O:floatArray_cast",&obj0)) goto fail;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_floatArray,SWIG_POINTER_EXCEPTION | 0 )) == -1) SWIG_fail;
    result = (float *)floatArray_cast(arg1);
    
    resultobj = SWIG_NewPointerObj((void *) result, SWIGTYPE_p_float, 0);
    return resultobj;
    fail:
    return NULL;
}


static PyObject *_wrap_floatArray_frompointer(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    float *arg1 = (float *) 0 ;
    floatArray *result;
    PyObject * obj0 = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"O:floatArray_frompointer",&obj0)) goto fail;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_float,SWIG_POINTER_EXCEPTION | 0 )) == -1) SWIG_fail;
    result = (floatArray *)floatArray_frompointer(arg1);
    
    resultobj = SWIG_NewPointerObj((void *) result, SWIGTYPE_p_floatArray, 0);
    return resultobj;
    fail:
    return NULL;
}


static PyObject * floatArray_swigregister(PyObject *self, PyObject *args) {
    PyObject *obj;
    if (!PyArg_ParseTuple(args,(char*)"O", &obj)) return NULL;
    SWIG_TypeClientData(SWIGTYPE_p_floatArray, obj);
    Py_INCREF(obj);
    return Py_BuildValue((char *)"");
}
static PyMethodDef SwigMethods[] = {
	 { (char *)"swilkf", _wrap_swilkf, METH_VARARGS },
	 { (char *)"new_intp", _wrap_new_intp, METH_VARARGS },
	 { (char *)"delete_intp", _wrap_delete_intp, METH_VARARGS },
	 { (char *)"intp_assign", _wrap_intp_assign, METH_VARARGS },
	 { (char *)"intp_value", _wrap_intp_value, METH_VARARGS },
	 { (char *)"intp_cast", _wrap_intp_cast, METH_VARARGS },
	 { (char *)"intp_frompointer", _wrap_intp_frompointer, METH_VARARGS },
	 { (char *)"intp_swigregister", intp_swigregister, METH_VARARGS },
	 { (char *)"new_floatp", _wrap_new_floatp, METH_VARARGS },
	 { (char *)"delete_floatp", _wrap_delete_floatp, METH_VARARGS },
	 { (char *)"floatp_assign", _wrap_floatp_assign, METH_VARARGS },
	 { (char *)"floatp_value", _wrap_floatp_value, METH_VARARGS },
	 { (char *)"floatp_cast", _wrap_floatp_cast, METH_VARARGS },
	 { (char *)"floatp_frompointer", _wrap_floatp_frompointer, METH_VARARGS },
	 { (char *)"floatp_swigregister", floatp_swigregister, METH_VARARGS },
	 { (char *)"new_floatArray", _wrap_new_floatArray, METH_VARARGS },
	 { (char *)"delete_floatArray", _wrap_delete_floatArray, METH_VARARGS },
	 { (char *)"floatArray___getitem__", _wrap_floatArray___getitem__, METH_VARARGS },
	 { (char *)"floatArray___setitem__", _wrap_floatArray___setitem__, METH_VARARGS },
	 { (char *)"floatArray_cast", _wrap_floatArray_cast, METH_VARARGS },
	 { (char *)"floatArray_frompointer", _wrap_floatArray_frompointer, METH_VARARGS },
	 { (char *)"floatArray_swigregister", floatArray_swigregister, METH_VARARGS },
	 { NULL, NULL }
};


/* -------- TYPE CONVERSION AND EQUIVALENCE RULES (BEGIN) -------- */

static void *_p_intpTo_p_int(void *x) {
    return (void *)((int *)  ((intp *) x));
}
static void *_p_floatpTo_p_float(void *x) {
    return (void *)((float *)  ((floatp *) x));
}
static void *_p_floatArrayTo_p_float(void *x) {
    return (void *)((float *)  ((floatArray *) x));
}
static swig_type_info _swigt__p_float[] = {{"_p_float", 0, "float *", 0},{"_p_float"},{"_p_floatp", _p_floatpTo_p_float},{"_p_floatArray", _p_floatArrayTo_p_float},{0}};
static swig_type_info _swigt__p_floatp[] = {{"_p_floatp", 0, "floatp *", 0},{"_p_floatp"},{0}};
static swig_type_info _swigt__p_floatArray[] = {{"_p_floatArray", 0, "floatArray *", 0},{"_p_floatArray"},{0}};
static swig_type_info _swigt__p_intp[] = {{"_p_intp", 0, "intp *", 0},{"_p_intp"},{0}};
static swig_type_info _swigt__p_int[] = {{"_p_int", 0, "int *", 0},{"_p_intp", _p_intpTo_p_int},{"_p_int"},{0}};

static swig_type_info *swig_types_initial[] = {
_swigt__p_float, 
_swigt__p_floatp, 
_swigt__p_floatArray, 
_swigt__p_intp, 
_swigt__p_int, 
0
};


/* -------- TYPE CONVERSION AND EQUIVALENCE RULES (END) -------- */

static swig_const_info swig_const_table[] = {
{0}};

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C"
#endif
SWIGEXPORT(void) SWIG_init(void) {
    static PyObject *SWIG_globals = 0; 
    static int       typeinit = 0;
    PyObject *m, *d;
    int       i;
    if (!SWIG_globals) SWIG_globals = SWIG_newvarlink();
    m = Py_InitModule((char *) SWIG_name, SwigMethods);
    d = PyModule_GetDict(m);
    
    if (!typeinit) {
        for (i = 0; swig_types_initial[i]; i++) {
            swig_types[i] = SWIG_TypeRegister(swig_types_initial[i]);
        }
        typeinit = 1;
    }
    SWIG_InstallConstants(d,swig_const_table);
    
}

