'''
from gtts import gTTS
import os
tts = gTTS(text="This is the pc speaking", lang='en')
tts.save("pcvoice.mp3")
os.system("rhythmbox pcvoice.mp3")
'''

'''
import os
os.system("say 'hello world'")
'''
'''
import pyttsx
engine = pyttsx.init()
engine.say('Good morning.')
engine.runAndWait()
'''

import nltk
text = "my name is mahmoud and i'm sad"
from nltk.tokenize import word_tokenize, sent_tokenize

sents = sent_tokenize(text)
print(sents)





#end
