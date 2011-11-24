#!/bin/bash

getyn()
{
    echo 'Is this ok? (y/n)'
    read yn
    case $yn in
      [Yy]) return 0 ;;
      yes) return 0 ;;
      YES) return 0 ;;
      [Nn]) return 1 ;;
      no) return 1;;
      NO) return 1;;
      * ) echo "only accept Y,y,N,n,YES,yes,NO,no";;
    esac
}

git status
getyn "Is this ok? (y/n)"
git add .
git commit
git diff master > diff

