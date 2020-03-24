module Lib
    ( someFunc
    ) where

someFunc :: IO ()
someFunc = putStrLn "someFunc"



-- concat in terms of foldr
-- foldr :: function(a->b->b) -> accumalator(b) -> originaLlist([a]) -> accumulator(b)
-- where function :: a -> b -> b
--      where a is the elment of the list, b is the acc
-- (++) :: [a] -> [a] -> [a]
concatF :: [[a]] -> [a]
concatF = foldr f []
  where
  -- f :: a -> b -> b
  -- where, a=element from the list, b=accumulator (to be converted\folded into)
    f :: [a] -> [a] -> [a]
    f =  (++)

concatIO :: [IO [a]] -> IO [a]
concatIO = foldr f (pure [])
  where
    f :: IO [a] -> IO [a] -> IO [a]
--    f a b = undefined
    f aa bb = aa >>= (\x -> bb >>= (\y -> pure $ x ++ y))
--    f a b = do

