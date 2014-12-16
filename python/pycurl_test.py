#!/usr/bin/env python

import click
import pycurl
import time
from StringIO import StringIO
try:
	# python 3
	from urllib.parse import urlencode
except ImportError:
	# python 2
	from urllib import urlencode

def curl_get(url):
	buf = StringIO()
	c = pycurl.Curl()
	c.setopt(c.URL, url)
	c.setopt(c.WRITEDATA, buf)
	c.perform()
	c.close()
	body = buf.getvalue()
	return body

# FIXME hardcode the post data name, need to be flexible
def curl_post(url, p, info, capital, total):
	c = pycurl.Curl()
	c.setopt(c.URL, url)
	header = 'Phant-Private-Key: ' + p
	c.setopt(c.HTTPHEADER, [header])
	post_data = {'info': info, 'capital': capital, 'total': total}
	postfields = urlencode(post_data)
	c.setopt(c.POSTFIELDS, postfields)
	return c.perform()

class conf(object):

	def __init(self):
		self.debug = False

pass_config = click.make_pass_decorator(conf, ensure=True)

@click.group()
@click.option('--debug', is_flag = True)
@pass_config
def cli(opt, debug):
	'''This script get/post data.\n
	e.g.\n
	python pycurl_test.py get -k PUBLICK_KEY\n
	python pycurl_test.py post -k PUBLICK_KEY -p PRIVATE_KEY\n
	'''
	opt.debug = debug

@cli.command()
@click.option('-k', default = 'Jxyjr7DmxwTD5dG1D1Kv', help = 'public key')
@click.argument('out', type = click.File('w'), default = '-', required = False)
@pass_config
def get(opt, k, out):
	'''This command gets data.'''
	if opt.debug:
		click.echo('out: %s' %out)

	print '---- in -----'
	click.echo('k: %s' %k)

	print '---- out ----'
	url_base = 'http://data.sparkfun.com/output/'
	url = url_base + k + '.json'
	print curl_get(url)

@cli.command()
@click.option('-k', default = 'Jxyjr7DmxwTD5dG1D1Kv', help = 'public key')
@click.option('-p', default = 'gzgnB4VazkIg7GN1g1qA', help = 'private key')
@click.option('--info', default = 'null', help = 'info=? (post data)')
@click.option('--capital', default = '10000.00', help = 'capital=? (post data)')
@click.option('--total', default = '10000.00', help = 'total=? (post data)')
@pass_config
def post(opt, k, p, info, capital, total):
	'''This command posts data.'''
	if opt.debug:
		click.echo('debug')

	print '---- in -----'
	click.echo('k: %s' %k)
	click.echo('p: %s' %p)
	click.echo('info: %s' %info)
	click.echo('capital: %s' %capital)
	click.echo('total: %s' %total)

	print '---- out ----'
	url_base = 'http://data.sparkfun.com/input/'
	url = url_base + k
	print curl_post(url, p, info, capital, total)

# Below lines are used to run this script directly in python env:
if __name__ == '__main__':
	cli()
