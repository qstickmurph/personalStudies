runMe.jar: 
	javac -cp "/usr/share/openjfx/lib/*:./bin/*" -sourcepath src -d bin/ src/application/*.java src/application/**/*.java
	jar cmvf META-INF/MANIFEST.MF build.jar -C bin/ . -C /usr/share/openjfx/lib/ .

clear:
	rm *.class *.jar
