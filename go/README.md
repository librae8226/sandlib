Run go with a clean docker env, for clean addicts.

```
docker run --rm --name go -e GOPROXY="https://goproxy.cn" -v "$PWD":/usr/src/myapp -w /usr/src/myapp golang go --version
```

```
mkdir hello && cd hello
docker run --rm --name go -e GOPROXY="https://goproxy.cn" -v "$PWD":/usr/src/myapp -w /usr/src/myapp golang go mod init example.com/hello
vi hello.go
docker run --rm --name go -e GOPROXY="https://goproxy.cn" -v "$PWD":/usr/src/myapp -w /usr/src/myapp golang go run .
```

add module requirements
```
docker run --rm --name go -e GOPROXY="https://goproxy.cn" -v "$PWD":/usr/src/myapp -w /usr/src/myapp golang go mod tidy
docker run --rm --name go -e GOPROXY="https://goproxy.cn" -v "$PWD":/usr/src/myapp -w /usr/src/myapp golang go run .
```

OR

docker run -it --rm --name go -e GOPROXY="https://goproxy.cn" -v "$PWD":/usr/src/myapp -w /usr/src/myapp golang /bin/bash
