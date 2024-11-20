# Graph Cycle Detection Tests

## Test 1: Basic Cycle Detection

### Input Graph
```
1 -> 2 : 10, 2 -> 3 : 20, 
3	 -> 4 : 15, 
3 ->  5 :5, 
1->1 : 4,
```

### Expected Output
- **Detected Cycles**:
  - **Cycle 1**: [1 -> 1]
    - **Cost**: 4
- **Non-Cyclic Connections**:  
  - Path: [1 -> 2 -> 3 -> 4]  
  - Path: [1 -> 2 -> 3 -> 5]

---

## Test 2: Graph with Added Noise

### Input Graph
```
1 -> 2 : 10 , 2 -> 3: 20, 3->4 :15,
3-> 5: 5,
1 -> 1: 4 , 5 -> 1: 8,
```

### Expected Output
- **Detected Cycles**:
  - **Cycle 1**: [1 -> 1]
    - **Cost**: 4
  - **Cycle 2**: [1 -> 2 -> 3 -> 5 -> 1]
    - **Cost**: 43
- **Non-Cyclic Connections**:
  - Path: [1 -> 2 -> 3 -> 4]

---

## Test 3: Sparse Graph

### Input Graph
```
1 -> 2 : 10 ,
2->3:20,
3 -> 4 :15
```

### Expected Output
- **No Cycles Detected**
- **Paths**:
  - Path: [1 -> 2 -> 3 -> 4]
