// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","���Ź�");
  set("long",@LONG
��ľ�Ƶ��ţ�������ǧ��������Ȼ��ɫ���ģ�ϸ�������������̷���룬
���Ӧ�о��У���ϸ���������ɼ���ȸ���ᣬ���ѵ�ˮ��������棬ɽʯ��ľ��
�ڴ�����һ�����࣬�����ź��Ÿ����أ�¥���������ʯ��̨���������������
ʤ�ա����ϱ�������¥��
LONG
  );
  set("exits",([
         "southdown":__DIR__"daizong",
         "up" :__DIR__"wanxian",
	"westup" : __DIR__"puzhao",
	"eastdown" : __DIR__"wangmu",
               ]));
        set("objects", ([
        __DIR__"npc/songzong" : 1,
                        ]) );
        set("outdoors", "fengyun");
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",10);
	setup();
  	replace_program(ROOM);
}
