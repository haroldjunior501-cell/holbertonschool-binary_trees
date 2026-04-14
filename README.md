# holbertonschool-binary_trees

This repository contains C functions for binary tree exercises.

## Current tasks

- `0-binary_tree_node.c`: creates a binary tree node

## Data structure

```c
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};
```
