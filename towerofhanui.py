import time 

def toh(n,src,dst,tmp,file):
    if n==1:
        file.write(f'Move the Disc {n} from {src} to {dst}\n')
    else:
        toh(n-1,src,tmp,dst,file)
        file.write(f'Move the Disc {n} from {src} to {dst}\n')
        toh(n-1,tmp,dst,src,file)
with open ("exks.txt",'w') as file:

    n=int(input("Enter the number of disc: "))
    start=time.time()
    toh(n,'A','C','B',file)
    end=time.time()
print(f'the time taken is {end-start:.6f} seconds')


