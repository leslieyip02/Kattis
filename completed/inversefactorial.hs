f x n
    | x == 1 = n - 1
    | otherwise = f (x `div` n) (n + 1)

-- for n >= 10, each n! has a unique length
-- length of number = floor (log10 x) + 1, x ∈ Z+
-- log(n!) = log(1 * 2 * 3 * ... * n) = log(1) + log(2) + log(3) + ... + log(n)

g l n t
    | l' == t = floor n
    | otherwise = g (l + logBase 10 n') n' t
    where
        l' = floor l + 1
        n' = n + 1

main = do
    ln <- getLine
    let t = length ln

    -- 9! = 362880, t = 6
    if t <= 6 then do
        print $ f (read ln :: Integer) 2
    else do
        print $ g 0 1 t