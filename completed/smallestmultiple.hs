import System.IO (isEOF)

sm :: Integer -> [Integer] -> Integer
sm n [] = n
sm n (x:xs) = sm (lcm n x) xs 

solve :: IO()
solve = do 
    done <- isEOF
    if not done then 
        do
            line <- getLine
            let numbers = map read (words line) :: [Integer] 

            print $ sm 1 numbers
            solve
    else
        return()

main :: IO()
main = do
    solve
    