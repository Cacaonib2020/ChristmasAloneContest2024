import os
N = 2

for i in range(1,N+1):
  filename = f"sample-{(i):02d}.txt"
  os.system(f"ans.exe <./in/{filename} >./out/{filename}")
  print(f"ans.exe < ./in/{filename} > ./out/{filename}")
