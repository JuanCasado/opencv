name=${1}
shift;
cd ${name}/build;
./${name} "$@";
