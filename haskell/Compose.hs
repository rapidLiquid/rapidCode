module Main where

main :: IO ()
main = undefined

newtype Compose f g a = 
    Compose ( f (g a) ) deriving Show

instance (Functor f, Functor g) => Functor (Compose f g) where
    fmap = undefined

instance (Applicative f, Applicative g) => Applicative (Compose f g) where
    pure = undefined
    (<*>)  = undefined

instance (Monad f, Monad g) => Monad (Compose f g) where
    (>>=) (Compose a) f = Compose $ a >>= _


{-


f (g a)
a -> f (g b)

f x >>= g

g :: (g a) -> f (g b)
g ga = g a -> a -> g b -> g b
-}