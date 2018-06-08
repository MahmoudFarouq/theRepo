import urllib2
from bs4 import *
from urlparse import urljoin
import MySQLdb
import re

class crawler:
	def __init__(self, dbname):
		#connect to database
		self.conn = MySQLdb.connect( host=hostname, user=username, passwd=password, db=database )
		pass
	def __del__(self):
		#close database
		self.conn.close()
		pass
	def dbCommit(self):
		#self.conn.commet()
		pass
	
	def execQuery(self, query):
		cur = self.conn.cursor()
		cur.execute(query)
		return  cur
		
	#Auxiliary fun for getting an id and adding it 
	# if it's not present
	def getEntryId(self, table, field, value, createnew=True):
		cur = self.execQuery( "select id from %s where %s='%s'" % (table,field,value))
		res = cur.fetchone()
		if res == None:
			cur = self.execQuery( "insert into %s (%s) values ('%s')" % (table,field,value))
			return cur.lastrowid
		else:
			return res[0]
		
	#index an individual page
	def addToIndex(self, url, soup):
		if self.isIndexed(url): 
			return
		print 'Indexing %s' %url
		
		# Get the individual words
		text = self.getTextOnly(soup)
		words= self.separateWords(text)
		
		# Get the URL id
		urlid = self.getEntryId('urllist','url',url)
		
		# Link each word to this url
		for i in range(len(words)):
			word = words[i]
			if word in ignoreWords: 
				continue
			wordid = self.getEntryId('wordlist','word',word)
			self.execQuery("insert into wordlocation(urlid,wordid,location) values (%d,%d,%d)" % (urlid,wordid,i))
	
	#extract the text from an html page(no tags)
	def getTextOnly(self, soup):
		v = soup.string
		if v == None:
			c = soup.contents
			resultText = ''
			for t in c:
				subText = self.getTextOnly(t)
				resultText += subText + '\n'
			return resultText
		else:
			return v.strip()
		
	#Separate the words by any non-whitespace character
	def separateWords(self, text):
		splitter = re.compile('\\W*')
		return [s.lower() for s in splitter.split(text) if s != '' ]

	#return true if this is already indexed
	def isIndexed(self, url):
		u = self.execQuery("select id from urllist where url='%s'" % url).fetchone( )
		if u != None:
			# Check if it has actually been crawled
			v = self.execQuery('select * from wordlocation where urlid=%d' % u[0]).fetchone( )
			if v != None: 
				return True
		return False
	
	#Add a link between two pages
	def addLinkRef(self, urlFrom, urlTo, linkText):
		pass
	
	#starting with a list of pages do a breadth
	#-first search to the given depth, indexing 
	#pages as we go
	def crawl(self, pages, depth=2):
		for i in range(depth):
			newPages = set()
			for page in pages:
				try:
					c = urllib2.urlopen(page)
				except:
					print 'Couldnt Open Page %s' %page
					continue
				soup = BeautifulSoup(c.read(), "lxml")
				self.addToIndex(page, soup)
				
				links = soup('a')
				for link in links:
					if( 'href' in dict(link.attrs) ):
						url = urljoin(page, link['href'])
						#if url.find("'") != -1:
						#	continue
						url = url.split('#')[0] #remove location portion 
						if url[0:4] == 'http' and not self.isIndexed(url):
							newPages.add(url)
						linkText = self.getTextOnly(link)
						self.addLinkRef(page, url, linkText)
				self.dbCommit()
			pages = newPages
	
	#create the database tables
	def createIndexTables(self):
		pass
	

#create list of words to ignore

ignoreWords = set(['the','of','to','and','a','in','is','it'])


hostname = '127.0.0.1'
username = 'root'
password = 'mahmoud123'
database = 'SearchEngine'




pagelist = ['https://WWW.GOOGLE.COM']
crawler = crawler('')
crawler.crawl(pagelist, depth=1)










