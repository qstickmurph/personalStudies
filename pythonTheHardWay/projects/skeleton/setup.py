try:
    from setuptools import setup
except ImportError:
    from distutils.core import setup

config = {
        'description' : 'My Project',
        'author' : 'Quinn P Murphey',
        'url' : '<insert URL',
        'download_url' : '<insert URL>',
        'author_email' : 'Quinn_murphey@me.com'
        'version' : '0.1',
        'install_requires' : ['nose'],
        'packages' : ['NAME'],
        'scripts' : [],
        'name' : 'Project'
        }

setup(**config)
