{-#LANGUAGE OverloadedStrings#-}
module Main where

import Data.Char
import Data.List

main :: IO ()
main = getLine >> getLine >>= f >>= putStrLn

f :: String -> IO String
f = pure . solve

conv :: [String]
conv = ["", "", "2", "3", "322", 
        "5", "53", "7", "7222", "7332"]

solve :: String -> String
solve = 
    reverse 
    . sort . concat 
    . map (\c -> conv !! (ord c - ord '0'))