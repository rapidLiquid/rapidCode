# Parser

### FP school of haskell notes
1. A function returns the same output with the same arg, a function has no state, nor can it access any external state.

2. Every time you call it, it behaves like a newborn baby with blank memory and no knowledge of the external world.

3. execution of pure functions can be easily parallelized because they have no side effects. With no side effects there are no data races

4. its better to call IO as IO action and not a container or something else

5. main is composed of IO actions which are themselves composed of IO actions  and hence this is the only source of side effects.

6. IO action keeps percolating up and is finally executed in the main

7. haskell laziness allows it to deal with the future that hasn't materialized yet

8. all imperative programming is at its core monadic

9. One of the major strengths of Haskell is that the execution of pure functions can be easily parallelized because they have no side effects

10. IO actions take UNIVERSE as input and produce a new universe which is the input to the other glued IO Action

11. Haskell data is immutable. Once you construct a data item, it will forever stay the same

12. 