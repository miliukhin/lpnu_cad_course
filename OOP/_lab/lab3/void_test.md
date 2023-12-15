# як тестувати порожнечу?

```
var string?
func some_func () -> void
{
	string = string + "a"
	return
}
```

```
func some_test (string:string) -> string
{
	return string + "a"
}
```

Якшо напишете юніт-тести, то

```
let s1 = "kaw"
assert=("kawa")
```
