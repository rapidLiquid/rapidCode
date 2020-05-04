{-#LANGUAGE OverloadedStrings#-}
module Main where
import Data.List (nub)
main :: IO ()
main = do
    ans <- solve <$> getLine
    putStrLn ans

solve :: String -> String
solve = f. toInteger . length . nub
    where
        f :: Integer -> String
        f x
            | odd x = "IGNORE HIM!"
            | otherwise = "CHAT WITH HER!"