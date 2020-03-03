module Main where


main :: IO ()
main = undefined

someFunc :: IO ()
someFunc = putStrLn "hello"


class Container c where
    empty :: c a
    insert :: a -> c a -> c a

instance Container [] where
    empty = []
    insert = (:)

newtype Queue a = Queue { unQueue :: [a] } deriving Show

instance Container Queue where
    empty = Queue []
    insert x = Queue . (:) x . unQueue


data Tree a = Leaf a | Node (Tree a) (Tree a)


instance Show b => Show (Tree b) where
    show (Leaf x) = "Leaf " <> show x
    show (Node l r) = "Node (" <> show l <> " , " <> show r <> ")"

countLeaves :: Tree a -> Integer
countLeaves (Leaf _) = 1
countLeaves (Node l r) = countLeaves l + countLeaves r


a :: Tree Integer
a = Node (Node (Leaf 1) (Node (Leaf 2) (Leaf 3))) (Node (Leaf 4) (Node (Leaf 5) (Leaf 6)))

relabel :: Tree a -> Integer -> ( Tree (Integer , a) , Integer)
relabel (Leaf a) i = (Leaf (i, a), i + 1)
relabel (Node l r) i = let (l' , i1) = relabel l i
                           (r' , i2) = relabel r i1
                       in ((Node l' r'), i2)




-- just to typecheck, works fine
-- type WithCounter a = Integer -> (a, Integer)
-- next :: (Integer -> (a, Integer)) -> (a -> Integer -> (b, Integer)) -> (Integer -> (b, Integer))
-- next f g = \ic -> let (r, ic') = f ic in g r ic'


newtype WithCounter a = WithCounter { evalWithCounter :: Integer -> (a, Integer) }

-- actual impl
-- next :: WithCounter a -> (a -> WithCounter b) -> WithCounter b
-- next f g = \ic -> let (r, ic') = f ic in g r ic'


-- crux

next :: WithCounter a -> (a -> WithCounter b) -> WithCounter b
next f g = WithCounter $ \ic -> let (r, ic') = (evalWithCounter f) ic in evalWithCounter (g r) ic'




pure' :: a -> WithCounter a
pure' a = WithCounter $ \ic -> (a, ic)



relabelNext :: Tree a -> WithCounter (Tree (Integer, a))
relabelNext (Leaf a) = WithCounter $ \ic ->  (Leaf (ic,a), ic+1 )
relabelNext (Node l r) = relabelNext l `next`
                        \left -> relabelNext r `next`
                        \right -> pure' $ Node left right


-- random shit

add :: Maybe a -> (a -> Maybe b) -> Maybe b
add = undefined

add2 :: Integer -> Integer -> Maybe Integer
add2 a b = Just (a + b)

f :: Maybe Integer -> Maybe Integer -> Maybe Integer
f ma mb = ma >>= (\a ->
                    mb >>= (\b -> add2 a b)
                 )



