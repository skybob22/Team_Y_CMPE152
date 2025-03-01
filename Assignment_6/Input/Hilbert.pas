PROGRAM Hilbert (input, output);

{Use LU decomposition and back-substitution to invert matrices.
 A Hilbert matrix of size 5 serves as an example. Hilbert matrices
 are ill-conditioned and are notoriously difficult to invert accurately.
 This program computes the Hilbert matrix, inverts it, multiples the
 Hilbert matrix by its inverse (resulting in an approximation of the
 identity matrix), and then inverts the inverse (resulting in an
 approximation of the original Hilbert matrix.}

CONST
    MAX = 5;

TYPE
    vector = ARRAY [1..MAX]         OF real;
    intvector = ARRAY [1..MAX] OF integer;
    matrix = ARRAY [1..MAX, 1..MAX] OF real;

    why = (SINGULARMATRIX, ZEROROW, NOCONVERGENCE);

VAR
    ps      : intvector;  {global pivot index array}
    H       : matrix;                     {Hilbert matrix}
    Hinv    : matrix;                     {Hilbert matrix inverse}
    Z       : matrix;                     {Identity matrix}
    i, j, n : integer;
    qq       : integer;
    asdf    : real;

PROCEDURE singular(w : why);

    BEGIN
        CASE w OF
            SINGULARMATRIX : writeln('Singular matrix in decompose.');
            ZEROROW        : writeln('Matrix with zero row in decompose.');
            NOCONVERGENCE  : writeln('No convergence in improve.');
        END;
    END;

FUNCTION abs(x : real) : real;

    BEGIN
        IF x < 0 THEN x := -x;
        abs := x;
    END;

PROCEDURE printmatrix(VAR M : matrix);

    VAR
        i, j : integer;

    BEGIN
        writeln;
        FOR i := 1 TO n DO BEGIN
            FOR j := 1 TO n DO write(M[i,j]:15:6);
            writeln;
        END;
        writeln;
    END;

PROCEDURE decompose(n : integer; VAR A, LU : matrix);

    {Computes triangular matrices L and U and permutation matrix P
     so that LU = PA.  Stores L-I and U in LU.  Vector ps contains
     permuted row indices.  Note that A and LU are often passed the
     same matrix.}

    VAR
        scales : vector;
        i, j, k, pivotindex : integer;
        normrow, pivot, size, biggest, mult : real;

    BEGIN

        {Initialize ps, LU, and scales.}
        FOR i := 1 TO n DO BEGIN  {rows}
            ps[i] := i;
            normrow := 0;

            FOR j := 1 TO n DO BEGIN  {columns}
                LU[i,j] := A[i,j];

                {Find the largest row element.}
                IF normrow < abs(LU[i,j]) THEN normrow := abs(LU[i,j]);
            END;

            {Set the scaling factor for row equilibration.}
            IF normrow <> 0 THEN scales[i] := 1/normrow
            ELSE BEGIN
                scales[i] := 0;
                singular(ZEROROW);
            END;
        END;

        {Gaussian elimination with partial pivoting.}
        FOR k := 1 TO n-1 DO BEGIN  {pivot row k}
            pivotindex := 0;
            biggest := 0;

            {Go down rows from row k.}
            FOR i := k TO n DO BEGIN

                {Divide by the largest row element.}
                size := abs(LU[ps[i], k])*scales[ps[i]];

                IF biggest < size THEN BEGIN
                    biggest    := size;  {biggest scales column element}
                    pivotindex := i;     {row index of this element}
                END;
            END;

            IF biggest = 0 THEN singular(SINGULARMATRIX)
            ELSE BEGIN
                IF pivotindex <> k THEN BEGIN

                    {Exchange rows.}
                    j := ps[k];
                    ps[k] := ps[pivotindex];
                    ps[pivotindex] := j;
                END;

                pivot := LU[ps[k], k];  {pivot element}

                {Go down rest of rows.}
                FOR i := k+1 TO n DO BEGIN
                    mult := LU[ps[i], k]/pivot;
                    LU[ps[i], k] := mult;

                    IF mult <> 0 THEN BEGIN

                        {Inner loop.  Only column subscript varies.}
                        FOR j := k+1 TO n DO BEGIN
                            LU[ps[i], j] := LU[ps[i], j]
                                                - mult*LU[ps[k], j];
                        END;
                    END;
                END;
            END;
        END;

        {Check bottom right element of permuted matrix.}
        IF LU[ps[n], n] = 0 THEN singular(SINGULARMATRIX);
    END;

PROCEDURE solve(n : integer; VAR LU : matrix; VAR b, x : vector);

    {Solves Ax = b using LU from decompose.}

    VAR
        i, j : integer;
        dot  : real;

    BEGIN

        {Ly = b : solve for y.}
        FOR i := 1 TO n DO BEGIN
            dot := 0;
            FOR j := 1 TO i-1 DO BEGIN
                dot := dot + LU[ps[i], j]*x[j];
            END;
            x[i] := b[ps[i]] - dot;
        END;

        {Ux = y : solve for x.}
        FOR i := n DOWNTO 1 DO BEGIN
            dot := 0;
            FOR j := i+1 TO n DO BEGIN
                dot := dot + LU[ps[i], j]*x[j];
            END;
            x[i] := (x[i] - dot)/LU[ps[i], i];
        END;
    END;

PROCEDURE invert(n : integer; VAR A, Ainv : matrix);

    {Compute Ainv = inverse(A).  Note that A and Ainv are often
     passed the same matrix.}

    VAR
        LU :   matrix;
        b, x : vector;
        i, j : integer;

    BEGIN
        decompose(n, A, LU);


        FOR j := 1 TO n DO BEGIN
            FOR i := 1 TO n DO BEGIN
                IF i = j THEN b[i] := 1
                         ELSE b[i] := 0;
            END;

            solve(n, LU, b, x);

            FOR i := 1 TO n DO Ainv[i,j] := x[i];
        END;
    END;

PROCEDURE multiply(n : integer; VAR A, B, P : matrix);

    {Compute P = A x B.}

    VAR
        i, j, k : integer;
        sum : real;

    BEGIN
        FOR i := 1 TO n DO BEGIN
            FOR j := 1 TO n DO BEGIN
                sum := 0.0;

                FOR k := 1 TO n DO BEGIN
                    sum := sum + A[i,k]*B[k,j];
                END;

                P[i,j] := sum;
            END;
        END;
    END;



BEGIN
    n := 5;

    {Compute the Hilbert matrix.}
    FOR i := 1 TO n DO BEGIN
        FOR j := 1 TO n DO BEGIN
            H[i,j] := 1.0/(i + j - 1);
        END;
    END;

    writeln;
    writeln('Hilbert matrix:');
    printmatrix(H);

    {Invert the Hilbert matrix.}
    invert(n, H, Hinv);

    writeln('Hilbert matrix inverted:');
    printmatrix(Hinv);

    {Multiply the Hilbert matrix by its inverse.}
    multiply(n, H, Hinv, Z);

    writeln('Hilbert matrix multiplied by its inverse:');
    printmatrix(Z);

    {Invert the inverse.}
    invert(n, Hinv, H);

    writeln('Inverse matrix inverted:');
    printmatrix(H);
END.
