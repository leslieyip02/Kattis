{-# LANGUAGE ParallelListComp #-}

c = 1 : [cn * (4 * n + 2) `div` (n + 2) | n <- [0..] | cn <- c]

solve 0 = return()
solve q = do
    x <- readLn
    print $ c !! x
    solve (q - 1)

main = do
    q <- readLn
    solve q