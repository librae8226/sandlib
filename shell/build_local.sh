#!/bin/bash

git apply ../url_local.patch
jekyll build --destination /opt/lampp/htdocs/leafgrass
git apply ../url_remote.patch
