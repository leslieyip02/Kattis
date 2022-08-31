main :: IO()
main = do
    n <- readLn :: IO Integer
    m <- readLn :: IO Integer
    print(n + m)