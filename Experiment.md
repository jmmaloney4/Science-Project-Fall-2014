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

Bubble Sort goes through the entire list, comparing adjacent elements, and swapping them if needed. This is very inneficent, however very simple to implement. The theroretical time complexity of Bubble Sort is O(n<sup>2</sup>), however it's experimentally about 6 times slower than Insertion Sort.

### Merge Sort

Merge Sort splits the list in half, then calls itself to sort each half. Then when each list is only one item, the list is sorted and it returns. Then it uses the fact that the first element is either the first element of the left hand list or the right hand list, and continues to combine the lists using this technique.

`| 2 | 5 | 1 | 7 | 3 | 0 |`

`| 2 | 5 | 1 |`   `| 7 | 3 | 0 |`

`| 1 | 2 | 5 |`    `| 0 | 3 | 7 |`

Now either, 1 or 0  are the begenning of the new, sorted, list, and based on the pattern, it would be 0. For the second element we again look at the first element in each list, which are now 1 and 3. We select 1, put it in the list, and repeat this for the rest of the elements. This gets us a thereoretical time complexity of O(n * log<sub>2</sub>(n)).
