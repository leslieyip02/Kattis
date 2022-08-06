import Data.List

unique :: [Int] -> Int
unique [x] = x
unique (x:y:xs)
    | x == y = unique xs
    | otherwise = x

solve :: Int -> Int -> IO()
solve 0 _ = return ()
solve t n = do
    _ <- readLn :: IO Int
    g <- getLine
    
    let gList = map read (words g) :: [Int]
    let c = unique (sort gList) :: Int
    putStrLn("Case #" ++ show (n - t + 1) ++ ": " ++ show c)
    
    solve (t - 1) n

main :: IO()
main = do
    n <- readLn :: IO Int
    solve n n
    