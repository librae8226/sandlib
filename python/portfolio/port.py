import click

class Config(object):

	def __init(self):
		self.debug = False

pass_config = click.make_pass_decorator(Config, ensure=True)

@click.group()
@click.option('--debug', is_flag = True)
@click.option('--path', type = click.Path())
@pass_config
def cli(opt, debug, path):
	'''This script evaluates portfolio.\n
	e.g.\n
	# revenue of 1.0 initlal fund with weekly 0.01 growth:\n
	port eval --mode w -f 1.0 -g 0.01\n
	# growth of growing to 5 times revenue in 2 years:\n
	port reval --mode y -r 5.0 -n 2\n
	'''

	opt.debug = debug
	if path is None:
		path = '.'
	opt.path = path

@cli.command()
@click.option('--mode', default = 'm',
		help = 'd/w/m/y: daily, weekly, monthly or yearly')
@click.option('-f', default = 1.0,
		help = 'initial fund')
@click.option('-g', default = 0.0,
		help = 'growth')
@click.argument('out', type = click.File('w'), default = '-',
		required = False)
@pass_config
def eval(opt, mode, f, g, out):
	'''This command calculates revenue from growth.'''
	if opt.debug:
		click.echo('opt path: %s' %opt.path)
		click.echo('out: %s' %out)

	print '---- in -----'
	click.echo(' mode: %s' %mode)
	click.echo(' f: %f' %f)
	click.echo(' g: %f' %g)

	print '---- out ----'
	if mode == 'd':
		rd = 1.0 + g
		rw = pow(rd , 7)
		rm = pow(rd, 30)
		ry = pow(rd, 365)
		print_revenue('d', f, rd)
		print_revenue('w', f, rw)
		print_revenue('m', f, rm)
	elif mode == 'w':
		rw = 1.0 + g
		rm = pow(rw, 4)
		ry = pow(rw, 52)
		print_revenue('w', f, rw)
		print_revenue('m', f, rm)
	elif mode == 'm':
		rm = 1.0 + g
		ry = pow(rm, 12)
		print_revenue('m', f, rm)
	elif mode == 'y':
		ry = 1.0 + g
	else:
		print 'please input correct \'mode\''
		return None

	print_revenue('y', f, ry)

@cli.command()
@click.option('--mode', default = 'y',
		help = 'm/y: monthly or yearly')
@click.option('-r', default = 2.0,
		help = 'revenue')
@click.option('-n', default = 1.0,
		help = 'number of d/w/m/y')
@click.argument('out', type = click.File('w'), default = '-',
		required = False)
@pass_config
def reval(opt, mode, r, n, out):
	'''This command calculates growth from revenue.'''
	if opt.debug:
		click.echo('opt path: %s' %opt.path)
		click.echo('out: %s' %out)

	print '---- in -----'
	click.echo(' mode: %s' %mode)
	click.echo(' r: %f' %r)
	click.echo(' n: %f' %n)

	print '---- out ----'
	if mode == 'm':
		rm = pow(r, 1.0/n)
		rw = pow(rm, 1.0/4.0)
		rd = pow(rm, 1.0/30.0)
		print_growth('m', rm)
		print_growth('w', rw)
		print_growth('d', rd)
	elif mode == 'y':
		ry = pow(r, 1.0/n)
		rm = pow(ry, 1.0/12.0)
		rw = pow(ry, 1.0/52.0)
		rd = pow(ry, 1.0/365.0)
		print_growth('y', ry)
		print_growth('m', rm)
		print_growth('w', rw)
		print_growth('d', rd)
	else:
		print 'please input correct \'mode\''
		return None

def print_revenue(mode, f, r):
	'''Print daily, weeky, monthly or yearly revenue'''
	if mode == 'd':
		n = [1]
	elif mode == 'w':
		n = [1]
	elif mode == 'm':
		n = [1, 2, 3, 5]
	elif mode == 'y':
		n = [1, 2, 3, 5, 10]
	else:
		print '@print_revenue: please input correct \'mode\''
		return None
	for i in n:
		click.echo('%2i%s: %f' %(i, mode, f * pow(r, i)))

def print_growth(mode, r):
	'''Print daily, weeky, monthly or yearly growth'''
	click.echo(' 1%s: %f' %(mode, (r - 1.0)))
