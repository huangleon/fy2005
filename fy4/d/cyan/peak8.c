// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "��أ��");
    set("long", @LONG
�Ӱ�ŭ�����������ó�أ����ǺųƼ���֮�ա���·֮����ֱ�����ƣ�ب
�����죬����������޷����������֮�¡�̧üչ����������ɽΡ�����Σ��
��ѹ����ֱ��Ҫ����ǵصس��㵹ѹ�����������ڰ�ŭ����Զ������������һ
�ֹ⾰��
LONG
NOR
        );
	set("objects", ([
	__DIR__"npc/bored":1,
	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"northup" : __DIR__"peak9",
  		"southup" : __DIR__"peak6",
	]) );

	set("outdoors", "cyan");

	set("coor/x",-60);
	set("coor/y",60);
	set("coor/z",80);
	setup();
}


int valid_leave(object obj, string dir){
	object w;
	int i;
	if (userp(obj))
	{
		i=20;
		w = obj->query_temp("weapon");
		if (w)
			if (w->query("skill_type") == "spear" || w->query("skill_type") == "staff")
				i=1;
		if (dir == "northup" && random(i))
		{
			obj->receive_damage("kee",200);
			message_vision(RED"$N����������Ŭ����ǰ��ȥ������\n"NOR,obj);
			obj->move(this_object());
			return notify_fail("");
		}
		if (w)
			message_vision("$N����"+w->name()+NOR"�����������������¶���\n"NOR, obj);
	}
	return 1;
}

/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/


