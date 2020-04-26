class Song(object):
    
    def __init__(self, lyrics):
        self.lyrics = lyrics

    def singMeASong(self):
        for line in self.lyrics:
            print(line)

    def name(self):
        print(self)

happyBDay = Song(["Happy birthday to you",
                "I don't want to get sued",
                "So I'll stop right there"])

bullsOnParade = Song(["They rally around tha family",
                    "With pockets full of shells"])

happyBDay.singMeASong()

bullsOnParade.singMeASong()

happyBDay.name()
