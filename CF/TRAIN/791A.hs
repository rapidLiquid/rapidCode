{-#LANGUAGE OverloadedStrings#-}
module Main where

import Data.Text (splitOn, pack, unpack)

main :: IO ()
main = getInt >>= solve 0 >>= putStrLn . show

solve :: Int -> [Int] -> IO Int
solve i [a,b]
    | a > b = pure i
    | otherwise = solve (i+1) [3*a,2*b]

getInt :: IO [Int]
getInt = fmap (map (read . unpack) 
            . splitOn " " . pack) getLine