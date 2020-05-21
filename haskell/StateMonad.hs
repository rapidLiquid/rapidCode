module Main where

newtype State s a = State { runS :: s -> (a, s) }

instance Functor (State s) where
    fmap f (State sa) = State $ 
        \s -> let (a',s') = sa s in
                (f a', s')
instance Applicative (State s) where
    pure a = State $ \s -> (a, s)
    (State f) <*> (State as) = State $
        \s -> let (f', s') = f s
                  (a, s'') = as s'
                in (f' a, s'')

instance Monad (State s) where
    return = pure
    (State sa) >>= f = State $ \s ->
        let (a',s') = sa s
            (State g) = f a'
            in g s'

type Stack a = [a]

push ::Num a=> a -> State (Stack a) ()
push a = State $ \s -> ((), a:s)

pop ::Num a=> State (Stack a) a
pop = State $ \z -> case z of 
    [] -> (0,[])
    (x:xs) -> (x,xs)



stk :: Stack Int
stk = [1,2,3,4,5]
stkOp :: State (Stack Int) Int
stkOp = do
    push 3
    pop
    pop
    pop
    pop
    pop
    pop
    pop


main :: IO ()
main = do
    let z = runS stkOp stk
    print z
