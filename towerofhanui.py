def toh(n,src,dst,tmp):
    if n==1:
        print(f'Move the Disc {n} from {src} to {dst}')
    else:
        toh(n-1,src,dst,tmp)
        print(f'Move the Disc {n} from {src} to {dst}')
        toh(n-1,tmp,dst,src)
n=int(input("Enter the number of disc: "))
toh(n,'A','B','C')

