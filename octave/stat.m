time = datenum(2014, 12, 8)
time(end + 1) = time(end) + 1
time(end + 1) = time(end) + 1
time(end + 1) = time(end) + 1
datestr(time)
total = [10116.88, 9736.28, 9962.49, 10089.92]
plot(time, total)
ax = gca()
datetick(2, "keepticks")
set(ax, "xtick", time)
