// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","��ĸ��");
  set("long",@LONG
̩ɽ����̶��ǳϪ����ĸ������̶֮ٮٮ�ߣ�̶ˮ�������ɼ���Ӱ���ഫ����
��ĸ������ȥ������·���˴����̲�ספ���ϴ���Ӵ˴�����̶����������������
�߸����⾭Ӫ��ֲ����ˮ����ĸ̶֮����Ϊ̩ɽȺ̶֮�
LONG
  );
	set("exits",([
		"westup" : __DIR__"hongmen",
		"eastup" : __DIR__"pingfeng",
		"east" : __DIR__"hushan",
	]));
	set("objects", ([
		__DIR__"npc/liu1" : 1,
		__DIR__"npc/liu2" : 1,
		__DIR__"obj/lake" : 1,
	]) );

    set("outdoors", "fengyun");
	set("coor/x",10);
	set("coor/y",10);
	set("coor/z",0);
	setup();
  	replace_program(ROOM);
}
