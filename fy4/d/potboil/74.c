#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED"������"NOR);
	set("long", @LONG
�뿪�ֳ�����֮�ŵ�����������·𲽽�����ɲ��Ȫ������������Զ����
�Ĳ�������Х��������ˮӳ��һƬѪ�죬���͵Ŀ�����û��һ�����⡣ħ����
�˼��ٶ����˵أ�����Ļ�Ȫ����ȴ������������������һ��ʤ����
LONG
        );
	set("exits",([
		"northdown" : __DIR__"75",
		"westup" : __DIR__"64",
		"eastdown" : __DIR__"84",
	]) );

	set("objects", ([
	__DIR__"npc/du" : 1,
	__DIR__"npc/yin" : 1,
					]) );

  	set("coor/x",70);
	set("coor/y",40);
	set("coor/z",-10);
	set("outdoors", "potboil");
	setup();
}


/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
