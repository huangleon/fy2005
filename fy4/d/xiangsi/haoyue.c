// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "��¹�");
        set("long", @LONG
ת�����ϣ���֪�˴�������Ȥ����ɫ���ȴ�ǰ��ֻ�����������ɺ��ƺ��
�ϱ�������˼һ�ߵ�ɽ����������������ɽ�����ͣ��������裬ƾ��������һ
��ɽˮ����������ǰ����Զ������һ��������ڣ�̧�ۿ�ȥ��ֻ����ǰʯ����
�����������֣�

����������������������[1;37m𩡡�������¡�����������[0;32m

LONG
NOR
        );
	set("objects", ([
//		__DIR__"obj/rock4" : 1,
	]));
	set("item_desc", ([
//		"ʯ��": (: look_stone :),
	]) );
	set("exits",([
  		"northdown" : __DIR__"shipai",
  		"east" : __DIR__"cansan",
  		"west" : __DIR__"zoulang",
	]) );

	set("outdoors", "xiangsi");

	set("coor/x",20);
	set("coor/y",-20);
	set("coor/z",20);
	setup();
}

string look_stone()
{
	object me = this_player();
	tell_object(me,"ʯ���������һ��С�֣�\n������������£�����ȴ�ټ�ȫ�ޣ����������Ҷ���Ү��\n");
	me->set_temp("annie/xiangsi_master",1);
	return " ";
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


