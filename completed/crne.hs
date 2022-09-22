main :: IO()
main = do
    n <- readLn :: IO Integer
    
    let c = n `div` 2 + 1
    let r = ceiling $ fromIntegral n / 2.0 + 1

    print $ r * c
