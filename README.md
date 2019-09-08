Game of life implementation

_______________________
Comparison of implementation approaches

| |Neighbor counting approach|Neigbor notify approach|Unordered_map approach|
| --- | --- | --- | --- |
|200x200 matrix<br>10000 generations| 4.55 s| 0.68 s| 23.8s |


Neighbor counting approach - On every iteration for each cell number of live neighbors is counting

Neighbor notify approach - On each change of cell state its neighbors are notified. Number of live neighbor cells is saved in cell structure

Unordered_map approach - Only live cells and cells with nonzero live neighbors are saved in memory. On each iteration only these cells are checked.
