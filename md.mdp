%title: 下一代容器工具
%author: Jun Liu
%date: 2020-05-16

-> # 目录 <-

- **下一代容器工具介绍**
- **下一代容器工具使用**

--------------------------------------------------
-> # 下一代容器工具介绍 <-

--------------------------------------------------
-> # 下一代容器工具介绍 <-

# podman介绍
[https://podman.io/](https://podman.io/)

> Pod Manager tool (podman)是管理OCI镜像/容器全生命周期的容器工具。

Buildah和Podman是Atomic项目早期的容器工具项目，2018年初红帽收购CoreOS后，Buildah和Podman的东家也由CoreOS转到红帽。收购后CoreOS后，红帽将Container Linux和Fedora Atomic Host两个项目整合成统一的新项目Fedora CoreOS来统一运营Buildah和Podman项目。

**podman特性:**
- daemonless
- 支持root和非root方式运行容器
- 支持k8s pod管理

-------------------------------------------------
-> # 下一代容器工具介绍 <-

# buildah介绍
[https://buildah.io/](https://buildah.io/)

> buildah是专注构建OCI镜像的容器工具。
和podman的关系，https://github.com/containers/buildah#buildah-and-podman-relationship

**buildah功能:**
- 创建、删除、重命名容器
- 创建、删除镜像
- 从Dockerfile构建和buildah脚本构建
- 支持OCI格式或docker格式镜像
- 挂载、卸载运行中容器的根文件系统

-------------------------------------------------
-> # 下一代容器工具介绍 <-

# skopeo介绍
[https://github.com/containers/skopeo](https://github.com/containers/skopeo)

> skopeo是专注远程镜像仓镜像元数据信息查看(inspect)、镜像同步(sync)、镜像删除(delete)的容器工具。

**skopeo功能:**
- 在不同的镜像仓之前复制镜像
- 查看远端镜像仓中的镜像详情
- 删除镜像仓中的镜像
- 镜像仓认证
- 支持OCI格式或docker格式镜像

--------------------------------------------------
-> # 下一代容器工具使用 <-

# podman 使用
安装，以centos8为例
```
yum install podman
alias docker=podman
```


```
mkdir dist
echo 'nginx ok' > dist/index.html

podman build -t nginx .
podman run -idt --name tn -p 8000:80 nginx
curl localhost:8000
```

-------------------------------------------------
-> # 下一代容器工具使用 <-

# podman 使用
- 整合k8s
```
#支持将pod导出为k8s格式yaml
podman generate kube demodb  > demodb.yaml
kubectl apply -f demodb.yaml
#支持运行k8s pod yaml
#注:只支持Pod这一种k8s Kind
cat > nginx.yaml <<'EOF'
apiVersion: v1
kind: Pod
metadata:
  labels:
    app: nginx
  name: mynginx
  namespace: default
spec:
  containers:
  - image: docker.io/library/nginx:1.17
    imagePullPolicy: IfNotPresent
    name: nginx
EOF
podman play kube nginx.yaml

```

- pod管理
```
podman pull registry.cn-hangzhou.aliyuncs.com/google_containers/pause:3.1
podman tag registry.cn-hangzhou.aliyuncs.com/google_containers/pause:3.1 k8s.gcr.io/pause:3.1
#创建pod并映射端口
podman pod create --name mypod -p 31001:80
#在pod中添加容器
podman run -d --pod mypod --name nginx docker.io/library/nginx:1.17

```

--------------------------------------------------
-> # 下一代容器工具使用 <-

# buildah 使用
```
#安装，以centos8为例
yum install buildah
```

- ONBUILD in **Dockerfile**
```
cat << EOF > Dockerfile
FROM busybox:latest
RUN touch /foo
ONBUILD RUN touch /bar
EOF
buildah bud --format=docker -f Dockerfile -t onbuild-image .
buildah inspect --format '{{.Docker.Config.OnBuild}}' onbuild-image
```
- ONBUILD in **buildah config**
```sh
cat > lighttpd.sh <<"EOF"
#!/usr/bin/env bash -x
ctr1=$(buildah from "${1:-fedora}")
## Get all updates and install our minimal httpd server
buildah run "$ctr1" -- dnf update -y
buildah run "$ctr1" -- dnf install -y lighttpd
## Include some buildtime annotations
buildah config --annotation "com.example.build.host=$(uname -n)" "$ctr1"
## Run our server and expose the port
buildah config --cmd "/usr/sbin/lighttpd -D -f /etc/lighttpd/lighttpd.conf" "$ctr1"
buildah config --port 80 "$ctr1"
## Commit this container to an image name
buildah commit "$ctr1" "${2:-$USER/lighttpd}"
EOF

bash lighttpd.sh
```

--------------------------------------------------
-> # 下一代容器工具使用 <-

# skopeo使用

```
#centos8
yum install  skopeo
```
```
查看远端镜像详情
skopeo inspect docker://docker.io/fedora

查看远端镜像版本
skopeo list-tags docker://docker.io/fedora

镜像同步
skopeo sync --dest-tls-verify=false --src docker --dest docker docker.io/fedora 192.168.130.31:5000

删除镜像
skopeo delete docker://192.168.130.31:5000/busybox:latest
```

--------------------------------------------------

-> # THANK YOU !  <-

mdp supports *other* **formatting**, too. Give it a try!
