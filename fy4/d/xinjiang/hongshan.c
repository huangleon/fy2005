/* Copyright (C) 1998 Apstone, Inc. */
inherit ROOM;
void create()
{
        set("short", "��ɽ");
        set("long", @LONG
��ɽ��ɽ�ʺ��ɫ������ɽ���Ǻܸߣ�Ҳ���Ǻ���ΰ�������Ǻ�������ɽ����
һ�����ơ������������������������������������ߴ�ĳ��źͳ��������Ĵ��̾�
���۵ס�
LONG
        );
        set("exits", ([ 
  		"up" : __DIR__"zhenlong",
  		"southdown" : __DIR__"tulu",
	]));

        set("objects", ([
			__DIR__"npc/hong" : 1,
	]) );

	
        set("outdoors", "xinjiang");
	set("coor/x",0);
	set("coor/y",50);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
