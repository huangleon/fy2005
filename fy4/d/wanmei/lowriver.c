// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "С��������");
        set("long", @LONG
����ĺӴ���խ��ˮ���ļ����޷絫������ӿ�����ںӱߣ����в����ͻᱻ��
�˾��ߡ�ֻ���书����֮�˲Ÿ����㡣
......ˮ��Խ��Խ���������Ѿ�����ס����......
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"playground",
]));
	set("outdoors","wanmei");
        set("objects", ([
                __DIR__"npc/cor" :2,
                        ]) );
	set("coor/x",0);
	set("coor/y",100);
	set("coor/z",-50);
	setup();
}
void init()
{
	if(interactive(this_player()))
	call_out("do_flush",10,this_player());
}

void do_flush(object me)
{
        object room;
	if(!me || environment(me) != this_object())
		return;
	tell_object(me,"һ����ӿ�����㱻���������Σ���\n");
	room= load_object(AREA_QIANJIN"hehuadang");
	me->move(room);
}	
