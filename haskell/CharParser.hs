module Main where

main :: IO ()
main = putStrLn "Hello World!"

newtype Parser a = Parser { runParser :: String -> (Maybe a, String) }
--newtype State s a = State { runState :: s -> (a, s) }

-- a simple parser to parse  a  character
charP :: Char ->  Parser Char
--charP c = Parser $ \s -> if null s || head s /= c 
--                          then (Nothing,s) else (Just c, tail s)



charP c = Parser $ \inp -> case inp of
				(y:ys) | y == c -> (Just c , ys)
				_ -> (Nothing, inp)






