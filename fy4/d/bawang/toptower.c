inherit ROOM;

void create()
{
	set("short", "¶ÏËş¶¥");

	set("long", @LONG
ÕâÀïÊÇ¶ÏËş¶¥£¬Ò»Õµ»ÆÓÍÖ½µÆÁı£¬ÓÃÖñ¸ÍĞ±Ğ±ÌôÆğ¡£Öñ¸Í²åÔÚ¶ÏÇ½Àï£¬µÆÁı²»
Í£µØÒ¡»Î¡£»è°µµÄµÆ¹âÏÂÓĞÈı¸öÈË£¬Ò»¸öË¥ÀÏØşÙÍµÄ²Ğ·ÏÈË£¬Òõ°µ³óÂªµÄÁ³ÉÏÂúÊÇ
µ¶°Ì¡£Ò»¸öÖĞÄê½õÒÂ´óºº£¬ÁíÒ»¸öÔòÊÇ¸öºÜ¸ß´óµÄºÚÒÂÈË£¬ÀäÀäµØÕ¾ÔÚ[33m´°[32m±ß¡£ 
LONG);

	set("type","street");
	set("exits",([
		"down":__DIR__"broketower5",
	]) );

	set("item_desc", ([
		"´°":	"Ò»ÉÈÆÆ¾ÉµÄ´°»§£¬´°À¸ÒÑ¾­Ã»Ê£ÏÂ¼¸¸ùÁË£¬Äã¿ÉÒÔÊÔ×ÅÌø³öÈ¥£¨jumpout window£©\n",
		"window":	"Ò»ÉÈÆÆ¾ÉµÄ´°»§£¬´°À¸ÒÑ¾­Ã»Ê£ÏÂ¼¸¸ùÁË£¬Äã¿ÉÒÔÊÔ×ÅÌø³öÈ¥£¨jumpout window£©\n",

	]));
	
	set("objects", ([
		__DIR__"npc/baili_changqing": 1,
		__DIR__"npc/deng":1,
		__DIR__"npc/hu_5":1
	]));
	set("indoors", "bawang");
	setup();

	set("coor/x",-15);
	set("coor/y",10);
	set("coor/z",40);
}



void init(){	
	add_action("do_jump","jumpout");
}


int do_jump(string arg){
	
	object me, ob, room;
	
	me = this_player();
	
	if (!arg || arg!="window")	return 0;

	if (ob=present("baili"))
		return notify_fail(ob->name()+"ÀäÀäµØµ²ÔÚÄãµÄÉíÇ°µÀ£ºÊÇ·ÇÖ®µØ£¬ÄÄÀïÀ´µÄ£¬»¹´ÓÄÄÀïÏÂÈ¥°É¡£\n");
		
	message_vision("$NÔ¾ÉÏ´°Ì¨£¬ËÄÏÂ¿´ÁË¿´£¬×İÉíÏòÍâÌøÈ¥¡£\n", me);
		
	room = find_object("/d/bawang/undertower2");
	if(!room) room=load_object("/d/bawang/undertower2");
	me->move(room);
	message("vision", me->name()+"´ÓËşÉÏÃæ»º»ºÂäÁËÏÂÀ´£¬\n", environment(me), me);
	
	return 1;
}