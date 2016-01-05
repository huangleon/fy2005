inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "��ɽ·");
        set("long", @LONG
·��ɽת������ɽ�䣬�����Բһ�����н���Ȫ�ۣ���Ϊ��ҩ�ط�Ȫ������˵
��ͬ��Ȫˮ���в�ͬ����Ч�������˰����Ƿ�Ϊ��ĿȪ����θȪ��ϴ��Ȫ�ȡ�Զ����
�ɼ�������Ұţ��¹���ܡ��ǡ���ȶ��ﾢ�����¾����������������ɼ�����
Ѽ���Ϸˮ���������ˡ�
LONG
        );
        set("exits", ([ 
		"southwest" : __DIR__"mugecuo",
		"northeast":  __DIR__"linchang1",
		"westdown":   __DIR__"river",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1660);
        set("coor/y",640);
        set("coor/z",20);
	set("map","zbwest");
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