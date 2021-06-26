# Victor

Victor is a C library which lets you using your data in linked-lists-type containers/vectors

With this library, you don't have to worry about manually allocating (or freeing) memory. Everything can be done using the given set of functions.

This library manages **circular**, **doubly-linked** lists

It lets you do the following operations:

- **Create** a list

- Get the list **size**

- **Sort** a list

- **Add data** to a list

  - At a given index (positive, or negative)

  - At the end of the list (append)

  - Through a pre-made node, or not

- **Display** a list's content

- **Free** memory

  - The list's head, and its nodes

  - The list, its nodes, and the data

____

## Why using this library

As you may know, C is quite a **low-level** programming language. It doesn't have dynamic memory management unlike its big brother C++.

This library was developped in order to **make life easier** to any dev who often manages big chunks of data.

To be more precise, this library was developped while my first and second year at EPITECH (_European Institure of Technology_). During those years, in order to fully comprehend memory principles, we programmed multiple projects using C language.

This library can also serve as a **source of inspiration** for any _EPITECH_ or _42_ student who would like to **code their own C containers**.

____

### Warning

If you are a first or second student in one of those schools, **DO NOT copy-paste the code**, you might find yourself in some very **unpleasant situations**...
