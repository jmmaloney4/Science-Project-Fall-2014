# Abstract

# Materials
  - Computer (specs here)
  - The Source Code
  - [CMake](http://www.cmake.org/)
  - [Make](http://www.gnu.org/software/make/)

# Procedure
  1. Gather Materials
  2. Compile
    - `cmake .`
    - `make`
  3. Run Time Test
    - `./script/time.sh`

# Algorithms

### Insetion Sort
  
Insertion Sort sorts a list by taking each element of a list and *Inserting* it into the list in the correct place. This is costlier than Merge Sort, however experimentally, it seems to be more efficent than Bubble Sort. It has a thereoretical time complexity of O(n<sup>2</sup>).

### Bubble Sort

Bubble Sort goes through the entire list, comparing adjacent elements, and swapping them if needed. This is very inneficent, however very simple to implement. The theroretical time complexity of Bubble Sort is O(n<sup>2</sup>), but it is experimentally about 6 times slower than Insertion Sort.

### Merge Sort

Merge Sort splits the list in half, then calls itself to sort each half. Then when each list is only one item, the list is sorted and it returns.
