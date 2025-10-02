# Deep-copy pointer

Subclass of std::unique_ptr which makes a deep copy of its contents upon copying.

Useful for holding objects that are uniquely allocated but copiable.

Using deep_copy_ptr allows types to have automatically generated default copy constructors and copy assignment operators if all their members are copiable, even if those members are dynamically allocated.
