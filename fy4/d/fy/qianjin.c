inherit ROOM;
int check_container(object ob);
void create()
{
    set("short", "Ç§½ğÂ¥Íâ");
    set("long", @LONG
´ËÂ¥Ëä²»ÔÚ¾©¶¼£¬µ«È´ÊÇÖĞÔ­×îÓĞÃûµÄÇàÂ¥¡£ÕâÀïÓĞ×î¹óµÄ¾Æ£¬Ò²ÊÇ×îºÃµÄ¾Æ£»
ÕâÀïÓĞ×î¹óµÄÅ®ÈË£¬Ò²ÊÇ×îÓĞÎ¶¶ùµÄÅ®ÈË£»ÕâÀïÓĞ×î¹óµÄ·şÎñ£¬Ò²ÊÇ×îºÃµÄ·şÎñ¡£
Öìºì´óÃÅÉÏÅÆ£¨£ó£é£ç£î£©Ò»¿é£¬ÓÖ¸ßĞüÒ»¿éÓù´Í½ğØÒ£º
[1;35m
			´ºÉ«ÎŞ±ß
[2;37;0m
LONG
    );
    set("exits", ([
	"east" : __DIR__"huanyun3",
	"west" : AREA_QIANJIN"pingfeng",
      ]));
    set("item_desc", ([
	"sign": @TEXT
Ç§½ğÂ¥Â¥¹æ£º
£±£®²»¿É¼Ğ´øÈÎºÎ±øÆ÷ÈëÂ¥¡£
£²£®ÒÔ·ÀÄú±»Ç§½ğÂ¥Ğ¡½ãÎóÈÏÎªÃ»ÓĞÏû·ÑÄÜÁ¦£¬
¡¡¡¡²»¿É¼Ğ´øÈÎºÎÊ³Îï£¬¾ÆË®ÈëÂ¥¡£
£³£®´ó¼Ò³öÃÅÔÚÍâÊÇÅóÓÑ£¬Ïà»¥¸øµãÃæ×Ó£¬
¡¡¡¡´ò¼Ü£¬ÄÖÊÂÕßÂ¥¹æ´¦ÖÃ¡£
£´£®£¢ÉÍÍ·£¢¸øµÃÔ½¶à£¬ÄúÊÜµÄËÅºîÔ½ºÃ¡£

ÅÆÏÂ»¹Ìù×ÅÒ»ÕÅĞ´×ÅÍáÍáÅ¤Å¤¼¸¸ö×ÖµÄĞ¡Ö½Ìõ(paper)¡£
TEXT
,
	"paper": @TEXT
Ğ¡Ö½ÌõÉÏÍáÍáÅ¤Å¤Ğ´×Å£º
ÓëÈË·½±ã£¬×Ô¼º·½±ã£¬¶şÊ®Á½Òø×Ó£¬´ó¼Ò¶¼·½±ã¡£
TEXT
      ]) );

    set("outdoors","fengyun");
    set("NONPC",1);
    set("objects", ([
	__DIR__"npc/guinu" : 2,
      ]) );
    set("coor/x",-80);
    set("coor/y",-200);
    set("coor/z",0);
    set("map","fysouth");
    setup();
}

int valid_leave(object me, string dir)
{
    object *inv, ob;
    int i, dayPhase;

    if(dir == "west") {
	if(!ob = present("gui nu",this_object())) {
	    ob = new(__DIR__"npc/guinu");
	    if(ob) {
		ob->move(this_object());
		message_vision("Ò»¸ö¹êÅ«´ÓÇ§½ğÂ¥ÀïÓ­ÁË³öÀ´¡£\n", me);
	    }	
	}

	if (me->query_temp("annie/pay_guinu"))
	{
		me->delete_temp("annie/pay_guinu");
		me->set("food",0);
		me->set("water",0);
		message_vision("¹êÅ«×ª¹ıÍ·È¥£¬¼Ù×°Ê²Ã´Ò²Ã»ÓĞ¿´¼û¡£\n", me);
		return 1;
	}

	dayPhase = NATURE_D->get_current_day_phase();
	if(dayPhase > 0 && dayPhase < 6) {
	    message_vision("¹êÅ«ÍûÍûÌì£¬¶Ô$NĞ¦×ÅËµ£ºÊ±³½ÉĞÔç£¬¹ÃÄïÃÇ»¹ÔÚË¯£¬Äú£®£®£®\n", me);
	    return notify_fail("ÈÌÄÍÒ»ÏÂ°É£¡\n");
	}
	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++) {
	    if(((int)inv[i]->query("weapon_prop")) ||
	      ((int)inv[i]->query("food_remaining") != 0) ||
	      ((int)inv[i]->query("liquid/remaining") !=0) ||
	      ((int)inv[i]->is_container()))
		return notify_fail("¹êÅ«ÏòÄãĞ¦µÀ£ºÇ§½ğÂ¥ÓĞÇ§½ğÂ¥µÄÂ¥¹æ£¬ÄúÇë¿´ÅÆ£®\n");
	}
	me->set("food",0);
	me->set("water",0);
    }
    return 1;
}
