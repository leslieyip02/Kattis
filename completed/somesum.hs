solve :: Int -> [Char]
solve n
    | n `mod` 2 == 1 = "Either"
    | n `mod` 4 == 0 = "Even"
    | otherwise = "Odd"

main :: IO()
main = do
    n <- readLn :: IO Int
    putStrLn $ solve n