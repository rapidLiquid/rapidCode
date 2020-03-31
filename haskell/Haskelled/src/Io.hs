

module Io where
doit :: IO ()
doit = do
  str <- getLine
  if str == "hello" then return ()
  else doit

fib :: Integer -> Integer
fib 0 = 0
fib 1 = 1
fib n = mod  (fib (n-1) + fib (n-2)) 10

fib3 :: [Integer]
fib3 = 1 : 1 : map (`mod` 10) (zipWith (+) fib3 (tail fib3))

fib2 :: Integer -> Integer
fib2 z = x
  where
    (x,_) = f z
    f 0 = (1, 0)
    f n =
      let (f1,f2) = f (n-1)
      in (mod (f1 + f2) 10, f1)