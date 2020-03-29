{-#LANGUAGE OverloadedStrings#-}
module Main where
-- https://codeforces.com/contest/69/problem/A
import qualified Data.Text as T
import Data.List

main :: IO ()
main = do
    ns <- getLine
    let n = read ns :: Integer
    res <- getL n []
    let res2 = (transpose . reverse) res
        allz = foldr (\x acc -> sum x == 0 && acc) True res2
    if allz then putStrLn "YES"
    else putStrLn "NO"
    pure ()


getL :: Integer -> [[Integer]] -> IO [[Integer]]
getL 0 acc = pure acc
getL n acc = do
    str <- getLine
    let l = map ((read :: String -> Integer) . T.unpack) 
                (T.splitOn " " . T.pack $ str)
    getL (n-1) (l : acc)

