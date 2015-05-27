#/bin/bash

# Get needed data

curl -X GET 'http://data.sparkfun.com/output/jqOJ6AN1bYTD0pxKMzNL.json' > public.json
#curl -X GET 'http://biz.finance.sina.com.cn/stock/flash_hq/kline_data.php?symbol=sh000300&begin_date=20141208&end_date=20150105' > csi300.xml
curl -X GET 'http://biz.finance.sina.com.cn/stock/flash_hq/kline_data.php?symbol=sh000300&begin_date=20141208' > csi300.xml
