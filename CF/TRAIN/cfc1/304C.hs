{-#LANGUAGE OverloadedStrings#-}
module Main where

import Data.List

main :: IO ()
main = ( readLn :: IO Int ) >>= solve >>= putStrLn

-- mkL n = [0..n-1]
solve :: Int -> IO String
solve n
    | even n = pure "-1"
    | otherwise =
        pure . intercalate "\n" $ map showL l3
    where
        l :: [Int]
        l = [0..n-1]
        l3 = [ l, l,  map (flip mod n . (*2)) l ]

showL :: [Int] -> String
showL = intercalate " " . map show