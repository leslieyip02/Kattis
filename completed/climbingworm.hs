climb :: Integer -> Integer -> Integer -> Integer -> Integer
climb a b h t
    | h - a <= 0 = t + 1
    | otherwise = climb a b (h - a + b) t + 1

main :: IO()
main = do
    line <- getLine

    let numbers = map read (words line) :: [Integer]
    let a = numbers !! 0
    let b = numbers !! 1
    let h = numbers !! 2

    print $ climb a b h 0