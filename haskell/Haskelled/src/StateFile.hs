module StateFile where

import Prelude
import Data.Char
-- testing out parsers etc
-- given a parser , parse it
newtype State s a = State { runState :: s -> (a, s) }

span' :: (a->Bool) -> [a] -> ([a],[a])
span' pred = go []
  where
    go acc [] = (acc, [])
    go acc whole@(a:as)
      | pred a = let (req, rest) = go acc as
              in ([a]<>req, rest)
      | otherwise = (acc,whole)


{-


what is the benefit of this
we can directly do

data Operator = Plus | Minus | Times | Division

someFunc1 :: String -> (Int, String)
parse1 :: (String -> (Int, String)) -> String -> (Int,String)
parse1 someFunc String
someFunc2 :: String -> (Double, String)
someFunc3 :: String -> (Operator, String)

we can either do the above , make a function for parsing
each and everytype or make it pluggable

1. we know that someFuncX body will be same
so that can be generic
2. parse takes someFunc so instead it can take some generic

parse :: ( String -> (a, String) ) -> String -> (a, String)
type Parser a = String -> ( a , String )
--------
parse :: Parser a -> String -> (a, String)
--------
someFunc1 :: Parser Int
someFunc2 :: Parser Double
someFunc3 :: Parser Operator

someFuncX have the logic to parse different things

parse is simply running it (runParser) on a string



-}