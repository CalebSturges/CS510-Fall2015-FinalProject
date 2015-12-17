#include <stdio.h>
#include "matrices.h"

int main(void) {

  // Construct a new 3x6 matrix
  MATRIX a = new_matrix(3,6);

  puts("Initial matrix:");
  print_matrix(&a);

  puts("Modified matrix:");
  set(&a, 1, 1, 20.0);
  set(&a, 2, 2, 40.0);
  set(&a, 0, 4, 60.0);
  set(&a, 2, 5, 80.0);
  print_matrix(&a);

  puts("Element a(2,2):");
  print_value(get(&a, 2, 2));
  puts("");
  puts("Element a(0,4):");
  print_value(get(&a, 0, 4));
  puts("");

  // Destruct matrix when done
  delete_matrix(a);

  return 0;
}
