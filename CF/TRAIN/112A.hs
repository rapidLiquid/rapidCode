{-#LANGUAGE OverloadedStrings#-}
module Main where

import Data.Char

main :: IO ()
main = do
    [a,b] <- getS 2
    putStrLn . show $ solve a b

solve :: String -> String -> Int
solve s1 s2
    | s1 > s2 = 1
    | s1 < s2 = -1
    | otherwise = 0
getS :: Int -> IO [String]
getS i = sequence [getLine >>= pure 
            . map toLower | _ <- [1..i]]