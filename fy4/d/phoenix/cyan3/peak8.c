// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
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
	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"northup" : "peak9",
  		"southup" : "peak6",
	]) );

	set("outdoors", "cyan");
	set("area","cyan3");

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
			if (w->query("climb"))
				i=10;
		if (dir == "northup" && random(i))
		{
			obj->receive_damage("kee",200);
			message_vision(RED"$N����������Ŭ����ǰ��ȥ������\n"NOR,obj);
			obj->move(this_object());
			return notify_fail("");
		}
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


