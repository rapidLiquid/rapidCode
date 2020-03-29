{-#LANGUAGE OverloadedStrings #-}
module Main where

-- https://codeforces.com/problemset/problem/71/A
import qualified Data.Text as T

main :: IO ()
main = do
    inp <- getLine
    let n = read inp :: Integer
    solve n


solve :: Integer -> IO ()
solve n = if n <= 0 then pure ()
    else getLine >>= putStrLn . _solve 
            >> solve (n-1)

_solve :: String -> String
_solve s
    | length s > 10 = 
        (c2S . head) s <> show (length s - 2) <> (c2S . last) s
    | otherwise = s
    where
        c2S :: Char -> String
        c2S = (:[])