runMe.jar: 
	javac -sourcepath src -d build src/*.java
	jar cmvf META-INF/MANIFEST.MF build.jar -C build/ .

clear:
	rm *.class *.jar
