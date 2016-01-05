// exert.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string *cont = ({ "betrayal", "divorced", "marry", "m_success", "marks", "timer", 
				"death", "family" });
 	if (!arg)
 		return notify_fail("help renew1\n");
	if (member_array(arg, cont)==-1)
		return notify_fail("²Î¿´help betarenew\n");
 	if (arg == "death")
 		me->delete("attr_apply/strength");
 	else if (arg == "class" || arg == "family") {
 		me->delete("family");
 		me->delete("once_menpai");
 		me->delete("class");
 		me->delete("betrayal");
 	} else
 		me->delete(arg);
 	write("ÄãµÄ"+arg+"¼ÍÂ¼±»Çå³ıÁË¡£\n");
 	return 1; 
}


int help (object me)
{
    write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½£ºrenew1 <ÄÚÈİ> [0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m

²âÊÔÍæ¼Ò×¨ÓÃÖ¸Áî¡£È¥³ıËùÓĞÓĞ¹Ø¼ÇºÅ

betarenew betrayal : ¡¡	È¥³ıÅÑÊ¦¼ÍÂ¼
betarenew divorced :¡¡ 	È¥³ıÀë»é¼ÍÂ¼
betarenew marry		È¥³ı½á»é¼ÍÂ¼
betarenew m_success	È¥³ıÌì½¾¼ÍÂ¼
betarenew marks		È¥³ıËùÓĞÃÕÌâ¼ÍÂ¼(×îºÃÔÙupdateÒ»ÏÂ×Ô¼º)
betarenew timer		È¥³ıËùÓĞÊ±¼äÏŞÖÆ¼ÍÂ¼£¨±ÈÈçghostcurseµÄ£©
betarenew death		È¥³ıËÀÍöstr penalty
betarenew family	È¥³ıËùÓĞ°İÊ¦¼ÍÂ¼

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
HELP
        );
    return 1;
}
