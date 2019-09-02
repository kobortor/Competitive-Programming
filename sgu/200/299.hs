import Data.List

readIntList :: Integer -> IO [Integer]
readIntList n = go n []
    where
        go 0 lst = return lst
        go n lst = do
            x <- read <$> getLine :: IO Integer
            go (n - 1) (x : lst)

solve :: [Integer] -> (Integer, Integer, Integer)
solve (x1:x2:x3:xs) = if x1 + x2 > x3 then (x1, x2, x3) else solve (x2:x3:xs)
solve _ = (0, 0, 0)

main = do
    n <- read <$> getLine :: IO Integer
    (x1, x2, x3) <- solve <$> sort <$> readIntList n
    putStrLn $ (show x1) ++ " " ++ (show x2) ++ " " ++ (show x3)
