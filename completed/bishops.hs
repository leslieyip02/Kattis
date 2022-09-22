import System.IO (isEOF)

solve :: IO()
solve = do 
    done <- isEOF
    if not done then 
        do
            n <- readLn :: IO Integer

            if n <= 1 then
                print n
            else
                print $ (n - 1) * 2
    
            solve
    else
        return()

main :: IO()
main = do
    solve