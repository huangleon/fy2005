// wizlist.c
//	--- Credit goes to SNOWMAN@SJ, modified by Silencer@FY4

#include <ansi.h>

inherit F_CLEAN_UP;

mapping hoodname=([
	"(admin)" :  	"°æ"HIW" œµ°°Õ≥ "NOR"°ø",
	"(arch)" : 	    "°æ"HIR" π‹°°¿Ì "NOR"°ø",
	"(wizard)" : 	"°æ"HIG" ø™°°∑¢ "NOR"°ø",
	"(apprentice)": "°æ"HIY" —ß  ÕΩ "NOR"°ø",
	"(immortal)" :  "°æ"HIM" πÀ°°Œ  "NOR"°ø"
]);
int level(mixed, mixed);
int imm(string wizid);

int main(object me, string arg)
{
        string *list, hood = "", str;
        int i, j;

        list = sort_array(SECURITY_D->query_wizlist(), (: level :));
 //	    if (!wiz_level(me)) list = filter_array(list, (: imm :));
        str = sprintf("\n%-30s\n",
        	WHT"°§"+MUD_NAME+"ƒø«∞π≤”–" + sizeof(list) + "ŒªŒ◊ ¶°§"NOR);
		str = replace_string(str, "  ", "©§");
        i = sizeof(list);
        while(i--) {
                if (hood != wizhood(list[i])) {
                        hood = wizhood(list[i]);
                        if( j ){
                        	while(j > 6) j -= 6;
                        	j = 6 - j;
                        	if( j > 0){
                        		while(j--) str += "         ";
					str += "°°";
                        	}
                        	else str += "°°";
                        }
                        str += sprintf("\n°°%-12s£∫"NOR, hoodname[hood]);
                        j = 0;
                }

                j++;
                if( j > 6 && j%6==1 )
                	str += "°°\n°°\t\t";
		str += sprintf("%-9s", capitalize(list[i]));
        }

        if( j ){
                while(j > 6) j = j - 6;
                j = 6 - j;
                if( j > 0) {
                	while(j--) str += "         ";
			str += "°°";
                }

                else str += "°°";
        }
        
        write(str+"\n");
        
        if (wiz_level(me))
		write("
===================================================================
∑Á‘∆π§◊˜◊È∑÷π§£∫

"WHT"1°£IMMORTAL πÀŒ "NOR"
IMMORTAL±æ…Ì «ÕÊº“£¨∑«’˝ ΩŒ◊ ¶£¨Œﬁ∑®Ω¯»ÎŒ◊ ¶∆µµ¿£¨≤ªƒ‹¥¶¿Ì∏ƒ∂Ø”Î”Œœ∑
ªÚÕÊº“”–πÿµƒ√¸¡Ó∫Õ ˝æ›°£ÀÊ◊≈ø™’æ ±º‰µƒ—”≥§£¨π‹¿Ì»À‘±≤ªø…ƒ‹∂˛ ÆÀƒ–° ±
‘⁄œﬂ£¨¥À»®œﬁø…“‘Ωª∏¯“ª–©ø…–≈»Œµƒ”÷ƒ‹≥§∆⁄‘⁄œﬂ°¢ Ïœ§”Œœ∑πÊ‘ÚµƒÕÊº“£¨∆‰
÷˜“™‘»Œ «∞Ô÷˙ÕÊº“£¨ªÓ‘æ∆¯∑’£¨Ω‚æˆ“ª–©–Ó“‚µ∑µ∞µƒŒ Ã‚°£
ƒø«∞ø…“‘¥¶¿Ìµƒ√¸¡Ó: edemote, nulock

"WHT"2°£WIZARD ø™∑¢»À‘±"NOR"
À˘”–≤ªπ‹¿Ìµ±«∞’æµ„µƒ∑Á‘∆π§◊˜◊È»À‘±£¨∆‰÷˜“™ƒøµƒ‘⁄”⁄π€≤Ï¡ÀΩ‚”Œœ∑‘À––«È
øˆ£¨Œ™Ω¯“ª≤Ωø™∑¢∑Á‘∆◊˜◊º±∏°£∆‰‘»ŒŒ™ºÏ≤ÈœµÕ≥‘À––£¨—∞’“£¬£’£«£¨¥À»®œﬁ
Œﬁ∑®–ﬁ∏ƒªÚ≤Èø¥ÕÊº“ ˝æ›°£
ø…“‘¥¶¿Ìµƒ”∞œÏÕÊº“√¸¡Ó: ban,exec,nuke,summon
full(◊‘…Ì), get(∑«NPC)£¨halt(◊‘…Ì)£¨goto£®∑«ƒ⁄≤ø£©,update(ÕÊº“)

"WHT"3°£ARCH π‹¿Ì»À‘±"NOR"
µ±«∞’æµ„µƒπ‹¿Ì»À‘±£¨∆‰‘»ŒŒ™π‹¿ÌŒ¨ª§’æµ„£¨¥¶¿ÌÕÊº“√¨∂‹£¨–ﬁ’˝¥ÌŒÛ£®ø…
–ﬁ∏ƒ≥˝œµÕ≥º«¬ºÕ‚µƒ ˝æ›£©

"WHT"4°£ADMIN œµÕ≥»À‘±"NOR"
‘»Œ£∫–≠µ˜∑Á‘∆π§◊˜◊Èµƒ»ŒŒÒ£¨Ã·π©µ±«∞’æµ„µƒ”≤º˛÷ß≥÷
===================================================================
\n");        
        return 1;
}

int imm(string wizid)
{
	return wiz_level(wizid) == 4;
}

int level(mixed ob1, mixed ob2)
{
        if (wiz_level(ob1) != wiz_level(ob2))
                return wiz_level(ob1) - wiz_level(ob2);
        return ob1 > ob2?-1:1;
}


int help(object me)
{
write(@HELP
[0;1;37m©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§[0m
[0;1;36m÷∏¡Ó∏Ò Ω : 	wizlist[0m
[0;1;37m©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§[0m   

”√Õæ : ¡–≥ˆ∏√”Œœ∑’æµ„À˘”–Œ◊ ¶√˚µ•°£

[0;1;37m©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§[0m 
HELP
     );
     return 1;
}
