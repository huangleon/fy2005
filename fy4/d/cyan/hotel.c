// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "�ĺ���ջ��");
    set("long", @LONG
�������߽��ĺ���ջ��ֻ���÷�����˼����һ�굽ͷ����һ���յ�����
ָͷ��ô����ο͡�����һ�Ρ������Ʒ嶥���������δ�ؿ���������������
��������������Ȿ���������ˣ��˷����������ڴ˿�������û����ˮ�Ŀ�
ջ��
LONG
NOR
        );
	set("objects", ([

	__DIR__"npc/rabbit":2,
	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"out" : __DIR__"peak2",
  		"enter" : __DIR__"hotel2",
	]) );

	set("outdoors", "cyan");

	set("coor/x",0);
	set("coor/y",40);
	set("coor/z",90);
	setup();
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


