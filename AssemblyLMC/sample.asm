        lda space
        sta char
loop    lda char
        otc
        add one
        sta char
        sub max
        brz end
        bra loop
end     hlt
space   dat 32
one     dat 1
max     dat 127
char    dat 
//bla bla