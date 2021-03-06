from flask import Flask, request, url_for, render_template
from subprocess import call

app = Flask(__name__)

@app.route('/')
def index():
	    return 'Index Page'

@app.route('/hello/')
@app.route('/hello/<name>')
def hello(name=None):
	return render_template('hello.html', name=name)

@app.route('/user/<username>')
def show_user_profile(username):
	# show the user profile for that user
	return 'User %s' % username

@app.route('/post/<int:post_id>')
def show_post(post_id):
	# show the post with the given id, the id is an integer
	return 'Post %d' % post_id

@app.route('/projects/')
def projects():
	return 'The project page'

@app.route('/about')
def about():
	return 'The about page'

@app.route('/func/<func>')
def run_func(func):
	return 'func name: %s' % func

@app.route('/login', methods=['GET', 'POST'])
def login():
	print 'login entry'
	if request.method == 'POST':
		print 'calling do_the_login'
		do_the_login()
                if request.data == 'on':
                    print 'calling on.sh'
                    call(['on.sh'])
                else:
                    print 'calling off.sh'
                    call(['off.sh'])
	else:
		print 'calling show_the_login_form'
		show_the_login_form()
	return 'login process done'

def do_the_login():
	"""doc for do_the_login"""
	print 'do_the_login'

def show_the_login_form():
	"""doc for show_the_login_form"""
	print 'show_the_login_form'

@app.route('/up', methods=['GET', 'POST'])
def up():
	print 'up entry'
	if request.method == 'POST':
                print 'calling up.sh'
                call(['up.sh'])
	else:
		print 'do nothing'
	return 'up process done'

@app.route('/down', methods=['GET', 'POST'])
def down():
	print 'down entry'
	if request.method == 'POST':
                print 'calling down.sh'
                call(['down.sh'])
	else:
		print 'do nothing'
	return 'down process done'

@app.route('/select', methods=['GET', 'POST'])
def select():
	print 'select entry'
	if request.method == 'GET':
                print 'calling select.sh'
                call(['select.sh'])
	else:
		print 'do nothing'
	return 'select process done'

with app.test_request_context():
	print url_for('static', filename='style.css')

if __name__ == '__main__':
	app.run(host='0.0.0.0', debug=True)
