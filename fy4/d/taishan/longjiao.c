// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","����ɽ");
  set("long",@LONG
���������మ̩ɽ��������������֮˵��˵̩ɽ������ϵ������ɽ����������
�ڣ�Զ������ɽ�������ۻ룬����Ⱥ�壬�䲻�ߣ�����ͦ���Ƶ�����ʵ�����޷���
���ģ�������ɽ���洦�ɼ�����������ֲ���أ�����̩ɽ������һ�ɰ���֮����
LONG
  );
  set("exits",([
	"eastdown" : __DIR__"jiunu",
               ]));
        set("objects", ([
        __DIR__"npc/chou" : 1,
	__DIR__"npc/mao" : 1,
                        ]) );
        set("outdoors", "fengyun");
	set("coor/x",-20);
	set("coor/y",20);
	set("coor/z",100);
	setup();
  	replace_program(ROOM);
}
