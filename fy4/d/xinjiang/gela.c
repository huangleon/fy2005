/*Copyright (C) 1998 Apstone, Inc. */
inherit ROOM;
void create()
{
        set("short", "�����ڳ�ɽ");
        set("long", @LONG
��ɽ֧�������ڳ�ɽ�����ѩ��ɽ�����˵�����֮��û�м�����Ը��ð�մ���
������ɽ��ȥѰ�Ҵ�˵�е���ɽѩ�����ഫ������ֻ��һ���˻��Ŵ���ɽ�����˳�
�����ҵ��������汦������ɽѩ����
LONG
        );
        set("exits", ([ 
  			"northeast" : __DIR__"bingchuan",
  			"southwest" :  __DIR__"tianshan",
]));
/*
        set("objects", ([
        __DIR__"npc/yaren" : 1,
	__DIR__"npc/prince" : 1,
                        ]) );
*/
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
	set("coor/x",10);
	set("coor/y",-80);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
