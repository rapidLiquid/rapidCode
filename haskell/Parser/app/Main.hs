module Main where

import Lib
import Data.Char

{-
1. LEX analysis -> text -> tokens
2. parsing -> build an expr tree
3. evaluation -> evaluate the expr
-}

data Expression

data Operator = Plus | Minus | Times | Div
    deriving (Show, Eq)

opToChar :: Operator -> Char
opToChar Plus = '+'
opToChar Minus = '-'
opToChar Times = '*'
opToChar Div = '/'

charToOp :: Char -> Operator
charToOp c
    | c == '+' = Plus
    | c == '-' = Minus
    | c == '*' = Times
    | c == '/' = Div

data Token = TokOp Operator
                | TokIdent String
                | TokNum Int
                deriving (Show, Eq)

showContent :: Token -> String
showContent (TokOp a) = opToChar a : []
showContent (TokIdent s ) = s
showContent (TokNum n ) = show n

-- lexical analyzer

-- tokenize :: String -> [Token]
-- tokenize = undefined

-- parser

parse :: [Token] -> Expression
parse = undefined

-- evaluator

evaluate :: Expression -> Double
evaluate = undefined

isOp :: Char -> Bool
isOp x = x `elem` "+-*/"


tokenize :: String -> [Token]
tokenize [] = []
tokenize (x:xs)
    | isOp x    = TokOp (charToOp x) : tokenize xs
    | isAlpha x = TokIdent [x] : tokenize xs
    | isDigit x = TokNum (read [x]) : tokenize xs
    | isSpace x = tokenize xs
    | otherwise = error $ "Cannot parse" ++ [x]

main = print $ tokenize " 1 + 4 / x "


seqq :: [IO ()] -> IO ()
seqq [] = return ()
seqq (a:as) = a >> seqq as


pc :: Char -> IO ()
pc = putChar

ps :: String -> IO ()
ps s = foldr (>>) (return ()) ( (map putChar s) ++ [pc '\n'] )


digits :: String -> (String, String)
digits str = digs "" str
  where
    digs :: String -> String -> (String, String)
    digs acc [] = (acc, [])
    digs acc (c : cs) | isDigit c = 
                            let (acc', cs') = digs acc cs 
                            in (c:acc', cs')
                      | otherwise = (acc, c:cs)




digits2 :: String -> (String, String)
digits2 = go ""
    where
        go :: String -> String -> (String, String)
        go acc [] = (acc,"")
        go acc x@(c:cs)
            | isDigit c = 
                go (acc<>[c]) cs 
            | otherwise = (acc, x)


span' :: (a->Bool) -> [a] -> ([a],[a])
span' f = go []
    where
        go acc [] = (acc,[])
        go acc xx@(c:cs)
            | f c =
                let (acc',rem) = go acc cs
                in (c:acc',rem)
            | otherwise = (acc,xx)




-- type Parser a = String -> (a, String)

-- several :: Parser a -> String -> [a]
-- several f s =
-- -- f s -> (a, rest)
--     let (juice, rest) = f s
--     in if rest == s then [juice]
--         else [juice ] ++ several f rest

-- num :: Parser Int
-- num str =
--     let (i,rest) = span' isDigit str
--         in (read i, rest)

-- main2 = print $ several num "12 4 128"


type Parser a = String -> (a, String)

several :: Parser a -> String -> [a]
several p "" = []
several p str = let (a, str') = p str
                    as = several p str'
                in a:as

num :: Parser Int
num str = 
    let (digs, str') = span isDigit str
        (_, str'')   = span isSpace str'
    in (read digs, str'')

main2 = print $ several num "12  128"


several2 :: String -> [Int]
several2 "" = []
several2 str =
    let (a,b) = span' isDigit str
        (_,bb) = span' isSpace b
    in read a : several2 bb


-- several' :: (String -> ( Int , String ) )
--             -> String -> [Int]
-- several' f "" = []
-- several' f str =
--     let (req,rest) = f str
--         rest2 = span' isSpace str
--     in [req] ++ several' f rest2