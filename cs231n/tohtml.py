import markdown
import os

files = os.listdir('./setup-instructions/')

for filename in files:
    print (filename)
    markdown.markdownFromFile(input='./setup-instructions/'+filename, output='./setup-instructions/'+filename.replace('.md', '.html'))