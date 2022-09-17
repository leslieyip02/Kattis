solve :: Integer -> Integer -> [Char]
solve n k
    | 2 ^ k >= n = "Your wish is granted!"
    | otherwise  = "You will become a flying monkey!"

main :: IO()
main = do
    ln <- getLine
    let p = map read (words ln) :: [Integer]
    let n = p !! 0
    let k = p !! 1

    putStrLn $ solve n k