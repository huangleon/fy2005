// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","������");
  set("long",@LONG
������ͤ������һ·���μе�����ɫ�谵��������Ȥ��ʯ���Ϲ�ʯ���������
������ɽ���У���һ·��ɽ��������֣��ɴ����ϣ����ǹ��գ������ĺ����ڣ���
ȥ���������衣
LONG
  );
  set("exits",([
	"westdown" : __DIR__"wusong",
	"up" : __DIR__"duisong",
	"eastup" : __DIR__"mengxian",
               ]));
        set("objects", ([
        __DIR__"npc/dalao" : 1,
                        ]) );
        set("outdoors", "fengyun");
	set("coor/x",10);
	set("coor/y",20);
	set("coor/z",90);
	setup();
  	replace_program(ROOM);
}
