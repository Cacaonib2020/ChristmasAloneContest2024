import os
import time
N = 27

for i in range(1,N+1):
  filename = f"testcase-{(i):02d}.txt"
  start = time.time() 
  # os.system(f"ans.exe <./in/{filename} >./out/{filename}")
  os.system(f"ans.exe <./in/{filename} >nul")
  t = time.time() - start
  print(f"ans.exe <./in/{filename} >./out/{filename} {t:.3f}sec")
