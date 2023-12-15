складений ключ

## Як підписати зв'язок?

```sh
eralchemy -i <file> -o <meow>.dot
```

session.dot:

```sh
"студент" -- "сесія" [taillabel=<<FONT>0..N</FONT>>,label=<<FONT>lmao</FONT>>,headlabel=<<FONT>0..N</FONT>>];
```

```sh
dot session.dot -Tpng -o session.png
```
