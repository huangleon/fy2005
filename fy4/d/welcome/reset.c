// Silencer@fy4 workgroup

// ÊôĞÔÖØÖÃ£¬´æÅÌ

// ÆäËûÊôĞÔÇåÁã¡¢¼¼ÄÜÇåÁã£¬´æÅÌ

// ²¹»Ø»ù±¾µÄ¼¼ÄÜ¡¢Êé¼®



inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIW"ÊôĞÔ·ÖÅä·¿¼ä"NOR);
	set("long", @LONG
LONG
	);
	set("exits", ([
	]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",700);
	set("no_magic",1);
	set("no_fight",1);
	set("valid_startroom", 1);
	setup();
}

int init(){
	object me;
	string *att = ({"int","cps","agi","str","con","kar"});
	string *att_c = ({ "²ÅÖÇ","¶¨Á¦","ËÙ¶È","Á¦Á¿","ÌåÖÊ","ÔËÆø" });
	int i;
	
	// ÖØĞÂ·ÖÅäÊôĞÔµã
	me = this_player();
	if (me->query("id") != "tester")	return 1;
	
	tell_object(me,"==========================================\n");
	for (i=0;i<sizeof(att);i++){
		tell_object(me,"ÄãÔø¾­·ÖÅäÁË"+ me->query("distribute/"+ att[i])+ "µã"+ att_c[i]+"\n");		
	}
	
	tell_object(me,"\nÏÖÔÚ¿ªÊ¼ÖØĞÂ·ÖÅäÊôĞÔµã£¬Ô­À´µÄ¶¼ÒÑ¾­ÖÃÁã¡£\n\n");
	tell_object(me,"ÃüÁîÎª[37m£ä£é£ó£ô£ò£é£â£õ£ô£å[32m£¬ºó¸úÄãÏ£ÍûµÄÊôĞÔ£¬
[37mÀı£º£ä£é£ó£ô£ò£é£â£õ£ô£å¡¡£ã£á£é£ú£è£é[32m£¨»ò²ÅÖÇ£©
¼´Ôö¼ÓÒ»µã²ÅÖÇ¡£\n");

	tell_object(me,"==========================================\n");
	
//	me->delete("distribute");
//	me->delete("used_gift_points");
	me->save();
	add_action("do_distribute","distribute");
		
}

int update_player(object me)
{
        object env, link_ob, obj;
        me->save();
        write ("ËùÓĞ²ÎÊıµã·ÖÅäÍê±Ï£¬×Ô¶¯½øÈëÏÂÒ»¸ö·¿¼ä¡£\n");
        obj->move(__DIR__"reset2");
        return 1;
}

int do_distribute(string arg)
{
	int gift_points;
	int used_gift_points;
	object me;
	
	me = this_player();
		
	me->set("update/fy51_attr_reset",1);
	
	if( !arg ) 
		return notify_fail("ÄãÒª·ÖÅäµ½ÄÄ¸ö²ÎÊıÉÏ£¿
Àı£º£ä£é£ó£ô£ò£é£â£õ£ô£å¡¡£ã£á£é£ú£è£é£¨»ò²ÅÖÇ£©\n");
	gift_points = me->query("gift_points");
	used_gift_points = me->query("used_gift_points");
	if( used_gift_points >= gift_points )
		return notify_fail("ÄãÃ»ÓĞ²ÎÊıµãÊ£ÓàÁË¡£\n");
	
	switch (arg) {
	case "²ÅÖÇ" :
	case "caizhi" :
			if((int) me->query("distribute/int") >=5)
				return notify_fail("ÄãµÄ²ÅÖÇ²»¿ÉÒÔÓÃ·ÖÅäµÄ·½·¨ÔÙÌá¸ßÁË¡£\n");
			me->add("used_gift_points",1);
			me->add("distribute/int",1);
			me->add("int",1);
			break;
        case "ÌåÖÊ" :
        case "tizhi" :
                        if((int) me->query("distribute/con") >=5)
                        	return notify_fail("ÄãµÄÌåÖÊ²»¿ÉÒÔÓÃ·ÖÅäµÄ·½·¨ÔÙÌá¸ßÁË¡£\n");
                        me->add("used_gift_points",1);
                        me->add("con",1);
                        me->add("distribute/con",1);
                        break;
        case "ÔËÆø" :
        case "yunqi" :
                        if((int) me->query("distribute/kar") >=5)
                        return notify_fail("ÄãµÄÔËÆø²»¿ÉÒÔÓÃ·ÖÅäµÄ·½·¨ÔÙÌá¸ßÁË¡£\n");
                        me->add("used_gift_points",1);
                        me->add("kar",1);
                        me->add("distribute/kar",1);
                        break;
        case "Á¦Á¿" :
        case "liliang" :
                        if((int) me->query("distribute/str") >=5)
                        return notify_fail("ÄãµÄÁ¦Á¿²»¿ÉÒÔÓÃ·ÖÅäµÄ·½·¨ÔÙÌá¸ßÁË¡£\n");
                        me->add("used_gift_points",1);
                        me->add("str",1);
                        me->add("distribute/str",1);
                        break;
        case "ËÙ¶È" :
        case "sudu" :
                        if((int) me->query("distribute/agi") >=15)
                        return notify_fail("ÄãµÄËÙ¶È²»¿ÉÒÔÓÃ·ÖÅäµÄ·½·¨ÔÙÌá¸ßÁË¡£\n");
                        me->add("used_gift_points",1);
                        me->add("agi",1);
                        me->add("distribute/agi",1);
                        break;
        case "¶¨Á¦" :
        case "dingli" :
                        if((int) me->query("distribute/cps") >=15)
                        return notify_fail("ÄãµÄ¶¨Á¦²»¿ÉÒÔÓÃ·ÖÅäµÄ·½·¨ÔÙÌá¸ßÁË¡£\n");
                        me->add("used_gift_points",1);
                        me->add("cps",1);
                        me->add("distribute/cps",1);
                        break;
        default :
			return notify_fail("Ã»ÓĞÕâ¸ö²ÎÊı¡£
Àı£º£ä£é£ó£ô£ò£é£â£õ£ô£å¡¡£ã£á£é£ú£è£é£¨»ò²ÅÖÇ£©\n");

	}
	write("ÄãµÄ"+ arg + "Ìá¸ßÁËÒ»µã¡£\n");
	if ( used_gift_points < 9)
		write("Äã»¹ÓĞ"+ chinese_number(gift_points - used_gift_points-1) + "µã²ÎÊı£¬Çë¼ÌĞø·ÖÅä¡£\n");
	else 
		{
			update_player(me);
		}
	return 1;
}




	
	
	


