#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me)
{
        string msg;
        
        tell_object(me,MAG"\n¡ï"HIY"É«²Ê¾«ÁéÏòÄú±¨¸æ"MAG"¡ï\n\n"NOR);
        tell_object(me,
"  	ºÚÉ«- BLK"BLK"¡ö¡ö¡ö¡ö¡ö¡ö"NOR" \n"                       
"  	ºìÉ«- RED"RED"¡ö¡ö¡ö¡ö¡ö¡ö"NOR"	HIR"HIR"¡ö¡ö¡ö¡ö¡ö¡ö"NOR" \n"
"  	ÂÌÉ«- GRN"GRN"¡ö¡ö¡ö¡ö¡ö¡ö"NOR" 	HIG"HIG"¡ö¡ö¡ö¡ö¡ö¡ö"NOR" \n"
"  	»ÆÉ«- YEL"YEL"¡ö¡ö¡ö¡ö¡ö¡ö"NOR" 	HIY"HIY"¡ö¡ö¡ö¡ö¡ö¡ö"NOR" \n"
"  	À¶É«- BLU"BLU"¡ö¡ö¡ö¡ö¡ö¡ö"NOR" 	HIB"HIB"¡ö¡ö¡ö¡ö¡ö¡ö"NOR" \n"
"  	·ÛÉ«- MAG"MAG"¡ö¡ö¡ö¡ö¡ö¡ö"NOR" 	HIM"HIM"¡ö¡ö¡ö¡ö¡ö¡ö"NOR" \n"
"  	ÇàÉ«- CYN"CYN"¡ö¡ö¡ö¡ö¡ö¡ö"NOR" 	HIC"HIC"¡ö¡ö¡ö¡ö¡ö¡ö"NOR" \n"
"  	°×É«- WHT"WHT"¡ö¡ö¡ö¡ö¡ö¡ö"NOR" 	HIW"HIW"¡ö¡ö¡ö¡ö¡ö¡ö"NOR" \n\n\n");

	if (wizardp(me))
	{
	msg = 
BGRN	"  	ºÚÉ«- BLK"BLK"·çÔÆÌìÏÂ"" \n"                       
BGRN	"  	ºìÉ«- RED"RED"·çÔÆÌìÏÂ""	HIR"HIR"·çÔÆÌìÏÂ"NOR" \n"
BGRN	"  	ÂÌÉ«- GRN"GRN"·çÔÆÌìÏÂ"" 	HIG"HIG"·çÔÆÌìÏÂ"NOR" \n"
BGRN	"  	»ÆÉ«- YEL"YEL"·çÔÆÌìÏÂ"" 	HIY"HIY"·çÔÆÌìÏÂ"NOR" \n"
BGRN	"  	À¶É«- BLU"BLU"·çÔÆÌìÏÂ"" 	HIB"HIB"·çÔÆÌìÏÂ"NOR" \n"
BGRN	"  	·ÛÉ«- MAG"MAG"·çÔÆÌìÏÂ"" 	HIM"HIM"·çÔÆÌìÏÂ"NOR" \n"
BGRN	"  	ÇàÉ«- CYN"CYN"·çÔÆÌìÏÂ"" 	HIC"HIC"·çÔÆÌìÏÂ"NOR" \n"
BGRN	"  	°×É«- WHT"WHT"·çÔÆÌìÏÂ"" 	HIW"HIW"·çÔÆÌìÏÂ"NOR" \n\n";

	msg += 
BRED	"  	ºÚÉ«- BLK"BLK"·çÔÆÌìÏÂ"" \n"                       
BRED	"  	ºìÉ«- RED"RED"·çÔÆÌìÏÂ""	HIR"HIR"·çÔÆÌìÏÂ"NOR" \n"
BRED	"  	ÂÌÉ«- GRN"GRN"·çÔÆÌìÏÂ"" 	HIG"HIG"·çÔÆÌìÏÂ"NOR" \n"
BRED	"  	»ÆÉ«- YEL"YEL"·çÔÆÌìÏÂ"" 	HIY"HIY"·çÔÆÌìÏÂ"NOR" \n"
BRED	"  	À¶É«- BLU"BLU"·çÔÆÌìÏÂ"" 	HIB"HIB"·çÔÆÌìÏÂ"NOR" \n"
BRED	"  	·ÛÉ«- MAG"MAG"·çÔÆÌìÏÂ"" 	HIM"HIM"·çÔÆÌìÏÂ"NOR" \n"
BRED	"  	ÇàÉ«- CYN"CYN"·çÔÆÌìÏÂ"" 	HIC"HIC"·çÔÆÌìÏÂ"NOR" \n"
BRED	"  	°×É«- WHT"WHT"·çÔÆÌìÏÂ"" 	HIW"HIW"·çÔÆÌìÏÂ"NOR" \n\n";

	msg += 
BYEL	"  	ºÚÉ«- BLK"BLK"·çÔÆÌìÏÂ"" \n"                       
BYEL	"  	ºìÉ«- RED"RED"·çÔÆÌìÏÂ""	HIR"HIR"·çÔÆÌìÏÂ"NOR" \n"
BYEL	"  	ÂÌÉ«- GRN"GRN"·çÔÆÌìÏÂ"" 	HIG"HIG"·çÔÆÌìÏÂ"NOR" \n"
BYEL	"  	»ÆÉ«- YEL"YEL"·çÔÆÌìÏÂ"" 	HIY"HIY"·çÔÆÌìÏÂ"NOR" \n"
BYEL	"  	À¶É«- BLU"BLU"·çÔÆÌìÏÂ"" 	HIB"HIB"·çÔÆÌìÏÂ"NOR" \n"
BYEL	"  	·ÛÉ«- MAG"MAG"·çÔÆÌìÏÂ"" 	HIM"HIM"·çÔÆÌìÏÂ"NOR" \n"
BYEL	"  	ÇàÉ«- CYN"CYN"·çÔÆÌìÏÂ"" 	HIC"HIC"·çÔÆÌìÏÂ"NOR" \n"
BYEL	"  	°×É«- WHT"WHT"·çÔÆÌìÏÂ"" 	HIW"HIW"·çÔÆÌìÏÂ"NOR" \n\n";
	msg += 
BCYN	"  	ºÚÉ«- BLK"BLK"·çÔÆÌìÏÂ"" \n"                       
BCYN	"  	ºìÉ«- RED"RED"·çÔÆÌìÏÂ""	HIR"HIR"·çÔÆÌìÏÂ"NOR" \n"
BCYN	"  	ÂÌÉ«- GRN"GRN"·çÔÆÌìÏÂ"" 	HIG"HIG"·çÔÆÌìÏÂ"NOR" \n"
BCYN	"  	»ÆÉ«- YEL"YEL"·çÔÆÌìÏÂ"" 	HIY"HIY"·çÔÆÌìÏÂ"NOR" \n"
BCYN	"  	À¶É«- BLU"BLU"·çÔÆÌìÏÂ"" 	HIB"HIB"·çÔÆÌìÏÂ"NOR" \n"
BCYN	"  	·ÛÉ«- MAG"MAG"·çÔÆÌìÏÂ"" 	HIM"HIM"·çÔÆÌìÏÂ"NOR" \n"
BCYN	"  	ÇàÉ«- CYN"CYN"·çÔÆÌìÏÂ"" 	HIC"HIC"·çÔÆÌìÏÂ"NOR" \n"
BCYN	"  	°×É«- WHT"WHT"·çÔÆÌìÏÂ"" 	HIW"HIW"·çÔÆÌìÏÂ"NOR" \n\n";

	msg += 
BBLU	"  	ºÚÉ«- BLK"BLK"·çÔÆÌìÏÂ"" \n"                       
BBLU	"  	ºìÉ«- RED"RED"·çÔÆÌìÏÂ""	HIR"HIR"·çÔÆÌìÏÂ"NOR" \n"
BBLU	"  	ÂÌÉ«- GRN"GRN"·çÔÆÌìÏÂ"" 	HIG"HIG"·çÔÆÌìÏÂ"NOR" \n"
BBLU	"  	»ÆÉ«- YEL"YEL"·çÔÆÌìÏÂ"" 	HIY"HIY"·çÔÆÌìÏÂ"NOR" \n"
BBLU	"  	À¶É«- BLU"BLU"·çÔÆÌìÏÂ"" 	HIB"HIB"·çÔÆÌìÏÂ"NOR" \n"
BBLU	"  	·ÛÉ«- MAG"MAG"·çÔÆÌìÏÂ"" 	HIM"HIM"·çÔÆÌìÏÂ"NOR" \n"
BBLU	"  	ÇàÉ«- CYN"CYN"·çÔÆÌìÏÂ"" 	HIC"HIC"·çÔÆÌìÏÂ"NOR" \n"
BBLU	"  	°×É«- WHT"WHT"·çÔÆÌìÏÂ"" 	HIW"HIW"·çÔÆÌìÏÂ"NOR" \n\n";

	msg += 
BMAG	"  	ºÚÉ«- BLK"BLK"·çÔÆÌìÏÂ"" \n"                       
BMAG	"  	ºìÉ«- RED"RED"·çÔÆÌìÏÂ""	HIR"HIR"·çÔÆÌìÏÂ"NOR" \n"
BMAG	"  	ÂÌÉ«- GRN"GRN"·çÔÆÌìÏÂ"" 	HIG"HIG"·çÔÆÌìÏÂ"NOR" \n"
BMAG	"  	»ÆÉ«- YEL"YEL"·çÔÆÌìÏÂ"" 	HIY"HIY"·çÔÆÌìÏÂ"NOR" \n"
BMAG	"  	À¶É«- BLU"BLU"·çÔÆÌìÏÂ"" 	HIB"HIB"·çÔÆÌìÏÂ"NOR" \n"
BMAG	"  	·ÛÉ«- MAG"MAG"·çÔÆÌìÏÂ"" 	HIM"HIM"·çÔÆÌìÏÂ"NOR" \n"
BMAG	"  	ÇàÉ«- CYN"CYN"·çÔÆÌìÏÂ"" 	HIC"HIC"·çÔÆÌìÏÂ"NOR" \n"
BMAG	"  	°×É«- WHT"WHT"·çÔÆÌìÏÂ"" 	HIW"HIW"·çÔÆÌìÏÂ"NOR" \n\n";

	msg += 
HBWHT	"  	ºÚÉ«- BLK"BLK"·çÔÆÌìÏÂ"" \n"                       
HBWHT	"  	ºìÉ«- RED"RED"·çÔÆÌìÏÂ""	HIR"HIR"·çÔÆÌìÏÂ"NOR" \n"
HBWHT	"  	ÂÌÉ«- GRN"GRN"·çÔÆÌìÏÂ"" 	HIG"HIG"·çÔÆÌìÏÂ"NOR" \n"
HBWHT	"  	»ÆÉ«- YEL"YEL"·çÔÆÌìÏÂ"" 	HIY"HIY"·çÔÆÌìÏÂ"NOR" \n"
HBWHT	"  	À¶É«- BLU"BLU"·çÔÆÌìÏÂ"" 	HIB"HIB"·çÔÆÌìÏÂ"NOR" \n"
HBWHT	"  	·ÛÉ«- MAG"MAG"·çÔÆÌìÏÂ"" 	HIM"HIM"·çÔÆÌìÏÂ"NOR" \n"
HBWHT	"  	ÇàÉ«- CYN"CYN"·çÔÆÌìÏÂ"" 	HIC"HIC"·çÔÆÌìÏÂ"NOR" \n"
HBWHT	"  	°×É«- WHT"WHT"·çÔÆÌìÏÂ"" 	HIW"HIW"·çÔÆÌìÏÂ"NOR" \n\n";
	write(msg);

	}

        return 1;
}



int help(object me)
{
        write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	Ö¸Áî¸ñÊ½ : color[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

Õâ¸öÖ¸Áî¿ÉÒÔÈÃÄãÖªµÀÓÎÏ·ÖÐ¸÷ÖÖÉ«²ÊµÄANSI¿ØÖÆ×ÖÔª¼°É«²ÊµÄ
ÊÔÑù£¬´Ó¶ø·½±ãÄúÑ¡ÔñÖÐÒâµÄÉ«²Ê¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m 
HELP );
        return 1;
}
