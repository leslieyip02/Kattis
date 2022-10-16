ncr :: Integer -> Integer -> Integer
ncr n 0 = 1
ncr 0 m = 0
ncr n m = ncr (n - 1) (m - 1) * n `div` m

solve :: Integer -> IO()
solve 0 = return()
solve t = do
    ln <- getLine
    let p = (map read) (words ln) :: [Integer]
    let n = p !! 0
    let m = (p !! 1) - 1

    print $ ncr n m

    solve (t - 1)

main :: IO()
main = do
    n <- readLn :: IO Integer
    solve n