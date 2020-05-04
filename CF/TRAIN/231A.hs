{-#LANGUAGE OverloadedStrings#-}
module Main where

import Data.Text (splitOn, pack, unpack)

main :: IO ()
main = do
    [n] <- getInts
    solve n 
    >>= pure . length . filter (>=2) 
    >>= putStrLn . show

-- solve :: Int -> String
-- solve = undefined

solve ::  Int -> IO [Int]
solve n = sequence [getLine >>= oz | _ <- [1..n]]

-- ones should be greater than equal to 2
oz :: String -> IO Int
oz  = pure . length . filter (=='1')

getInts :: IO [Int]
getInts = fmap ( map ( read . unpack ) 
            . splitOn " " . pack ) getLine

