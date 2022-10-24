digits :: String -> Integer -> Integer
digits n i
    | n == "1"  = i
    | otherwise = digits (show $ length n) (i + 1)

solve :: IO()
solve = do
    ln <- getLine
    if ln /= "END" then do
        print $ digits ln 1
        solve
    else
        return()

main :: IO()
main = do
    solve