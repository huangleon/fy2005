// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","����¥");
  set("long",@LONG
һ������¥���·����ˡ�������Դ����һ��ɽϪ����������ɽɫ���ģ�Ϫˮ��
�塣Ϫ��һ������Ķ�ص���ɫ����ʯƺ��ʯ�Ͽ����ƣ��Σ�Ԫ�����������֣���ϧ
����Ϫˮ�ĳ���ϴˢ���ּ��Ѿ�ģ����Ϫ�����ִ�������Ũ�񣬼а�ʯ�ڣ���ɫ
���ԡ�Ϫ��ʯ�����顰��Ȫ�����֣�����������ˮ�������ʯ���ĺϳ�����Ȼ����
��һ�����ࡣ�ֲ�����������פ�㡣����������
LONG
  );
  set("exits",([
         "up":__DIR__"doumu",
         "down" :__DIR__"hongmen",
               ]));
        set("objects", ([
        __DIR__"npc/ding" : 1,
                        ]) );
        set("outdoors", "fengyun");
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",20);
	setup();
  	replace_program(ROOM);
}
