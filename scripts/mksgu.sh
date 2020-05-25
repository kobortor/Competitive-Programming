function mksgu () {
    if (( $# != 1 )); then
        echo We need exactly 1 argument!
        return
    fi

    problem_id=$1
    folder_id=$((problem_id / 100 * 100))

    folder_name=$(basename $(pwd))
    if [ "$folder_name" = "Competitive-Programming" ]; then
        echo Setting targ=sgu/$folder_id/$problem_id.cpp
        targ=sgu/$folder_id/$problem_id.cpp
        mkdir -p sgu/$folder_name/

        if [ -f sgu$folder_id/$problem_id.cpp ]; then
            echo File already exists
        else
            cf gen cpp > /dev/null
            mv Competitive-Programming.cpp sgu/$folder_id/$problem_id.cpp
        fi
    else
        echo Error: You must be in a folder named "Competitive-Programming" use this function
    fi
}
