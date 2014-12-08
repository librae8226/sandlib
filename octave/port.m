function port(n, g)
	x = 1:1:n;
	y = realpow(1 + g, x);
	plot(x, y);
endfunction
