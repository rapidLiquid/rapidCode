module Main where

import qualified Data.Set as S
-- https://codeforces.com/problemset/problem/368/B
-- TLE ??
distinct :: S.Set Int -> [Int] -> [Int] -> [Int]
distinct _ [] acc = reverse acc
distinct s (x:xs) [] = 
    let s2 = S.singleton x in distinct s2 xs [1]
distinct s (x:xs) ac@(a:acc) = 
    if S.member x s
    then distinct s xs (a:ac)
    else let s2 = S.insert x s
             a2 = a + 1
         in distinct s2 xs (a2:ac)

solve :: Int -> [Int] -> [Int] -> [Int]
solve n a q = go q []
    where
        dis = reverse $ distinct S.empty (reverse a) []

        go :: [Int] -> [Int] -> [Int]
        go [] acc = reverse acc
        go (x:xs) acc = go xs $ (dis !! (x-1)) : acc


main :: IO ()
main = do
    [n,_] <- getInp
    arr <- getInp
    interact $
        unlines . map show
        . solve n arr . map read
        . lines
    where
        getInp :: IO [Int]
        getInp = map read <$> words <$> getLine