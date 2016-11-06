import urllib, urlparse, string, time

def get_temperature(country, state, city):
  url = urlparse.urljoin('http://www.weather.com/weather/cities/',
                          string.lower(country)+'_' +\
                          string.lower(state)+'_'+\
                          string.replace(string.lower(city), ' ', '_') + '.html')
  data = urllib.urlopen(url).read()
  #print url
  #print data
  start = string.index(data, 'current temp: ') + len('current temp: ')
  stop = string.index(data, 'degv;F', start-1)
  temp = int(data[start:stop])
  localtime = time.asctime(time.localtime(time.time()))
  print ("On %(localtime)s, the temporature in %(city)s, " +\
        "%(state)s %(country)s is %(temp)s F.") % vars()

if __name__ == '__main__':
  #get_temperature('FR', '', 'Paris')
  #get_temperature('US', 'RI', 'Providence')
  get_temperature('US', 'CA', 'San Francisco')
