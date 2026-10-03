from setuptools import find_packages
from setuptools import setup

setup(
    name='turtle_intfaces',
    version='0.0.0',
    packages=find_packages(
        include=('turtle_intfaces', 'turtle_intfaces.*')),
)
