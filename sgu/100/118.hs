import Data.List
 
readLst :: IO [Integer]
readLst = do
    (x:xs) <- map read <$> words <$> getLine :: IO [Integer]
    return xs
 
polyprod :: [Integer] -> Integer
polyprod l = go l 1 0
    where
        go [] prod sum = sum
        go (x:xs) prod sum = go xs px (sum + px)
            where px = prod * x
 
digsum 0 tmp = tmp
digsum n tmp = digsum d (tmp + m)
    where
        (d, m) = divMod n 10
 
digroot n = if n < 10 then n else digroot (digsum n 0)
 
solve 0 = return ()
solve k = do
    lst <- readLst
    putStrLn $ show $ digroot $ polyprod $ lst
    solve (k - 1)
 
main = do
    k <- read <$> getLine :: IO Integer
    solve k
