1. compilation
	```
	gcc -o prog prog.c
	```
2. linking --- looking for needed stuff


```
[sasha@honeypot ~uni/OOP/_lab/_lab-8]$ nm main.o
                 U _GLOBAL_OFFSET_TABLE_
0000000000000000 T main
                 U _Z6my_addii
                 U _ZNSolsEi
                 U _ZNSolsEPFRSoS_E
0000000000000000 r _ZNSt8__detail30__integer_to_chars_is_unsignedIjEE
0000000000000001 r _ZNSt8__detail30__integer_to_chars_is_unsignedImEE
0000000000000002 r _ZNSt8__detail30__integer_to_chars_is_unsignedIyEE
                 U _ZSt4cout
                 U _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES
6_
[sasha@honeypot ~uni/OOP/_lab/_lab-8]$ nm main.o
                 U _GLOBAL_OFFSET_TABLE_
0000000000000000 T main
                 U _Z6my_addii
                 U _ZNSolsEi
                 U _ZNSolsEPFRSoS_E
0000000000000000 r _ZNSt8__detail30__integer_to_chars_is_unsignedIjEE
0000000000000001 r _ZNSt8__detail30__integer_to_chars_is_unsignedImEE
0000000000000002 r _ZNSt8__detail30__integer_to_chars_is_unsignedIyEE
                 U _ZSt4cout
                 U _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
		 ```
		 u unresolved
