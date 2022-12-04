import glob

sources = glob.glob('./test/*.cpp') + glob.glob('./test/**/*.cpp')

for source in sources:
    print(source)
