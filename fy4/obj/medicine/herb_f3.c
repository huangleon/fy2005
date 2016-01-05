/*	Herb heal by silencer@fy4.

compared it with normal healing pills
1. 5 silver ¹·Æ¤¸àÒ© 					20 sen
2. 20 silver ÔÆÄÏ°×Ò©£¬´ó·çÍè£¬»¢¹ÇÍè 			100kee/50sen/50gin
3. 60 silver ĞÜÕÆ/ÈË²Î/Â¹È×  				300kee/200gin/200sen
4. 100 silver	ÆßÉ«Óêºç»¨/ÈıÒ¶·ïÎ²²İ/Ñ©Ö¥  		1500kee/1000sen/1000gin
5. 200 silver	¾Å»¨ÓñÂ¶Íè/°×ÔÆĞÜµ¨Íè/´äĞä»¤ĞÄµ¤	5000kee/2500sen/2500gin


all can be collected by knight player.

L 100 herb, can be bought
type 1: herb_a: "Áúµ¨²İ","¹È¾«²İ","½ğÇ®²İ","µØ¶ú²İ","µÆĞÄ²İ", 	Level 100,  base_value 0.3-0.8g,    effect 500-2500 kee
type 2: herb_b: " "Ä¾Ïã","ÇàÄ¾Ïã","Ì´Ïã",			Level 100, base_value 0.5-0.7g      effect 500-1000-2000 sen/gin

L Level 150 herb random_drop 
type 1: herb_c: "¶¬³æÏÄ²İ","×ÏºÓ³µ","ÆßÒ¶Áú×¦»¨",  random(3) drop, knight 3000, 3500, 4000 kee
type 5: herb_d: "°×»¨Éß²İ","ÆßĞÄº£ÌÄ","ó¿ËÚÒ¶",    poison self-made weapon..... 
type 4  herb_e: "½ğÒø»¨"	depoison

L 200 herb
type 3: herb_f: "ÁéÖ¥","×ÏÌÙÒ¶"	random drop    4000/2000/2000 cure poison, heal both value.

So the parameters are
Level: requirement for herb level
field:  kee/gin(sen)/full/depoison/poison
effect: amount that it heals

*/

inherit MEDICINE;
#include <ansi.h>

void create()
{
	set_name("Òğ¼ä²İ",({"yincao", "herb"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long",(: herb_desc :));
	    set("unit","´Ø");
	    set("base_unit","¿Ã");
	    set("base_weight",30);
	    set("material","herb");
	    
	    set("usage_type","herb");
	    set("heal_type","kee/10");
	    set("type","full");
	    set("base_value",0);
	    set("level",150);
	    set("effect",5000);
	    set("field","kee");
	    set("volumn",1);
	}
	set_amount(1);
}
