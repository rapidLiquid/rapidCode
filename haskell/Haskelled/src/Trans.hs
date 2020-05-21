{-#LANGUAGE OverloadedStrings#-}
module Trans where



import Data.Text
-- Imports that will be needed later:
import qualified Data.Text.IO as T
import Data.Map as Map
import Control.Applicative

data LoginError =
    InvalidEmail
    | NoSuchUser
    | WrongPassword
    deriving Show


main :: IO ()
main = undefined


getDomain :: Text -> Either LoginError Text
getDomain z =
    case splitOn "@" z of
        [_, domain] -> Right domain
        _ -> Left InvalidEmail

printRes :: Either LoginError Text -> IO ()
printRes (Left e) = T.putStrLn . pack $  show e
printRes (Right t) = T.putStrLn $ t

-- either :: (a -> c) -> (b -> c) -> Either a b -> c
{-

so first function is to handle erro and
     second to handle success
-}
printRes2 :: Either LoginError Text -> IO ()
printRes2 = either (T.putStrLn . pack . show) T.putStrLn


--best would be this

printRes3 :: Either LoginError Text -> IO ()
printRes3 = T.putStrLn . either (const "er") id

-- printRes3 :: Either LoginError Text -> Text
-- printRes3 = either (const "err") (id)


-- ask the user for the token
getToken :: IO ( Either LoginError Text )
getToken =
    putStrLn "enter domain" >> T.getLine >>= pure . getDomain



-- domain and pass
users :: Map Text Text
users = Map.fromList [("ex.com","ssd"),("localhost","abcs")]


userLogin :: IO (Either LoginError Text)
userLogin = do
    token <- getToken
    case token of
        Right domain ->
            case Map.lookup domain users of
                Nothing -> pure $ Left NoSuchUser
                Just pass -> do
                    pass2 <- T.getLine -- ask
                    if pass2 == pass
                        then pure token
                        else pure $ Left WrongPassword
        lef -> pure lef -- in this case return the error since domain is wrong



{-

runE :: EitherIO e a -> IO (Either e a)
EitherIO :: IO (Either e a) -> EitherIO e a

-}

liftE :: Either e a -> EitherIO e a
liftE = EitherIO . pure

liftIO :: IO a -> EitherIO e a
liftIO = EitherIO . (pure <$>)

getToken2 :: EitherIO LoginError Text
getToken2 = do
    liftIO $ putStrLn "enter Domain"
    dom <- liftIO $ T.getLine
    liftE $ getDomain dom

userLogin2 :: EitherIO LoginError Text
userLogin2 = do
    -- tok <- EitherIO $ getToken
    tok <- getToken2
    pass <- maybe (liftE . Left $ NoSuchUser) 
                pure (Map.lookup tok users)
    pass_asked <- liftIO $ T.putStrLn "enterPass" >> T.getLine
    if pass_asked == pass
        then liftE $ pure "AUTHENTICATED"
        else liftE $ Left WrongPassword
    -- if pass2 
    -- case Map.lookup tok users of
    --     Nothing -> liftE $ Left NoSuchUser
    --     Just pass -> do
    --         liftIO $ putStrLn "enter pass"
    --         pass2 <- liftIO $ T.getLine
    --         liftIO $ T.putStrLn $ "p2 " <> pass2
    --         liftIO $ T.putStrLn $ "p1 " <> pass
    --         liftIO $ T.putStrLn $ "tok " <> tok
    --         if pass == pass2
    --             then liftE $ pure "s"
    --             else liftE $ Left WrongPassword




-- kind of like Either ...
data EitherIO e a = EitherIO 
    { runE :: IO (Either e a) }

instance  Show (EitherIO e a) where
    show _ = "sss"


--fmap :: (a-> b) -> EitherIO e a -> EitherIO e b
instance Functor (EitherIO e) where
    fmap f (EitherIO ex) = EitherIO $ (f <$>) <$> ex 

instance Applicative (EitherIO e) where
    pure = EitherIO . pure . pure
    EitherIO f <*> EitherIO a = EitherIO $ do
        f' <- f
        a' <- a
        pure $ f' <*> a'

-- instance Monad (EitherIO e) where
--     EitherIO ea  >>= f = EitherIO $ do
--         eax <- ea
--         case eax of
--             z@( Left e ) ->  pure $ Left e
--             Right a -> runE  (f a)
-- can we somhow use either
-- note how this is simply kind of either ... awesome
-- but not exactly since its not left and right


-- runE . f :: a -> (IO (Either ... ))
-- if success then 

instance Monad (EitherIO e) where
    (EitherIO eix) >>= f = EitherIO $
        eix >>= either (pure . Left) (runE . f)





{-

how to think about either , the main juice is v
e is just a wrapping a context that might have failed

-}

{-

data Oneof e v = Fail e | Success v

instance Functor (Oneof e) where
    fmap f (Success v) = Success $ f v
    fmap _ (Fail z) = Fail z



instance Applicative (Oneof e) where
    pure = Success
    Success f <*> Success a = Success $ f a
    Fail f <*> _ = Fail f
    _ <*> Fail z = Fail z


instance Monad (Oneof e) where
    Success a >>= f = f a
    Fail a >>= _ = Fail a
-}



{-






about monads and the process of chaining...
some other common functional patterns etc...

(>>=) :: m a -> ( a -> m b ) -> m b




now the beauty of monad is that we can chain them

here instead of  <- a , we can have some other computations
that return Maybe someting and can use the result here

or it can return maybe of somthing and we want the internal value
to change ...

so inject ... f <$> 

<$>
<*> :: m (a->b) -> m a -> m b
such a scalable right associative operation for chaining

now some of the things are generalised like
state monad etc and diff monad transformers that can be used
out of the box with some standard libraries ...

now to think about... what is bind and what is the value 
that is being `unwrapped`

we can visualise this by writing in non - do notation form..


HENCE the BINDINGs are actually the JUICE value


-}

addMaybe :: Num a=>Maybe a -> Maybe a -> Maybe a
addMaybe a b = do
    aa <- a
    bb <- b
    pure $ aa + bb




addMaybe2 :: Num a=>Maybe a -> Maybe a -> Maybe a
addMaybe2 ma mb =
    ma >>= \a ->
    mb >>= \b ->
        pure $ a + b



