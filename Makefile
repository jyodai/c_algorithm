all : help

help :
	# make up            Docker Containerを起動
	# make stop          Docker Containerを停止
	# make sh            Docker ContainerにShellで接続
	# hello              Hello Worldを出力する

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
# C言語の実行
################################################################################

hello :
	docker-compose exec ubuntu /bin/bash -c ' \
		cd src; \
		gcc hello.c -o hello; \
		./hello; \
		rm ./hello;\
	'

euclidean :
	docker-compose exec ubuntu /bin/bash -c ' \
		cd src; \
		gcc EuclideanAlgorithm.c -o EuclideanAlgorithm; \
		./EuclideanAlgorithm; \
		rm ./EuclideanAlgorithm;\
	'