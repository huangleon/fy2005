#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"��Ҷ��"NOR);
	set("long", @LONG
�ﻨ�ҵ���ݻƣ����������ҹ����������ǰħ����Ů�͛���ר����ľ��
������ʱ�佫��ϼ������ֲ���ˣ��Ӵ����۴��ģ���һ������������������Զ
���������ɪ����
LONG
        );
	set("exits",([
  		"east" : __DIR__"56",
		"southup" : __DIR__"45",
  		"west" : __DIR__"36",


	]) );

	set("objects", ([
	__DIR__"npc/tong" : 1,
					]) );

  	set("coor/x",40);
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
