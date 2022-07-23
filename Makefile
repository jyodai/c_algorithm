all : help

help :
	# make up            Docker Containerを起動
	# make stop          Docker Containerを停止
	# make sh            Docker ContainerにShellで接続

up :
	docker-compose up -d
stop :
	docker-compose stop
sh :
	docker-compose exec ubuntu /bin/bash
