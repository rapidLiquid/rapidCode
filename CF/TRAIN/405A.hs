{-#LANGUAGE OverloadedStrings#-}
module Main where
import Data.Text (pack, unpack, splitOn)
import Data.List (intercalate)
main :: IO ()
main = do
    _ <- getLine
    l <- intercalate " " . map show 
            . qsort . head <$> getInts 1
    putStrLn l

getInts :: Integer -> IO [[Integer]]
getInts i = sequence [getLine >>= f | _ <- [1..i] ]
    where
        f :: String -> IO [Integer]
        f = pure . map (read . unpack) . splitOn " " . pack

qsort :: [Integer] -> [Integer]
qsort [] = []
qsort list = qsort lesser ++ pivots ++ qsort higher
    where
        pivot = head list
        pivots = filter (==pivot) list
        higher = filter (>pivot) list
        lesser = filter (<pivot) list