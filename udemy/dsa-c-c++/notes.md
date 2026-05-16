# DSA with C/C++ - Comprehensive Notes

---

## Table of Contents

1. [Arrays](#arrays)
2. [Structs & Padding](#structs--padding)
3. [Pointers](#pointers)
4. [Pointers to Structs](#pointers-to-structs)
5. [References](#references)
6. [Passing Objects to Reference Parameters](#passing-objects-to-reference-parameters)
7. [Functions & Parameter Passing](#functions--parameter-passing)
8. [Classes in C++](#classes-in-c)
9. [Strings & Memory Profiling](#strings--memory-profiling)
10. [reinterpret_cast vs C-Style Casts](#reinterpret_cast-vs-c-style-casts)
11. [Byte-Level Pointer Arithmetic](#byte-level-pointer-arithmetic)
12. [Stack vs. Heap Memory](#stack-vs-heap-memory)
13. [Physical vs. Logical Data Structures](#physical-vs-logical-data-structures)
14. [Abstract Data Types (ADT)](#abstract-data-types-adt)
15. [Time and Space Complexity](#time-and-space-complexity)
16. [General Best Practices](#general-best-practices)

---

## Arrays

- Arrays are **contiguous blocks of memory** for elements of the same type.
- `sizeof(arr)` gives total bytes (e.g., `int arr[5]` is usually 20 bytes).
- **Partial initialization:** `int arr1[5] = {1};` sets the first element to 1, rest are zero.
- **Variable-length arrays** (`int arr2[n];`) are allowed in C99, but **not standard C++**.
- **Range-based for loops** require C++11 or later.

### Code Example

```cpp
int arr[5] = {1, 2, 3, 4, 5};
cout << "size of arr: " << sizeof(arr) << endl; // 20 bytes

int arr1[5] = {1};
// arr1[0] = 1, arr1[1] = 0, arr1[2] = 0, arr1[3] = 0, arr1[4] = 0

int n = 8;
int arr2[n]; // Variable-length array (C99 only, not standard C++)
```

### Key Points

- When an array is passed to a function, it **decays to a pointer** to the first element.
- `sizeof(arr)` inside a function gives the **size of the pointer** (typically 4 or 8 bytes), not the array.
- To get the number of elements: `int n = sizeof(arr) / sizeof(arr[0]);`

---

## Structs & Padding

- Structs group related variables under one name.
- The compiler adds **padding** for alignment, making struct size larger than the sum of members.
- Padding ensures each member is stored at a memory address suitable for its type (improves CPU performance).

### Code Example

```cpp
struct Rectangle {
    int length;   // 4 bytes
    int breadth;  // 4 bytes
    char title;   // 1 byte
};
// sizeof(Rectangle) = 12 bytes (not 9!) due to padding
```

### Key Points

- Always use `sizeof()` to check actual struct size.
- **Member order** in structs affects padding and total size.
- Structs can be initialized globally or locally.
- Arrays of structs can be created and iterated:

```cpp
struct Rectangle r2[5] = {{1,2}, {3,4}, {5,6}, {7,8}, {9,10}};
for (size_t i = 0; i < sizeof(r2)/sizeof(r2[0]); i++) {
    cout << "Area: " << r2[i].length * r2[i].breadth << endl;
}
```

---

## Pointers

- Pointers are variables that **store memory addresses**.
- Used to access and manipulate **heap memory** (dynamically allocated).
- The pointer variable itself is stored in **stack memory**, but it points to a location in heap memory.
- Pointer size depends on architecture (commonly **8 bytes on 64-bit** systems).

### Declaration & Usage

```cpp
int a = 10;
int *p;
p = &a;       // p stores the address of a

cout << *p;   // Dereferences p → prints 10
*p = 20;      // Changes value of a through pointer p
```

### Dynamic Memory Allocation

#### C Style (malloc/free)

```cpp
int *q = (int *)malloc(5 * sizeof(int)); // Allocates 5 ints on heap
*q = 1;
*(q + 1) = 2;  // Pointer arithmetic: q+1 = q + 1*sizeof(int) bytes
*(q + 2) = 3;
free(q);        // MUST free heap memory
```

#### C++ Style (new/delete)

```cpp
int *r = new int[5];  // Allocates 5 ints on heap
r[0] = 10;
r[1] = 20;
delete[] r;           // MUST delete heap memory
```

### Important Notes

- `malloc()` returns `void*` — in C++ you **must cast** it to the correct type.
- In C, you can assign `void*` to any pointer type without a cast.
- Array names can be used as pointers to their first element (but are not pointers themselves).
- Printing addresses: use `%p` in `printf` and cast to `(void*)`.

---

## Pointers to Structs

- You can create pointers to structs: `struct Rectangle *p;`
- Use `->` to access members via pointer: `p->length`
- Equivalent syntax: `(*p).length`

### Code Example

```cpp
struct Rectangle r1 = {10, 5};
struct Rectangle *p = &r1;

cout << p->length;   // 10
cout << p->breadth;  // 5

p->length = 20;      // Modifies r1.length through pointer
```

### Dynamic Allocation of Structs

```cpp
struct Rectangle *r2 = (struct Rectangle *)malloc(sizeof(struct Rectangle));
r2->length = 15;
r2->breadth = 7;
free(r2);  // Always free dynamically allocated structs
```

---

## References

- References are **aliases** (another name) for existing variables.
- Must be **initialized when declared** and cannot be changed to refer to another variable.
- Do **not** occupy separate memory; just another name for the variable.
- **Not pointers:** cannot be null, do not require dereferencing.

### Code Example

```cpp
int a = 10;
int &ref1 = a;   // ref1 is a reference to a

ref1 = 20;       // Changes value of a
cout << a;       // Prints 20
```

### Key Differences from Pointers

| Feature | Reference | Pointer |
|---------|-----------|---------|
| Can be null | No | Yes |
| Can be reassigned | No | Yes |
| Requires dereferencing | No | Yes (`*p`) |
| Occupies memory | No (alias) | Yes |

---

## Passing Objects to Reference Parameters

When a function parameter is declared as a reference (e.g., `const string& s`), the caller does **not** need any special syntax — just pass the object normally. The compiler handles the reference binding behind the scenes.

### How It Works Step by Step

1. In `main()`, `str1` is a normal `string` object on the stack with a real address (e.g., `0x00F3FC40`).
2. When you call `inspectString("str1", str1)`, the compiler passes the **address** of `str1` to the function.
3. Inside `inspectString()`, `s` is **not a copy** — it's an alias backed by a hidden pointer. Every use of `s` auto-dereferences that pointer to access the original `str1`.
4. `&s` inside the function gives the address of the **original** `str1`, not a local copy.

### Code Example

```cpp
// What you write:
string str1 = "Hello";
inspectString("str1", str1);        // no & needed at call site

// What the compiler generates (conceptually):
inspectString("str1", &str1);       // passes address of str1

// Inside the function:
void inspectString(const char* name, const string& s) {
    s.length();   // compiler generates: (*hidden_ptr).length()
    &s;           // returns 0x00F3FC40 — address of original str1
}
```

### Reference vs Pointer Syntax Comparison

| | Pointer | Reference |
|--|---------|-----------|
| Declaration | `const string* s` | `const string& s` |
| Call site | `inspectString("str1", &str1)` | `inspectString("str1", str1)` |
| Access inside | `s->length()` | `s.length()` |

### Without the Reference (`const string s` — no `&`)

- The compiler would **copy** the entire string object into a new local variable.
- For a 1180-char string, that means allocating heap memory for the copy — wasteful.

### Key Takeaway

- The `&` in the function signature tells the compiler "bind a reference."
- At the call site, you just pass the variable normally — the compiler does the rest.
- **No copy is made.** The function operates directly on the original object.

---

## Functions & Parameter Passing

### Three Ways to Pass Parameters

#### 1. Pass by Value (Copy)

```cpp
void swap1(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}
// Does NOT modify original variables — works on copies
```

#### 2. Pass by Pointer (Address)

```cpp
int swap2(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}
// Call: swap2(&x, &y); — DOES modify original variables
```

#### 3. Pass by Reference (C++ only)

```cpp
int swap3(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    return 0;
}
// Call: swap3(x, y); — DOES modify original variables
```

### Arrays as Function Arguments

- Arrays **decay to pointers** when passed to functions.
- `sizeof(arr)` inside the function gives pointer size, not array size.
- To return an array from a function, allocate on heap with `new` and return pointer:

```cpp
int *newArray(int arr[], int n) {
    int *newArr = new int[n];
    for (int i = 0; i < n; i++)
        newArr[i] = arr[i];
    return newArr;
}
// Caller must: delete[] newArr;
```

### Structs as Function Arguments

```cpp
int area1(struct Rectangle *r)  { return r->length * r->breadth; }  // By pointer
int area2(struct Rectangle r)   { return r.length * r.breadth; }    // By value (copies)
int area3(struct Rectangle &r)  { return r.length * r.breadth; }    // By reference
```

- **By value:** copies the entire struct (slow for large structs).
- **By pointer/reference:** no copy, works with original (preferred for large structs).
- When a struct contains a pointer, passing by value copies the pointer but **not** the data it points to (shallow copy).

---

## Classes in C++

- Classes encapsulate data (members) and operations (methods) together.
- Use **access specifiers**: `private`, `public`, `protected`.
- **Constructors** initialize objects; **destructors** clean up.

### Code Example

```cpp
class Rectangle {
private:
    int length;
    int breadth;
public:
    Rectangle(int l, int b);    // Constructor
    ~Rectangle();               // Destructor

    int area() { return length * breadth; }
    void modifyDimensions(int l, int b) {
        length = l;
        breadth = b;
    }
};

Rectangle::Rectangle(int l, int b) {
    length = l;
    breadth = b;
}

Rectangle::~Rectangle() {
    cout << "Rectangle destroyed" << endl;
}

// Usage:
Rectangle r1(10, 5);
cout << r1.area();          // 50
r1.modifyDimensions(15, 7);
cout << r1.area();          // 105
```

---

## Strings & Memory Profiling

### Small String Optimization (SSO)

- Short strings (typically ≤ 15 chars) are stored **inside** the `std::string` object itself (on the stack).
- Longer strings allocate memory on the **heap**.
- `sizeof(string)` gives the object size (fixed), while `length()` gives character count.
- `capacity()` shows how much space is allocated before reallocation is needed.

### Detecting SSO

```cpp
bool isSSO(const string& s) {
    const void* objStart = &s;
    const void* objEnd   = reinterpret_cast<const char*>(&s) + sizeof(s);
    const void* dataPtr  = s.data();
    return (dataPtr >= objStart && dataPtr < objEnd);
}
```

---

## reinterpret_cast vs C-Style Casts

`reinterpret_cast<const char*>(&s)` and `(const char*)(&s)` produce **identical results** — both convert a `string*` address to a `char*` for byte-level pointer arithmetic.

### Why `reinterpret_cast` Is Preferred in C++

| Reason | Details |
|--------|---------|
| **Explicit intent** | Clearly says "I'm reinterpreting the bit pattern of this pointer." A C-style cast `(char*)` is ambiguous — the compiler may apply `static_cast`, `const_cast`, or `reinterpret_cast` depending on context. |
| **Searchable** | You can grep for `reinterpret_cast` to find all "dangerous" casts. C-style casts are much harder to search for. |
| **Safer** | `reinterpret_cast` won't accidentally strip `const`. A C-style cast like `(char*)(&s)` would silently drop `const`, which could lead to bugs. You'd need a separate `const_cast` to remove `const`. |

---

## Byte-Level Pointer Arithmetic

In C/C++, pointer arithmetic **scales by the size of the pointed-to type**:

```cpp
int* p;
p + 1;       // moves forward by sizeof(int) = 4 bytes

string* p;
p + 1;       // moves forward by sizeof(string) = 32 or 40 bytes
```

To advance by an **exact number of bytes**, cast to `char*` (`sizeof(char) == 1`, guaranteed):

```cpp
reinterpret_cast<const char*>(&s) + sizeof(s);
```

### Step by Step

```cpp
&s                                     // type: const string*  (address 0x100)
reinterpret_cast<const char*>(&s)      // type: const char*    (still 0x100, but +N = N bytes)
+ sizeof(s)                            // 0x100 + 40 = 0x128   (end of object)
```

### Without the Cast (Wrong)

```cpp
const string* p = &s;
p + 1;      // 0x100 + sizeof(string) = 0x128 (happens to work for +1, but not general)
p + 40;     // 0x100 + 40*sizeof(string) = way too far!
```

### Usage in `isSSO()`

This technique calculates the end address of the string object, then checks if `s.data()` falls within `[objStart, objEnd)` — i.e., whether the char buffer lives inside the object (SSO/stack) or on the heap.

You could also use `uint8_t*` or `unsigned char*` instead of `char*` — same result. `char*` is the conventional choice.

---

## Stack vs. Heap Memory

### The Stack: The Organized Desk

| Property | Details |
|----------|---------|
| Structure | LIFO (Last In, First Out) |
| Management | 100% automatic |
| Speed | Extremely fast (just moving a stack pointer) |
| Size | Small / Fixed (few MB) |
| Data Lifespan | Temporary (dies when function ends) |
| Best For | Local variables, small arrays, function calls |
| Risk | **Stack Overflow** (too much data or infinite recursion) |

```cpp
void calculateTotal() {
    int price = 10;          // pushed onto stack
    int tax = 2;             // pushed onto stack
    int total = price + tax; // pushed onto stack
} // All destroyed instantly when function ends
```

### The Heap: The Storage Warehouse

| Property | Details |
|----------|---------|
| Structure | Unstructured (data anywhere there's free space) |
| Management | 100% manual |
| Speed | Slower (OS searches for free space) |
| Size | Massive / Variable (limited by physical RAM) |
| Data Lifespan | Persistent (lives until explicitly freed) |
| Best For | Large arrays, linked lists, trees, objects of unknown size |
| Risk | **Memory Leak** (forgetting to free) |

```cpp
void createList() {
    int* ptr = (int*)malloc(100 * sizeof(int)); // Heap allocation
    // ... use the data ...
    free(ptr); // MUST manually free!
}
```

### Segmentation Fault Example

```c
int arr1[10000000] = {1, 1}; // Stack overflow → segmentation fault
// Exceeds stack size limit. Use heap allocation instead.
```

---

## Physical vs. Logical Data Structures

### The Big Picture: Materials vs. Blueprints

- **Physical Data Structures** = raw materials (how/where data is placed in memory).
- **Logical Data Structures** = blueprints (how you interact with data, what the rules are).

### Physical Data Structures

#### Arrays

- A single, **continuous block** of memory.
- Analogy: A row of lockers — all same size, side by side.
- **Pros:** Extremely fast random access (O(1) by index).
- **Cons:** Fixed size; inserting/resizing requires copying everything.

#### Linked Lists

- A collection of **separate, non-continuous** memory blocks (nodes) connected by pointers.
- Each node holds the **data** and the **address of the next node**.
- **Pros:** Dynamic size; easy insertion/deletion.
- **Cons:** No random access; extra memory for pointers.

---

## Abstract Data Types (ADT)

- An ADT is defined by its **data representation** and the **operations** allowed on that data.
- Users don't need to know implementation details — just the interface.

### Key Characteristics

- **Data Representation:** How data is stored (array, linked list, etc.)
- **Operations:** Adding, removing, searching, etc.
- **Abstraction:** Users create instances without worrying about internals.

### Example: List as an ADT

- Can be implemented as an array or linked list.
- Supported operations: add, remove, search, get size.
- The user doesn't care which implementation is used — just the behavior.

### Benefits

- Fosters better design and **modularity**.
- Separates "what" from "how".
- Fundamental data structures (arrays, linked lists) are implementations of ADTs.

---

## Time and Space Complexity

### The Chef Analogy

- **Time Complexity:** "If I cook for 100 people instead of 1, how much longer will it take?"
- **Space Complexity:** "How many extra pots and pans will I need?"
- Measured by how resources **scale** as input size (`n`) grows, not in absolute seconds/bytes.

### Big O Notation (Time Complexity)

Describes the **upper limit (worst-case)** of how an algorithm's time grows.

**Crucial Rule:** Drop constants. `12n + 1` → `O(n)`

| Notation | Name | Description | Example |
|----------|------|-------------|---------|
| O(1) | Constant | Same time regardless of input size | `array[0]` |
| O(log n) | Logarithmic | Cuts remaining work in half each step | Binary Search |
| O(n) | Linear | Time proportional to input | Simple loop through array |
| O(n²) | Quadratic | Nested loops; data doubles → time × 4 | Bubble sort |

### O(1): Constant Time

```cpp
print(array[0]); // Always one operation, regardless of array size
```

### O(log n): Logarithmic Time

- Cuts the problem in half each step.
- Dictionary doubles in size → only ONE extra step needed.
- Example: **Binary Search**.

### O(n): Linear Time

```cpp
for (int i = 0; i < n; i++) {
    print(array[i]); // Visits each element once
}
```

### O(n²): Quadratic Time

```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        // Nested loop: n × n operations
    }
}
```

### Space Complexity

- Analyzes how much **extra RAM/memory** an algorithm requires based on input size.
- If an algorithm creates a copy of the input → O(n) space.
- If it uses only a few variables → O(1) space.

---

## General Best Practices

- Always **match** allocation and deallocation methods:
  - `malloc()` → `free()`
  - `new` → `delete`
  - `new[]` → `delete[]`
- Use correct format specifiers for printing pointers and values.
- Member order in structs affects padding and total size.
- Prefer passing large structs/arrays by **reference or pointer** to avoid copying overhead.
- Never access memory after freeing it (dangling pointer).
- Allocate large arrays on the **heap** to avoid stack overflow.

---
