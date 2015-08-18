import sys
import re
import urllib2

r = r"""<a href="\/accounts[^>]+>([^<]+).+?<td>\n? *([0-9]+)"""

to_crawl = []
for i in range(1, 49):
    to_crawl.append("https://footbar.fr/accounts/my-profile?page={}".format(i))

print "$dollar = ["
for page in to_crawl:
    response = urllib2.urlopen(page).read()
    matches = re.findall(r, response, re.DOTALL)
    for match in matches:
        print "{{name:'{}', score:{}}},".format(match[0], match[1])
