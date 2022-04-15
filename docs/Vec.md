# Vec#< T >
Holds # values of type `T`.  (# is 2, 3 or 4)
Also allows to do operations on them (all the arithmetical operators supported):
- `=`, `+`, `-`, `*`, `/`, `%`
- `+=`, `-=`, `*=`, `/=`, `%=`


__Example of use:__
```cpp
OWL::Vec2<int> myValue(1); /* initializes a 2d vector of type int, with both values equal 1 */
OWL::Vec2<unsigned int> copyingAndCastingExample = myValue; /* initializes a 2d vector of type unsigned int with both values equal to the ones in myValue */
OWL::Vec2<float> addingExample = myValue + copyingAndCastingExample; /* initializes a 2d vector of type float equal to the addition of myValue and copyingAndCastingExample */
addingExample += OWL::Vec2<float>(2.0f); /* adds 2 to addingExample */
OWL::Vec2<double> mutliplyingExample = addingExample * myValue; /* initializes a 2d vector of type double, which is equal to the multiplication of addingExample and myValue */
mutliplyingExample *= OWL::Vec2<float>(3.0f); /* multiplies the multiplyingExample by 3 */

OWL::Vec3<int> myOtherValue(10, 60, 45); /* initializes a 3d vector of type int */
myOtherValue *= OWL::Vec3<unsigned int>(4); /* multiplies the values of myValue by 4 */
myOtherValue /= OWL::Vec3<float>(2.0f); /* divides the values of myValue by 2 */

OWL::Vec4<char> anotherValue(6, 7, 6, 7); /* initializes a 4d vector of type char */
anotherValue = OWL::Vec4<char>(255) - anotherValue; /* makes anotherValue equal to {255, 255, 255, 255} - it's value */
```
Other thing in vector types is that you can choose a value via it's index using `[]` operator, or via letter assigned to it:
- `OWL::Vec#<T>[0]` / `OWL::Vec#<T>.x` / `OWL::Vec#<T>.r` / `OWL::Vec#<T>.u`
- `OWL::Vec#<T>[1]` / `OWL::Vec#<T>.y` / `OWL::Vec#<T>.g` / `OWL::Vec#<T>.v`
- `OWL::Vec#<T>[2]` / `OWL::Vec#<T>.z` / `OWL::Vec#<T>.b`
- `OWL::Vec#<T>[3]` / `OWL::Vec#<T>.w` / `OWL::Vec#<T>.a`

Yes - `u` and `v` values are for people who want to use the vector for texturing, and
`r`, `g`, `b` and `a` are for people who want to use the vector for coloring (It's used in SoftwareContext).

__Example of use:__
```cpp
OWL::Vec4<int> exampleVector;
exampleVector.u = 56;
exampleVector[1] = 45;
exampleVector.z = 80;
exampleVector.a = 77;

std::cout << "[0]: " << exampleVector[0] << " " << exampleVector.x << " " << exampleVector.r << " " << exampleVector.u << "\n";
std::cout << "[1]: " << exampleVector[1] << " " << exampleVector.y << " " << exampleVector.g << " " << exampleVector.v << "\n";
std::cout << "[2]: " << exampleVector[2] << " " << exampleVector.z << " " << exampleVector.b << "\n";
std::cout << "[3]: " << exampleVector[3] << " " << exampleVector.w << " " << exampleVector.a << "\n";

/* These should display 4 the same values each */
```

Vector types also allow logical operations (all the logical operators supported):
- `==`, `!=`, `<`, `<=`, `>`, `>=`

__Example of use:__
```cpp
OWL::Vec4<float> example1(1.0f, 2.0f, 3.0f, 4.0f);
OWL::Vec4<double> example2(0.1f, 0.2f, 0.3f, 0.4f);

bool check1 = example1 > example2; /* true */
bool check2 = example1 < example2; /* false */
bool check3 = example1 >= example2; /* true */
bool check4 = example1 <= example2; /* false */
bool check5 = example1 == example2; /* false */
bool check6 = example1 != example2; /* true */
```

If you don't like using `<T>` to specify what type do you want to use in your vector, you can use one of our typedefs:
- `Vec#<int>` = `Vec#i`
- `Vec#<unsigned int>` = `Vec#ui`
- `Vec#<char>` = `Vec#b`
- `Vec#<unsigned char>` = `Vec#ub`
- `Vec#<float>` = `Vec#f`
- `Vec#<double>` = `Vec#d`

__Example of use:__
```cpp
OWL::Vec4i intVector;
OWL::Vec3ui unsignedIntVector;
OWL::Vec2b charVector;
OWL::Vec4ub unsignedCharVector;
OWL::Vec3f floatVector;
OWL::Vec2d doubleVector;
```
