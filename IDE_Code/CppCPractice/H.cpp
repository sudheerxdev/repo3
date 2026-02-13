function matrixMultiply(A, B):
    n = size of matrices A, B
    if n == 1:
        return A * B  // Base case

    // Divide
    partition A, B, and C into submatrices
    A11, A12, A21, A22 = partitions of A
    B11, B12, B21, B22 = partitions of B
    C11, C12, C21, C22 = partitions of C

    // Conquer
    P1 = matrixMultiply(A11, B11)
    P2 = matrixMultiply(A12, B21)
    P3 = matrixMultiply(A11, B12)
    P4 = matrixMultiply(A12, B22)
    P5 = matrixMultiply(A21, B11)
    P6 = matrixMultiply(A22, B21)
    P7 = matrixMultiply(A21, B12)
    P8 = matrixMultiply(A22, B22)

    // Combine
    C11 = P1 + P2
    C12 = P3 + P4
    C21 = P5 + P6
    C22 = P7 + P8

    return C
