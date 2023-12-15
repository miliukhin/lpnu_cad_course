You cannot use switch here; as the error says, const char* is not supported. It's a good thing, too, because comparing two C-strings through pointers only compares the pointers, not the strings they point to (consider "hello" == "world").

Even if it were, you're trying to compare your C-string to multicharacter literals, which is certainly not what you intended, not least of all because they have type int and an implementation-defined value; I guess you meant to write "SRAD", not 'SRAD'.

Since you're using C++, you should do this:

const std::string name = pAttr->Name();
const std::string value = pAttr->Value();

if (name == "SRAD") {
   double D = atof(value.c_str());  // use std::stod(value) in C++11
   // ...
}
else if (name == "DRAD") {
   // ...
}
else {
   // ...
}

(I also fixed your use of name in the initialisation of D; Remy's right — you must have meant value here since "SRAD" cannot possibly be interpreted as a double.)
