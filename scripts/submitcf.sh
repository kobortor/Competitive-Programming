function submitcf () {
    if (( $# != 0 )); then
        echo Do not put any arguments!
        return
    fi

    file_name="$(basename "$targ")"
    contest_id="$(basename "$(dirname "$targ")")"
    problem_id="${file_name%.*}"

    cf submit $contest_id $problem_id $targ
}
