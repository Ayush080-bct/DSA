import time 
def toh(n,src,dst,tmp):
    if n==1:
        print(f'Move the Disc {n} from {src} to {dst}')
    else:
        toh(n-1,src,tmp,dst)
        print(f'Move the Disc {n} from {src} to {dst}')
        toh(n-1,tmp,dst,src)
n=int(input("Enter the number of disc: "))
start=time.time()
toh(n,'A','C','B')
end=time.time()
print(f'the time taken is {end-start:.6f} seconds')


