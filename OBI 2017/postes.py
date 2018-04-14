qt = int(input())
postes = list(map(int, input().split()))
qt_subst = qt_consert = 0

for p in postes:
    if p < 50:
        qt_subst += 1
    if p >= 50 and p < 85:
        qt_consert += 1
        
print(qt_subst, qt_consert)