import Data.List
import Data.Char
import Data.Maybe

uniq [] = []
uniq (x:[]) = [x]
uniq (x:y:xys)
    | x == y    = uniq (y:xys)
    | otherwise = x : uniq (y:xys)

parse :: [Integer] -> String
parse lst = go lst unique 
    where
        unique = uniq $ sort lst
        go [] _ = []
        go (x:xs) lst = chr (ord('A') + fromJust (elemIndex x lst)) : go xs lst

solve :: [Integer] -> String
solve lst@(x:xs) = parse $ fstchar : go lst fstchar
    where
        (front, back) = span (== x) lst
        g = gcd x (head back)
        fstchar = if length front `mod` 2 == 0 then g else quot x g
        go [] _ = []
        go (x:xs) prv = res : go xs res
            where res = quot x prv

testcase id tot
    | id > tot  = return ()
    | otherwise = do
        putStr $ "Case #" ++ (show id) ++ ": "
        (n:l:[]) <- map read <$> words <$> getLine :: IO [Integer]
        lst <- map read <$> words <$> getLine :: IO [Integer]
        putStrLn $ solve lst
        testcase (id + 1) tot

main = do
    tot <- read <$> getLine :: IO Integer
    testcase 1 tot
