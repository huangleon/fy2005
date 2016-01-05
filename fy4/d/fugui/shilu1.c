inherit ROOM;

void create()
{
	set("short", "ÇàÊ¯Ïï");

	set("long", @LONG
ÕâÊÇÌõÇàÌõÊ¯Æö³ÉµÄĞ¡Ïï£¬±ÈÆğ¼ªÏéÕòµÄĞ¡½Ö¿í³¨ÁË²»ÉÙ£¬µ¹Ò²»¹ËãÆ½Õû£¬Â·
ÅÔÁ½ÅÅ[37méªÄ¾Ê÷[32mĞŞ¼ôµØÕûÕûÆëÆë£¬Ê±²»Ê±»¹ÓĞ¼¸Á¾ËÄÂÖµÄÂí³µÑØÂ··É¿ìµÄ³åÈëÏï×Ó¡£
LONG);
	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
		"west":__DIR__"xiaojie4",
		"northeast":__DIR__"shilu2",
	]) );
   	set("item_desc", ([
		"tree": "ÕâÊÇ¿Ã¸ß´óµÄéªÄ¾Ê÷£¬Ö¦Ò¶Ã¯Ê¢£¬ËÆºõ¶¼Éì½øÁË½ğ´óË§¸®¡£\n",
		"éªÄ¾Ê÷": "ÕâÊÇ¿Ã¸ß´óµÄéªÄ¾Ê÷£¬Ö¦Ò¶Ã¯Ê¢£¬ËÆºõ¶¼Éì½øÁË½ğ´óË§¸®¡£\n",
				
    ]) );
	set("coor/x",30);
	set("coor/y",80);
	set("coor/z",0);
	setup();
}

void init ()
{
        add_action ("do_climb", "climb");
}

int do_climb (string arg)
{
	object me,room;
	int move;
	if (!arg || (arg != "tree" && arg != "Ê÷"))
		return notify_fail("ÄãÒªÅÀÊ²Ã´£¿\n");
	me = this_player();
	move = me->query_skill("move",1);
	if (move < 40)
		return notify_fail("Ê÷Ì«¸ßÁË£¬ÄãÅÀ²»ÉÏÈ¥¡££¨Ğè40¼¶Çá¹¦£©\n");
	
	message_vision("$NÎüÁË¿ÚÆø£¬ÊÖ×ã²¢ÓÃ£¬ÂıÂıµÄÅÀÉÏÂ·±ßµÄ´óÊ÷¡£\n",me);
	room = find_object(__DIR__"tree");
	if(!room)
		room=load_object(__DIR__"tree");
	me->move(room);
        message("vision",me->name()+"´ÓÊ÷ÏÂÅÀÁËÉÏÀ´¡£",room,me);
	return 1;
}
