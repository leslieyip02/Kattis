-- n choose 2
c :: Integer -> Integer
c n = (n * (n - 1)) `div` 2

main :: IO()
main = do
    n <- readLn :: IO Integer
    print $ (c (n `div` 4)) * 4 + 4