// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "���ƶ�");
    set("long", @LONG
���������ƾ������������ǰ��ɫһ�㡣�����ʯ��ᾡ���ľ�дС��±�
���ͣ�ֻ���������˼��ľ���֮�ϣ�����һ��ո�µĴ��ݣ�����һ���ʺ�ĵ�
���ڷ嶥�����ķ��зɵ������ϡ��ĺ���ջ���������������ɱ棬����ͨ����
�ƻ���ʾ������֮��Ĵ��ڣ����׵߸���������ƾ��ص���֪��
LONG
NOR
        );
	set("objects", ([
	__DIR__"obj/rock2":1,
	__DIR__"obj/woods":1,
	__DIR__"obj/lantern":1,
	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"enter" : __DIR__"hotel",
  		"southdown" : __DIR__"peak1",
	]) );

	set("outdoors", "cyan");

	set("coor/x",0);
	set("coor/y",40);
	set("coor/z",80);
	setup();
}

void init(){
	add_action("do_look", "look");
}

int do_look(string arg) {
if (!arg)
	return 0;
	if (arg == "����")
	{
		write("һ���ʺ��ʺ���ɢ�Ź�â�ĵ������ڴ�������طɵ���"NOR"\n");
		return 1;
	}
	return 0;
}

void reset()
{
	object river,stone,*inv;
	
	::reset();

	river = present("����", this_object());
	if (!river)
		return;
	inv = all_inventory(river);
	if (sizeof(inv) < 1)
	{
		stone = new(__DIR__"obj/kindling");
		if(stone)
			stone->move(river);
	}
	return;
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


