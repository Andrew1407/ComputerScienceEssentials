# ComputerScienceEssentials

Computer sciende c++ code examples of main concepts &amp; topics/

To launch a main just run a [bash script](./run.sh):

```bash
./run.sh
```

## Usage

To run a code example from available [content](#content) just use **[utils](./utils/utils.hpp)** namespace choosing a necessary function to call in main, for instance: *utils::useBinarySearch()*, or *utils::useSorting()*, etc. There's a bunch of code examples listed below; functions with the examples are also present in the utils header file.

## Content

### Datastructs

The repo contains implementation of two **[data containers](./datastructs/)** (lists):

+ **[stack](./datastructs/stackSelf.hpp)** (implementation's [here](./datastructs/stackSelf.cpp));
+ **[queue](./datastructs/queueSelf.hpp)** (implementation's [here](./datastructs/queueSelf.cpp));

### Sorting

The **[sorting](./sorting/sorting.hpp)** namescape contains a few implementations of well-known sorting algorithms, which are:

+ **[bubble sort](./sorting/bubble.cpp)**;
+ **[insertion sort](./sorting/insertion.cpp)**;
+ **[selection sort](./sorting/selection.cpp)**;

### Classes basic operations

The **[classes](./utils/classes/)** dir contains different cases of using classes and thier instances (objects):

+ **[abstract](./utils/classes/abstract.cpp)**;
+ **[dynamic classes](./utils/classes/classes.cpp)**;
+ **[diamond problem](./utils/classes/diamondProblem.cpp)**;
+ **[inherinace](./utils/classes/inheritance.cpp)**;
+ **[inner local classes](./utils/classes/innerLocalClasses.cpp)**;
+ **[multiple inheritance](./utils/classes/multipleInheritance.cpp)**;
+ **[operators overloading](./utils/classes/operators.cpp)**;

### OOP patterns

The **[patternsUsage](./utils/patternsUsage/)** dir contains some object-oriented patterns implementation and usecase examples:

+ **[abstract factory](./utils/patternsUsage/abstractFactory.cpp)**;
+ **[adapter](./utils/patternsUsage/adapter.cpp)**;
+ **[bridge](./utils/patternsUsage/bridge.cpp)**;
+ **[builder](./utils/patternsUsage/builder.cpp)**;
+ **[decorator](./utils/patternsUsage/decorator.cpp)**;
+ **[observer](./utils/patternsUsage/observer.cpp)**;
+ **[singleton](./utils/patternsUsage/singleton.cpp)**;
+ **[strategy](./utils/patternsUsage/strategy.cpp)**;
+ **[visitor](./utils/patternsUsage/visitor.cpp)**;
