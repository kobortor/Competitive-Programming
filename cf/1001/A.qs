namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit, sign : Int) : ()
    {
        body
        {
            if (sign == 1) {
                H(q);
            } else {
                X(q);
                H(q);
            }
        }
    }
}
