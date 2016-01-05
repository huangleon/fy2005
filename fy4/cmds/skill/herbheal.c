/*	Herb heal by silencer@fy4.

compared it with normal healing pills
1. 2 silver ¹·Æ¤¸àÒ© 					40 sen
2. 3 silver ÔÆÄÏ°×Ò©£¬´ó·çÍè£¬»¢¹ÇÍè 			100kee/50sen/50gin
3. 10 silver ĞÜÕÆ/ÈË²Î/Â¹È×  				300kee/200gin/200sen
4. 60 silver	ÆßÉ«Óêºç»¨/ÈıÒ¶·ïÎ²²İ/Ñ©Ö¥  		1500kee/1000sen/1000gin
5. 200 silver	¾Å»¨ÓñÂ¶Íè/°×ÔÆĞÜµ¨Íè/´äĞä»¤ĞÄµ¤	5000kee/2500sen/2500gin


all can be collected by knight player.

L 100 herb, can be bought
type 1: herb_a: "Áúµ¨²İ","¹È¾«²İ","½ğÇ®²İ","µØ¶ú²İ","µÆĞÄ²İ", 	
	Level 100, base_value effect 500(2s)-1000(4s)-1500(6s)-2000(8s)-2500(10s) kee
type 2: herb_b: " "Ä¾Ïã","ÇàÄ¾Ïã","Ì´Ïã",			
	Level 100, base_value effect 500(2s)-1000(4s)-1500(6s) sen/gin

L Level 150 herb random_drop 
type 1: herb_c: "¶¬³æÏÄ²İ","×ÏºÓ³µ","ÆßÒ¶Áú×¦»¨",  
	random(3) drop, knight 3000, 3500, 4000 kee
type 5: herb_d: "°×»¨Éß²İ","ÆßĞÄº£ÌÄ","ó¿ËÚÒ¶",    poison self-made weapon..... 
	L75(75), L100 (150), L150 (200), L180(250), L200(300)
	2s-4s-5s-6s-7s	
type 4  herb_e: "½ğÒø»¨"	depoison	20s

L 200 herb
type 3: herb_f: "ÁéÖ¥","×ÏÌÙÒ¶"	random drop    4000/2000/2000 cure poison, heal both value.

Level: requirement for use herb
type : cure,  full, poison, depoison,
field:  kee/gin/sen
effect: amount that it heals, or it poisons,

*/

#include <ansi.h>
#include <condition.h>
inherit "/daemon/condition/generic_condition";
inherit F_CLEAN_UP;

int main(object me, string arg){
        
        int level, herb_level, effect;
        string type, field;
        
        string plant;
        object herb;
        
	if( !arg || sscanf(arg, "with %s", plant)!= 1 ) 
		return	notify_fail("Ö¸Áî¸ñÊ½£ºherbheal with <Ò©²İÃû>\n");

        if (me->is_busy())
        	return notify_fail("ÄãÏÖÔÚÕıÃ¦×Å£¬Ã»¿ÕÁÆÉË¡£\n");
        	
        if( me->is_fighting() )
                return notify_fail("Õ½¶·ÖĞÔË¹¦ÁÆÉË£¿ÕÒËÀÂğ£¿\n");

	level = me->query_skill("herb",1);
	if(level < 50 )
                return notify_fail("ÖÁÉÙĞèÒª50¼¶Ò©µÀ²ÅÄÜ±æ±ğÒ©²İµÄÓÃÍ¾¡£\n");

	herb = present(plant,me);
	if (!herb)
		return notify_fail("ÄãÉíÉÏÃ»ÓĞĞ¯´ø"+plant+"\n");
	
	type = herb->query("type");
	if (type!="cure" && type!="full" && type!="depoison")
		return notify_fail(herb->name()+"²»ÄÜÓÃÀ´ÁÆÉË¡£\n");
	           
        herb_level = herb->query("level");
        if (level < herb_level )
        	return notify_fail("Äã¶Ô´ËÖÖÒ©²İµÄĞÔÄÜÉĞ²»ÁË½â£¬ÎŞ·¨ÓÃÆäÀ´ÁÆÉË¡£\n");
        
        if(me->query("force")<200)
        	return notify_fail("ÔËÓÃÒ©µÀĞèÒª200µãÕæÆø¡£\n");
        me->add("force", -200);
        me->force_status_msg("force");
                        
        write( HIG "ÄãÈ¡³ö"+ herb->name() + HIG"·ÅÔÚ¿ÚÖĞ½ÀÀÃ£¬È«Éí·ÅËÉ£¬×øÏÂÀ´¿ªÊ¼½«ÕæÆøÔÚ¾­ÂöÖĞ»º»ºÁ÷¶¯¡£\n" NOR);
        message("vision", HIG + me->name() + "×øÏÂÀ´ÔËÆğÒ©µÀĞÄ·¨ÁÆÉË£¬Í·ÉÏÃ°³öÂÆÂÆ°×Æø£¬
²»¾Ã£¬ÍÂ³öÒ»¿ÚğöÑª£¬Á³É«¿´ÆğÀ´ºÃ¶àÁË¡£\n"NOR,environment(me), me);
	
	field = herb->query("field");
	if (type == "cure")
	{
		switch (field) {
			case "kee": 	effect = herb->query("effect");
					me->receive_curing("kee", effect);
					tell_object(me,"ÄãµÄÆøÑªÖÎÓúÁË"+effect+"µã¡£\n");
					break;
			case "sen":	
			case "gin": 	effect = herb->query("effect");
					me->receive_curing("gin",effect);
					me->receive_curing("sen",effect);
					tell_object(me,"ÄãµÄ¾«Á¦ºÍĞÄÉñÖÎÓúÁË"+effect+"µã¡£\n");
					break;
			default:	tell_object(me,"Èç¹ûÄã¿´µ½Õâ¾ä»°£¬Çë±¨¸æÎ×Ê¦¡£\n");
		}
	}
	if (type == "full")
	{
		switch (field) {
			case "kee": 	effect = herb->query("effect");
					me->receive_fulling("kee", effect);
					tell_object(me,"ÄãµÄÆøÑª»Ø¸´ÁË"+effect+"µã¡£\n");
					break;
			case "sen":	
			case "gin": 	effect = herb->query("effect");
					me->receive_fulling("gin",effect);
					me->receive_fulling("sen",effect);
					tell_object(me,"ÄãµÄ¾«Á¦ºÍĞÄÉñ»Ø¸´ÁË"+effect+"µã¡£\n");
					break;
			default:	tell_object(me,"Èç¹ûÄã¿´µ½Õâ¾ä»°£¬Çë±¨¸æÎ×Ê¦¡£\n");
		}
	}
	if (field == "depoison")
		me->clear_condition();		
	if (field == "depoisonx")
		me->clear_condition_type(LOW_POISON);	        

        herb->add_amount(-1);
        me->start_busy(2);
        return 1;
}
 
int help(object me)
{
	write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	herbheal with <Ò©²İÃû> [0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

¿ì»îÁÖµÜ×ÓµÄ×¨³¤£¬ÀûÓÃÒ©²İÑ¬ÁÆÉË¿Ú£¬ÎªÎäÁÖÖĞÁÆÉËÊ¥Êõ¡£
£¨ÖÁÉÙĞèÒª50¼¶Ò©µÀ£©

²»Í¬µÄÒ©²İÓĞ²»Í¬µÄÒ©Ğ§£¬Ò©µÀÔ½¸ß£¬¶ÔÒ©²İµÄÁË½â¾ÍÔ½Éî¿Ì¡£
Ò©²İÔÚ¿ì»îÁÖºÍ·çÔÆ³Ç¶¼ÓĞ³öÊÛ£¬¿ÉÓÃ£ó£á£í£ğ£ì£åÖ¸Áî²ì¿´
Æä¹¦Ğ§¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
 
HELP
    );
    return 1;
}
 
 