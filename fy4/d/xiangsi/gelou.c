// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
	object river,stone,*inv;

	set("short", "ѩ�и�");
        set("long", @LONG
�߽�ů��޹Ȼ��ѩ�и�ɽ����Ȼ�ĺ���һɨ���ա����ǻ谵��С����
б����һ��������齣���Ϸ��ʵʹ�������׹�أ�˫�ｻ���Ľ��������ǳ
��ɫ���ɴ֮�⡣��齱�����С�ɵĻ���ľױ̨��̨��һ���綹������ӯӯ
���������ž�̩���Ĵ�ƿ��ƿ�м����ؽ�С�����Խ������š�һֻ��ͭСů
¯�����k�ż��Ƶ�����ˮ���㣬���ܵ�����������ǳǳ������
LONG
        );
	set("objects", ([
		__DIR__"npc/suluo" : 1,
		__DIR__"obj/desk2" : 1,
	]));
	set("exits",([
  		"west" : __DIR__"hanquan",
	]) );

	set("item_desc", ([
		"���":	"�����ͷ������ͷ��������β�������м�����һ�����顣\n",
		"����":	"һ������ɽ�����ɵ�Բ�飬��Ө͸����\n",
		"����": "������������������ʲô��\n",
		"����": "һ�浰Բ�ε�ͭ�����������ƺ��и��ѱ���\n",
		"�ѱ�":	"����ϸһ����ԭ��ֻ�Ǹ�����ͨͨ�����硣\n",		
		"��ƿ": "��̩���Ĵ�ƿ�м����ؽ�С�����Խ������š�\n",
	]));	
	
	set("indoors", "xiangsi");

	set("coor/x",20);
	set("coor/y",-30);
	set("coor/z",20);
	setup();

	river = present("ױ̨", this_object());
	if (!river)
		return;
	inv = all_inventory(river);
	if (sizeof(inv) < 1)
	{
		stone = new(__DIR__"obj/cat");
		if(stone)
			stone->move(river);
	}

}



void reset()
{
	object river,stone,*inv;
	
	::reset();

	add("ref",1);
	if (query("ref") < 9)
		return;
	set("ref",0);

	river = present("ױ̨", this_object());
	if (!river)
		return;

	inv = all_inventory(river);
	if (sizeof(inv) < 1)
	{
		stone = new(__DIR__"obj/cat");
		if(stone)
		{
			stone->move(river);
			river->set("cat",1);
		}
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


