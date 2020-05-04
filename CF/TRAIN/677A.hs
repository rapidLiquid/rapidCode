{-#LANGUAGE OverloadedStrings#-}
module Main where
import Data.Text (pack, unpack, splitOn)
main :: IO ()
main = do
    [_,h] <- readInts
    hs <- readInts
    putStrLn $ show (solve h hs)
    where
        readInts :: IO [Int]
        readInts = fmap (map ((read ::String ->Int). unpack) 
                    . splitOn " " . pack) getLine

solve :: Int -> [Int] -> Int
solve h = foldr (\x acc -> if x > h then acc + 2 else acc + 1) 0