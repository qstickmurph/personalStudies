from nose import *
import NAME

def setup():
    print("SETUP!")

def teardown():
    print("TEARDOWN!")

def testBasic():
    print("I RAN!", end = ' ')
