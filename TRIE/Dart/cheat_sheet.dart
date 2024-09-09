var x=stdin.readLineSync();
print(“I am $x”);
print(“I am {$x.toUpperCase()}”);


String quote = 'If you can\'t explain it simply,\nthen you don\'t understand it well enough.';
print(quote);
we can also use “““  ””” and write inside .Then those short form won’t trouble.

Additional Functions of string: 
length,contains(“to”),padLeft(10),padRight(10),trim(),trimLeft(),trimRight(),
split(“ ”)  will return list of words splitted based on space,
substring(initial index,final index+1).







int value = 42; 
int radix = 16; // hexadecimal representation 
String hexString = value.toRadixString(radix); print(hexString); // Output: 2a



for(int i=0;i<5;i++){
print(“hello ${i+1}”);
}


BigInt Longvalue;
Longvalue=BigInt.parse(‘6944858544454’);

double same for both;
num x=99.56; it handles both double,int.

var x=any type of value can be initialized and var will become that type and in future we can re-initialize with that type only.

dynamic x;
 x=any type of value can be initialized and reinitialized.

To indicate that a variable might have the value null, just add ?  because normally dart don’t accept it.
So If a function is null safety and argument called is with ? then we will check if it’s not null and call. 

To use some other value instead of null
func(apple??”red”);
Class same as c++;



****LIST****

var a=<int or dynamic or string or don’t write this part>[1,5,6,2];
a.add(23);
var b=[15,45];
b.addAll(a);
b.add(“ffd”); any types can be added.
b.insert(index,value); to add value at index.
b.insertAll(index,list); to add list at index;
print(“$b”);

var newList=[“new”, …a, …b] // also useful to add const map or listlike this
b[0]=9; to change value at index 0.

b.replaceRange(s,e,[5,6,55]) to replace range s to e with new list.
There is no restriction of s to e length be same as new replacement list length.


Remove functions:
remove(value),removeAt(index),removeLast(),
removeRange(s,e)
other important functions:
length,reversed,first,last,isEmpty,isNotEmpty,
elementAt(index),subList(s,exclusive index end)

*2 list can be checked if equal with ==


******SET******
Var st1={‘ami’, ‘tumi’, ‘he’ ,12, 5}
Var st2={12, 5}

st1.add(55);
add(),addAll(),contains(),remove()

var st3=st1.intersection/union(st2)
To restrict to one type use<> before{}.
For empty set use <type>{} must.if type not set it will become map.



******MAP*****
var map=Map(); //<dynamic,dynamic>
map[‘alu’]=20;
map[‘porata’]=10;
var map={
‘k1’:12,
‘k2’: ‘another’
} 
Value ,key depends on the declaration<> like below.
Map<int,String>mp=Map()

The functions of map are
isEmpty,isNotEmpty,length, keys,values,containsKey(key),containsValue(value),remove(key)


***final***
Final add at first of any data type it becomes final and that value can’t be changed.

final not need to be initialized .The moment it’s initialized later it becomes final value.
const need to be initialized.

const list can’t take add but final list can take add but for both no overwrite possible.


****condition****
if-else ,while same as c++.

*****use of comperator****
Here Dolphin is a class
int compareDolphins(Dolphin d1, Dolphin d2) {
  if (d1.length < d2.length) {
    return -1;
  } else if (d1.length > d2.length) {
    return 1;
  } else {
    return 0;
  }
}
List<Dolphin> dolphins = [ Dolphin(5), Dolphin(3), ]; 
dolphins.sort((d1, d2) => compareDolphins(d1, d2));




enum Blood{positive,negative}
Then the variable is defined as below:
Blood btype;
btype=Blood.positive; 

***********class**********
When you create custom classes in Dart, by default, two instances of the same class with identical properties are not considered equal. This is because Dart compares object references by default, not their content. This can lead to unexpected behavior, especially when using these objects in collections like Sets.
To solve this issue we have to override == operator and hashcode generator.

@override
Int get hashCode=>Object.hash(name,age);// class attributes

@override
bool operator ==(Object other)=>
identical(this,other)||other is Person&& name==other.name && age==other.age;


Now for set only one will be there if 2 person with same values and class appear.

class Person {
  final String _name;
  final List<Person>? _siblings;

  Person(String name, List<Person>? siblings)
      : _name = name,
        _siblings = UnmodifiableListView(siblings ?? []);

  String get name => _name;

  List<Person>? get siblings => _siblings;
}

**Stream async*,Iterable sync* structure same.
