function mkcf () {
    if (( $# != 2 )); then
        echo We need exactly 2 arguments!
        return
    fi

    contest_id=$1
    problem_id=$( echo $2 | tr '[a-z]' '[A-Z]' )

    if (( ${#contest_id} > 4 )); then
        echo Contest length must be 4 characters or less
        return
    else
        contest_id=$(printf %04d $contest_id)
    fi

    folder_name=$(basename $(pwd))
    if [ "$folder_name" = "Competitive-Programming" ]; then
        echo Setting targ=cf/$contest_id/$problem_id.cpp
        targ=cf/$contest_id/$problem_id.cpp
        mkdir -p cf/$contest_id/

        if [ -f cf/$contest_id/$problem_id.cpp ]; then
            echo File already exists
        else
            cf gen cpp > /dev/null
            mv Competitive-Programming.cpp cf/$contest_id/$problem_id.cpp
            sed "s=FILE=cf/$contest_id/$problem_id.cpp=g" scripts/template_Makefile > Makefile
        fi
    else
        echo Error: You must be in a folder named "Competitive-Programming" use this function
    fi
}
