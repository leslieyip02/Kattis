h :: Integer -> [Integer]
h 1 = [1]
h n 
    | n `mod` 2 == 0 = n : h (n `div` 2)
    | otherwise = n : h (3 * n + 1)

main :: IO()
main = do
    n <- readLn :: IO Integer
    print $ sum $ h n