// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","����ͤ");
  set("long",@LONG
������ʯ���۷��٣��ٶ����ŷþ��ɡ�˵�ñ������������������ʼ�ʱ���
�����ڣ�����Ϊ�ض�ʮ�Ⱦ��ĵھż����ɼ�����ʵ���Ǻ��Ժյ��ˡ��ɴ˸��ӣ�
�Ʋ��ŵ��ٲ�ɢ����죬�������ֱ�£����Ʋ�����
LONG
  );
  set("exits",([
	"eastup" : __DIR__"chaoyang",
	"westup" : __DIR__"jiunu",
	"southdown" : __DIR__"buyun",
               ]));
        set("objects", ([
                __DIR__"obj/tree2" : 1,
       ]) );

        set("outdoors", "fengyun");
	set("coor/x",0);
	set("coor/y",20);
	set("coor/z",80);
	setup();
  	replace_program(ROOM);
}
