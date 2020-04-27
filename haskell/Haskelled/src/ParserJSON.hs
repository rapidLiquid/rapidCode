{-# LANGUAGE LambdaCase #-}
module ParserJSON where

import Data.Functor (($>))
import Control.Applicative


main :: IO ()
main = undefined

data JsonValue =  JsonNull
                | JsonBool Bool
                | JsonNumber Integer
                | JsonString String
                | JsonArray [JsonValue]
                | JsonObject [(String, JsonValue)]
                deriving (Show, Eq)

-- create separate small parser to parse individual types
-- combine these parsers to form a bigger parser

--parser :: String -> Maybe (String, a)

-- generally parse can parse anything and return the rest for other parsers
-- this makes them composable ... parse and move on to the next
-- sometimes they can fail and not parse something...

--parser = undefined



-- now comes the main part, lets create a kind of parametric object
--type Parser a = String -> Maybe (String, a)
-- so basically teh whole complexity got hidden....

-- become an epic haskeller and create a newtype
newtype Parser a = Parser { runParser :: String -> Maybe (String, a) }
-- kind of like struct in cpp
-- why is this called runParser ...
-- to run the parser .... simple
jsonValue :: Parser JsonValue
jsonValue = undefined
-- jsonvalue is a JsonValue parser, to run it simply do
-- runParser jsonValue , which requires a string and parses the result
-- it holds and hides the implementation of the parser
-- sort of like a trick, call run... and it makes it run ...
--    it pulls out the func and does something


-- we can think of this as a pluggable thing ...
-- we can have any parser which simply encodes a lambda expression
-- some rule to take a string and output something
-- now we can run it and get the result on any string

-- this would simply parse a single null value .....
jsonNull :: Parser JsonValue
jsonNull = stringP "null" $> JsonNull
--but to parse a sequence of char we need to able to parse a single char
-- but which char to pass, we need some char and need to return a Parser
-- we could have written charP :: Parser Char but it would be any char, the below is specific Char
charP :: Char -> Parser Char
charP x =
  Parser $ \case
    (c:cs)
      | c == x -> Just (cs, c)
    _ -> Nothing

stringP :: String -> Parser String
stringP = seqq . map charP

-- now to make the string parser
-- we need to take a sequence of stringP
-- map charP somestring -> [Parser Char]
-- we need to make it Parser [Char]
-- we need to turn it inside out
-- sequenceA t (f a) -> f (t a)
-- takes a traversable of applicatives and makes them
--  applicative of traversables

-- to use the above, we need to make it functor and then applicative

-- fmap :: (a->b) -> f a -> f b
instance Functor Parser where
  fmap f (Parser p) = Parser $ \input ->
      case p input of
        Just (rest, a) -> Just (rest, f a)
        Nothing -> Nothing

-- (<*>) :: f ( a -> b) -> f a -> f b
instance Applicative Parser where
  (<*>) (Parser p1) (Parser p2) =
    Parser $ \input ->
      p1 input >>= (\(input', a) -> p2 input'
               >>= \(input'', b) -> Just $ (input'', a b))
  pure x = Parser $ \s -> Just (s, x)

instance Alternative Parser where
  (<|>) (Parser p1) (Parser p2) =
    Parser $ \input -> p1 input <|> p2 input
  empty = Parser $ \_ -> Nothing
--  empty = undefined

jsonBool :: Parser JsonValue
jsonBool = f <$> (stringP "true" <|> stringP "false")
  where
    f "true" = JsonBool True
    f "false" = JsonBool False
    f _ = undefined

seqq :: Applicative f => [f a] -> f [a]
seqq = foldr f (pure [])
  where
    f :: Applicative f => f a -> f [a] -> f [a]
    f v acc = pure (:)<*> v <*> acc