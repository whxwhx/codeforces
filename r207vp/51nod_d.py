class Counter(dict):
    def __missing__(self, key):
		return 0
n = input()
a = [Counter() for j in xrange(2) ]
cnt = Counter()
a[0][n] = 1
t = 0
while len(a[t]) > 0:
	a[t^1] = Counter()
	for l,c in a[t].items():
		cnt[((l + 1) >> 1) * ((l + 2) >> 1)] = cnt[((l + 1) >> 1) * ((l + 2) >> 1)] + c
		if l > 1:
			if (l-1) / 2 > 0:
				a[t^1][(l-1)/2] = a[t^1][(l-1)/2] + c
			a[t^1][(l-1)/2+(l-1)%2] = a[t^1][(l-1)/2+(l-1)%2] + c
	t = t ^ 1
cnt = sorted(cnt.iteritems(), key=lambda cnt: cnt[0]) 
ans = 0
s = 0
for l,c in cnt:
	ans = ans + (s + c + s + 1) * c / 2 * l
	s = s + c
print ans