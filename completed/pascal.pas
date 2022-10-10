program pascal;
label solved;

var
    n: int32;
    i: int32;
    counter: int32;

begin
    readln(n);
    for i := 2 to round(sqrt(n)) + 1 do begin
        if n mod i = 0 then begin
            counter := n - n div i;
            goto solved;
        end
    end;

    counter := n - 1;
    
    solved: writeln(counter);
end.