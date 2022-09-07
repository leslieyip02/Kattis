import Data.List
import Data.Char

c :: Int -> Char
c x
    | x == 0 = ' '
    | otherwise = chr (x + 96)

c' :: Char -> Int
c' x
    | x == ' ' = 0
    | otherwise = ord x - 96

e :: [Char] -> Int -> [Char]
e [] _ = []
e (x:xs) y = c (p `mod` 27) : e(xs) p
    where
        p = c' x + y

d :: [Char] -> Int -> [Char]
d [] _ = []
d (x:xs) y = c (r - y) : d(xs) r
    where
        p = c' x
        q = ceiling $ fromIntegral (y - p) / 27
        r = p + q * 27

solve :: Int -> IO()
solve 0 = return()
solve n = do
    ln <- getLine

    if ln !! 0 == 'e' then
        putStrLn $ e (drop 2 ln) 0
    else 
        putStrLn $ d (drop 2 ln) 0

    solve (n - 1)

main :: IO()
main = do
    n <- readLn :: IO Int
    solve n