solve :: Int -> Int -> Int -> [Char]
solve p q s
    | lcm p q <= s = "yes"
    | otherwise = "no"

main :: IO()
main = do
    ln <- getLine
    let l = map read (words ln) :: [Int]
    let p = l !! 0
    let q = l !! 1
    let s = l !! 2

    putStrLn (solve p q s)