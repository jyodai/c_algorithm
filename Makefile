all : help

help :
	# make up            Docker Containerを起動
	# make stop          Docker Containerを停止
	# make sh            Docker ContainerにShellで接続
	# clean              コンパイルしたファイルを削除
	# hello              Hello Worldを出力する
	# euclidean-c        コンパイル
	# euclidean-r        アルゴリズムを実行
	# euclidean-t        テストを実行

################################################################################
# docekrの操作
################################################################################

up :
	docker-compose up -d
stop :
	docker-compose stop
sh :
	docker-compose exec ubuntu /bin/bash

################################################################################
# アルゴリズムの実行
################################################################################

clean :
	docker-compose exec ubuntu /bin/bash -c ' \
		cd ./src; \
		ls ./ | grep -v -E "\.c" | xargs rm; \
	'

hello :
	docker-compose exec ubuntu /bin/bash -c ' \
		cd src; \
		gcc hello.c -o hello; \
		./hello; \
		rm ./hello;\
	'

euclidean-c :
	docker-compose exec ubuntu /bin/bash -c ' \
		cd src; \
		gcc EuclideanAlgorithm.c -o EuclideanAlgorithm; \
	'

euclidean-r :
	docker-compose exec ubuntu /bin/bash -c ' \
		./src/EuclideanAlgorithm; \
	'

euclidean-t :
	docker-compose exec ubuntu /bin/bash -c ' \
		./src/EuclideanAlgorithm -t; \
	'

eratosthenes-c :
	docker-compose exec ubuntu /bin/bash -c ' \
		cd src; \
		gcc SieveOfEratosthenes.c -o SieveOfEratosthenes; \
	'

eratosthenes-r :
	docker-compose exec ubuntu /bin/bash -c ' \
		./src/SieveOfEratosthenes; \
	'

eratosthenes-t :
	docker-compose exec ubuntu /bin/bash -c ' \
		./src/SieveOfEratosthenes -t; \
	'
