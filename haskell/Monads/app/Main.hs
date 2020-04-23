module Main where

import Lib

main :: IO ()
main = someFunc



-- newtype State s a = 
--     State { runState :: s -> (a, s) }



-- -- fmap :: (a->b) -> State s a -> State s b
-- -- sa :: s -> (a, s)

-- instance Functor (State s) where
--     fmap f (State sa) = State $ 
--         \initialState -> let (a,s') = sa initialState
--             in (f a, s')

-- instance Applicative (State s) where
--     pure = undefined
--     (<*>) = undefined

-- instance Monad (State s) where
--     return = undefined
--     (>>=) = undefined
--     (>>) = undefined
