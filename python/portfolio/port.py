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
	'''This script evaluates portfolio.'''
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
		click.echo(' 1d: %f' %rd)
		click.echo(' 1w: %f' %rw)
		click.echo(' 1m: %f' %rm)
		click.echo(' 2m: %f' %pow(rm, 2))
		click.echo(' 3m: %f' %pow(rm, 3))
		click.echo(' 5m: %f' %pow(rm, 5))
	elif mode == 'w':
		rw = 1.0 + g
		rm = pow(rw, 4)
		ry = pow(rw, 52)
		click.echo(' 1w: %f' %rw)
		click.echo(' 1m: %f' %rm)
		click.echo(' 2m: %f' %pow(rm, 2))
		click.echo(' 3m: %f' %pow(rm, 3))
		click.echo(' 5m: %f' %pow(rm, 5))
	else:
		rm = 1.0 + g
		ry = pow(rm, 12)
		click.echo(' 1m: %f' %rm)
		click.echo(' 2m: %f' %pow(rm, 2))
		click.echo(' 3m: %f' %pow(rm, 3))
		click.echo(' 5m: %f' %pow(rm, 5))

	click.echo(' 1y: %f' %ry)
	click.echo(' 2y: %f' %pow(ry, 2))
	click.echo(' 3y: %f' %pow(ry, 3))
	click.echo(' 5y: %f' %pow(ry, 5))
	click.echo('10y: %f' %pow(ry, 10))

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
		click.echo(' 1m: %%%f' %(100 * (rm - 1.0)))
		click.echo(' 1w: %%%f' %(100 * (rw - 1.0)))
		click.echo(' 1d: %%%f' %(100 *(rd - 1.0)))
	else:
		ry = pow(r, 1.0/n)
		rm = pow(ry, 1.0/12.0)
		rw = pow(ry, 1.0/52.0)
		rd = pow(ry, 1.0/365.0)
		click.echo(' 1y: %%%f' %(100 * (ry - 1.0)))
		click.echo(' 1m: %%%f' %(100 * (rm - 1.0)))
		click.echo(' 1w: %%%f' %(100 * (rw - 1.0)))
		click.echo(' 1d: %%%f' %(100 *(rd - 1.0)))
