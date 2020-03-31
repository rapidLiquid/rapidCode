module Stack where

class Stack f where
  push :: a -> f a -> f a
  pop :: f a -> ( a, f a )
  top :: f a -> a
