// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","ӣ����");
  set("long",@LONG
ɽ�����죬��ɫ�������𴦻����ƣ�����ͬ��̩ɽ���񴦸�ɽ��ˮ����Ϊ
�ѵã���ӣ����ֲ�Һóԣ��˴��ش�ɽ����ӣ����ɽ��Ұ��ÿ��ӣ�ҳ��켾�ڣ���
ɽ�ۺ죬������Ȼ�����˵��ˣ��మ��Щ��̩ɽӣ�ҵ�����Ӱ�����𴦴��ǲ�ͬ��
LONG
  );
  set("exits",([
	"southdown" : __DIR__"luohan",
               ]));
        set("objects", ([
        __DIR__"npc/waiter" : 1,
                        ]) );
        set("outdoors", "fengyun");
	set("coor/x",10);
	set("coor/y",10);
	set("coor/z",60);
	setup();
  	replace_program(ROOM);
}
