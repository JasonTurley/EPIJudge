#include <vector>
#include "test_framework/generic_test.h"
using std::vector;

void ApplyPermutation(vector<int>* perm_ptr, vector<int>* A_ptr) {
    vector<int>& perm = *perm_ptr;
    vector<int>& A = *A_ptr;

    for (size_t i = 0; i < A.size(); i++) {
        while (i != perm[i]) {
            std::swap(A[i], A[perm[i]]);
            std::swap(perm[i], perm[perm[i]]);
        }
    }
}

vector<int> ApplyPermutationWrapper(vector<int> perm, vector<int> A) {
  ApplyPermutation(&perm, &A);
  return A;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"perm", "A"};
  return GenericTestMain(args, "apply_permutation.cc", "apply_permutation.tsv",
                         &ApplyPermutationWrapper, DefaultComparator{},
                         param_names);
}
