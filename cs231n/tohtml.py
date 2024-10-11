import markdown
import os

files = os.listdir('./python-numpy-tutorial/')

for filename in files:
    print (filename)
    markdown.markdownFromFile(input='./python-numpy-tutorial/'+filename, output='./python-numpy-tutorial/'+filename.replace('.md', '.html'))