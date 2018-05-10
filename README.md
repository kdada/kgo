# kgo

### Basic

#### Data Types

| Type   | Bits | Range                                                    |
|--------|------|----------------------------------------------------------|
| bool   | 8    | true, false                                              |
| char   | 8    | [−127, +127]                                             |
| byte   | 8    | [0, 255]                                                 |
| short  | 16   | [−32,767, +32,767]                                       |
| ushort | 16   | [0, 65,535]                                              |
| int    | 32   | [−2,147,483,647, +2,147,483,647]                         |
| uint   | 32   | [0, 4,294,967,295]                                       |
| long   | 64   | [−9,223,372,036,854,775,807, +9,223,372,036,854,775,807] |
| ulong  | 64   | [0, +18,446,744,073,709,551,615]                         |
| float  | 32   | +- [1.175494351e-38, 3.402823466e+38]                    |
| double | 64   | +- [2.2250738585072014e-308, 1.7976931348623158e+308]    |


#### Operators


| Priority | Operator         | Description          |
|----------|------------------|----------------------|
|    MIN   | = += -= *= /= %= | Assignment operators |
|          | && || !          | Logical operators    |
|          | == > >= < <= !=  | Relational operators |
|          | + - * / %        | Arithmetic operators |
|    MAX   | & | ^ ~ << >>    | Bitwise Operators    |

#### Statements

```
var a = 1         // long = 1
var b = int(2)    // int = 2
var c = true      // bool = 1
var d = 'd'       // char = 'd'
var e = "str"     // *char = 's' 't' 'r' '\0'
var f = `multiple // *char = "multiple\nlines\n"
lines
`
const g = 1       // immutable long = 1
```


### Control Flow

#### if

```
if expression {
	
}

if expression {
	
} else {

}

if expression {
	
} else if expression {

}
```

#### switch

```
switch expression {
	case constant-expression[, constant-expression]:
		[fallthrough]
	[case constant-expression:]
	[default:]
}


switch {
	case expression:
		[fallthrough]
	[case expression:]
	[default:]
}
```

#### for
```
for expression {
	[break]
	[continue]
}

for expression; expression; expression {
	[break]
	[continue]
}
```

### Enum

```
enum(int) Error {
	WrongA = 1
	WrongB       // WrongB = WrongA + 1
	WrongC = 5
}
```

### Struct

```
struct StructA {
	FieldA int
}

func (a *StructA) MethodA(paramA int, paramB bool) (int, bool) {
}

```

### Function

```
func SomeFunction(paramA int, paramB bool) (int, bool) {
}

```

### Package
```
package some

import (
	"lib"
	"../pkg/another"
	anotherlib "../pkg/lib"
)
```
