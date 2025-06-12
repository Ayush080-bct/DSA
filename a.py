import subprocess
import time

while True:
    result = subprocess.check_output("netsh wlan show interfaces", shell=True).decode()
    for line in result.splitlines():
        if "Signal" in line:
            print("📶 Signal Strength:", line.strip().split(":", 1)[1].strip())
        elif "Receive rate (Mbps)" in line:
            print("⬇️  Receive Rate:", line.strip().split(":", 1)[1].strip(), "Mbps")
        elif "Transmit rate (Mbps)" in line:
            print("⬆️  Transmit Rate:", line.strip().split(":", 1)[1].strip(), "Mbps")
    print("-----")
    time.sleep(5)
