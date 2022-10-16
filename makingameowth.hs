solve (n:p:x:y:xs) = p * x + (p `div` (n - 1)) *  y

main = do
    ln <- getLine
    
    let v = map read (words ln) :: [Integer]
    print $ solve v