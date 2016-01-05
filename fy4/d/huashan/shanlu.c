#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
���������֣�һ��С·��������ǰ��ʯ���̾͵�ɽ·�϶�������ǰ���졣·��
ʯ����������һ��Ƭ��̦������֮�±���ʪ����̦��ʯ�����ˮ��һ�ελ�����
�£����������һ��СС��ʯ���
LONG
        );
    set("exits", ([ 
  		"northeast" : __DIR__"ziqi",
	    "westup" : __DIR__"yanluo",
	]));
   
    set("outdoors", "huashan");

	set("coor/x",-35);
	set("coor/y",-60);
	set("coor/z",30);
	setup();
}

void init() {
	object me;
	add_action("do_search", "search");
}

int do_search() {
	object me, ob;
	
	me = this_player();
	
	message("vision", me->name() + "�ڲݴ�����ϸѰ�ҡ�\n", environment(me), me);
	
	if (me->query("marks/turtle_room")==base_name(this_object())
			&& me->query_temp("marks/search_turtle")!=2) {
		if (me->query_temp("marks/search_turtle")==1) {	
			tell_object(me, "�㲦���ݴ���ϸѰ�ң���Ȼ����һֻ����������ϸϸ��ë�ڹ�����������\n"); 
			me->set_temp("marks/search_turtle",2);
			ob = new(AREA_HUANGSHAN"npc/turtle");
			if(objectp(ob)) {
				ob->set("turtle_owner",me);
				if (!ob->move(this_object()))
				{
					destruct(ob);
					tell_object(me,"��ë�ڹ����㻳�������꣬û�ҵ��ط��������ˡ�\n");
				}
			}
			return 1;
		}
	
		if (!present("green turtle", this_object())) {
			tell_object(me, YEL"���ݴ����ƺ���ʲô��������һ�£�����Ϊ�Լ��ۻ��ˡ�\n"NOR); 
			me->set_temp("marks/search_turtle", 1);
			return 1;
		} 
	}
	
	tell_object(me,"���ڻ�����������ȥ��ʲôҲû�з��֡�\n");
	return 1;
}