fb [] = []
fb (x:xs)
    | x `mod` 15 == 0 = "fizzbuzz" : fb xs
    | x `mod` 3  == 0 = "fizz"     : fb xs
    | x `mod` 5  == 0 = "buzz"     : fb xs
    | otherwise       = show x     : fb xs

check [] _ = []
check (x:xs) y = c : (check xs) y
    where
        r = zipWith (\a b -> a == b) x y
        c = length $ filter (== True) r

solve [] i y z = z
solve (x:xs) i y z
    | x > y     = solve xs (i + 1) x i
    | otherwise = solve xs (i + 1) y z

main = do
    ln <- getLine
    
    let p = map read (words ln) :: [Integer]
    let n = p !! 0
    let m = p !! 1

    cases <- getContents
    let s = check ((map words) (lines cases)) (fb [1 .. m])
    print $ solve s 1 0 1