{-#LANGUAGE OverloadedStrings#-}
module Main where

import Data.Text (pack, unpack, splitOn)

main :: IO ()
main = do
    [n] <- getInt
    str <- getLine
    putStrLn (solve n str)

getInt :: IO [Int]
getInt = fmap (map (read . unpack) 
            . splitOn " " . pack) getLine

solve :: Int -> String -> String
solve tot str
    | tot < a * 2 = "Anton"
    | tot > a * 2 = "Danik"
    | otherwise = "Friendship"
    where
        a :: Int
        a = foldr (\c ac -> 
                    if c == 'A' then ac + 1
                     else ac) 0 str