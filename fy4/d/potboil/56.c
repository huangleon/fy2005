#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"��ͩ��"NOR);
	set("long", @LONG
�����ȳ���֮ʱ����ͩ�Լ�������Ϊ��ɽʤ��֮һ�������������ħ̳��
�����Ӹ��Ƕ��ô˴�����ÿһ���������ʵ����綼Ҫ������С������ɫ����
�����£�΢���ᶯ��ҡ��һ�ذ�쵵Ĺ�Ӱ��
LONG
        );
	set("exits",([
  		"east" : __DIR__"66",
		"northup" : __DIR__"57",
  		"west" : __DIR__"46",


	]) );

	set("objects", ([
	__DIR__"npc/ku" : 1,
					]) );

  	set("coor/x",50);
	set("coor/y",60);
	set("coor/z",0);
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
