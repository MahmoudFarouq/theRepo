def isLeap(year):
	if (year % 4   != 0): 
		return False
	elif (year % 100 != 0): 
		return True
	elif (year % 400 != 0): 
		return False
	return True
def Split(date, sep='-'):
	birth = {}
	sepPos = date.find(sep)
	birth['year'] = int(date[0:sepPos])
	birth['month'] = int(date[sepPos+1:date.find(sep, sepPos+1)])
	sepPos = date.find(sep, sepPos+1)
	birth['day'] = int(date[sepPos+1:])
	return birth
def CalculateDays(birthD, todayD, sep='-'):
	then = Split(birthD)
	now   = Split(todayD)
	
	daysOfMonth = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
	result = 0
	
	while(then['day'] != now['day']):
		result += 1;	
		then['day'] += 1
		if(then['day'] % daysOfMonth[then['month']-1] == 0):
			then['day'] %= daysOfMonth[then['month']-1]
			then['month'] += 1
	while( then['month'] != now['month']):
		result += daysOfMonth[then['month']-1]
		then['month'] += 1
		if(then['month'] % 12 == 0):
			then['month'] %= 12
			then['year'] += 1
	while( then['year'] != now['year']):
		then['year'] += 1
		result += 366 if isLeap(then['year']) else 365
	print(result)


CalculateDays("1996-04-19", "2017-09-06")
