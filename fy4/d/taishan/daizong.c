// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","��ڷ�");
  set("long",@LONG
�������ͨ��̩ɽ��ɽ�ţ����̩ɽ����һ�����Ũ�񣬷�����������ɵ�
������������������������֮�ף���ɽ֮�ڡ�����Ρ��׳������ڷ�֮�ϣ�������
��һ�������أ�
LONG
  );
  set("exits",([
         "south":AREA_DAIMIAO"houzai",
         "northup" :__DIR__"hongmen",
               ]));
        set("outdoors", "fengyun");
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
  	replace_program(ROOM);
}
