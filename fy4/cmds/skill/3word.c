//	Silencer@fy4 workgroup

#include <ansi.h>
inherit F_CLEAN_UP;

int main (object me, string arg)
{
	int iron, i,duration;
	string msg;
	string *word;
	string *temp = ({"an", "ba", "hong", "ma", "mi", "ni" });
	
	if (me->query("class")!= "lama")
		return notify_fail("Ö»ÓÐ´óÕÑµÜ×Ó²ÅÄÜÐû¡ºÈý×ÖÕæÑÔ¡»\n");
		
	iron = me->query_skill("kwan-yin-spells",1);
	if (iron < 200)
		return notify_fail("¡ºÈý×ÖÕæÑÔ¡»ÐèÒª200¼¶¹ÛÒôÁù×ÖÃ÷Öä¡£\n");

	if (!arg)
		return notify_fail("ÄãÏÖÔÚ×¼±¸µÄÈý×ÖÕæÑÔÎª£º"+ me->query("marks/pfm/3word")+"\n");
	
/*	if (me->is_busy())
		return notify_fail("ÄãÏÖÔÚÕýÃ¦£¬ÎÞ·¨¾²Ë¼ÕæÑÔ¡£\n");
				
	if(me->is_fighting() )
		return notify_fail("¡ºÈý×ÖÕæÑÔ¡»²»ÄÜÔÚÕ½¶·ÖÐ¼ÇÒä¡£\n");
*/
	
	word = allocate(3);
	
	if (sscanf(arg,"%s+%s+%s",word[0],word[1],word[2])!=3)
		return notify_fail("Èý×ÖÕæÑÔÉèÖÃµÄ¸ñÊ½²»¶Ô£¬Çë²Î¿´help 3word\n");
	
	message_vision(HIY"$N"NOR+HIY"µø×øÔÚµØ£¬Ë«ÍÈÅÌÂ££¬ºÏÊ®ÄîµÀ£ºÈô¸´ÓÐÈË£¬µÃÎÅÊÇ¾­£¬²»¾ª¡¢²»²À¡¢²»Î·£¬µ±ÖªÊÇÈËÉõÎªÏ£ÓÐ¡£
ºÎÒÔ¹Ê£¿ÈçÀ´Ëµ£ºµÚÒ»²¨ÂÞÃÛ£¬·ÇµÚÒ»²¨ÂÞÃÛ£¬ÊÇÃûµÚÒ»²¨ÂÞÃÛ¡£\n"NOR,me);
	
	for (i=0;i<3;i++){
		if (member_array(word[i],temp)==-1)
			return notify_fail(word[i]+"²»ÊÇÈý×ÖÕæÑÔÖ®Ò»¡£\n");
		write(" µÚ" + chinese_number(i+1) +"¸öÕæÑÔÊÇ£º" + word[i] +"\n");	
	}
	
	
	me->set("marks/pfm/3word",arg);
	
	return 1;
}



int help(object me)
{
write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	3word[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

´óÕÑ¸ßÉ®ÐÞÁ¶¹ÛÒôÃ÷Öäµ½200¼¶ÒÔÉÏºó£¬¿ÉÍ¬Ê±ËÌ³öÊý×ÖÕæÑÔ£¬
µ«ÊÇ£¬ÔÚÊ¹ÓÃÖ®Ç°±ØÐë¾²Ë¼Æ¬¿Ì¼ÇÒä¡£

¸ñÊ½¾ÙÀý£º¡¡3word an+an+an
ÓÖÈç£º	   3word an+ni+ni

Ê¹ÓÃcast 3word ±ã¿É½«¼ÇÒä×¡µÄÕæÑÔÍ¬Ê±ËÌ³ö¡£

¶ÔÓÚÈý×ÖÕæÑÔÀ´Ëµ£¬ºÄ·ÑµÄ·¨Á¦×î¶à²»³¬¹ý450£¬Ôì³ÉµÄ×ÔÎÒÃ¦ÂÒ
×î¶à²»³¬¹ý6¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
HELP
    );
    return 1;
}