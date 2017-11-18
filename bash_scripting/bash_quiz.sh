#!/bin/bash
echo 'Is a Dog an Animal?'

select dog in Yes No
do
        case $dog in 
        Yes|No)   
                break
                ;;
        *)
                echo "Invalid Input" 
                ;;
        esac
done

echo 'Capital of Canada?'
select place in Ottawa Toronto
do
        case $place in
        Ottawa|Toronto)
                break
                ;;
        *)
                echo "Invalid Input"
                ;;
        esac
done
echo 'Capital of Ontario?'
select place2 in Ottawa Toronto
do
        case $place2 in
        Ottawa|Toronto)
                break
                ;;
        *)
                echo "Invalid Input"
                ;;
        esac
done
echo 'Sky is blue'
select sky in true false
do
        case $sky in
        true|false)
                break
                ;;
        *)
                echo "Invalid Input"
                ;;
        esac
done
echo 'Grass is usually green'
select grass in true false
do
        case $grass in
        true|false)
		
                break
                ;;
        *)
                echo "Invalid Input"
                ;;
        esac
done
Score=0
if [ "$sky" = true ];
then

Score=$((Score + 1))
fi
if [ "$grass" = true ];
then

Score=$((Score + 1))
fi
if [ "$place2" = Toronto ];
then
Score=$((Score + 1))
fi
if [ "$place" = Ottawa ];
then
Score=$((Score + 1))
fi
if [ "$dog" = Yes ];
then
core=$((Score + 1))
fi
echo Your score is $Score out of 5
echo Results stored in root
mail -s "Test Score" mac <<< "Your score was : " $Score
