{-#LANGUAGE OverloadedStrings#-}
module Main where

import Data.Text (pack, unpack, splitOn, intercalate)

--confirm 5 row and five columns
-- find the position of the number
main :: IO ()
main = do
    strs <- getS
    let p = pos strs
    let ans = abs (2 - fst p) + abs (2 - snd p)
    putStrLn $ show ans

pos :: [String] -> (Int,Int)
pos s = (indexC s, maximum $ map indexR s)
        where
            indexC :: [String] -> Int
            indexC = go2 0
            go2 i [] = -1
            go2 i (c : cs)
                | '1' `elem` c = i
                | otherwise = go2 (i+1) cs
            indexR :: String -> Int
            indexR = go 0
            go i [] = -1
            go i (c : cs)
                | c == '1' = i
                | otherwise = go (i+1) cs

getS :: IO [String]
getS = sequence [getLine >>=  
        (pure . unpack . intercalate "" 
            . splitOn " " . pack) | _ <- [1..5] ]