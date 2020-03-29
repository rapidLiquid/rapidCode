module Main where

import Data.List
-- https://codeforces.com/problemset/problem/384/A
main :: IO ()
main = do
    n <- getLine >>= pure . (read :: String -> Int)
    let res = solve n
    putStrLn . show . length . filter (=='C') $ res
    putStrLn res
    pure ()

solve :: Int -> String
solve n =
    let n' = (n+1) `div` 2
        cs = f "." . intercalate "." . take n' $ (repeat "C")
        dot = f "C" . intercalate "C" . take n' $ (repeat ".")
    in intercalate "\n" . take n $ cycle [cs, dot]
    where
        f s = if even n then ( <> s )
                else ( <> mempty )