solve :: Integer -> Integer -> Integer -> Integer
solve lo hi x = 
    let mid = quot (lo + hi) 2 in 
    if lo > hi then
        hi
    else if mid * mid <= x then
        solve (mid + 1) hi x
    else
        solve lo (mid - 1) x

main = do
    x <- read <$> getLine :: IO Integer
    putStrLn $ show $ solve 0 (10^501) x
