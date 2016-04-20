awk -F \| 'NR==FNR { a[$2]=$0; next } { print a[$1]"|"$2 }' awk_name_id.txt awk_id_score.txt
