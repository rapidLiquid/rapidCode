{-# LANGUAGE OverloadedStrings #-}
module Main where
-- https://codeforces.com/contest/443/problem/A
import qualified Data.Set as Set
import qualified Data.Text as T

main :: IO ()
main = do
    input <- getLine
    let input2 = T.pack . drop 1 . take (length input - 1) $ input
        splitted = map T.strip . T.splitOn "," $ input2
        l = Set.fromList . filter (not . T.null) $ splitted
    putStrLn . show $ Set.size l
    pure ()