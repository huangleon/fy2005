// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","������");
  set("long",@LONG
������������������һ������������ʷ��֤���������Ĺ��ţ�Ʈ�ݾ��ף�ÿ��
ĺ�ĳ��ӣ��䲻�󣬵���ׯ�ϲ����������ɰ�ӳ�գ�������������֮�⣬����һ��
��һƷ����ɡ����������¸��Ӿ�Զ���������������ŷ��ߣ���̩ɽ������ص���
���½�������������������֮ʢ��Ҳ��һʱ������
LONG
  );
  set("exits",([
	"eastdown" : __DIR__"hongmen",
               ]));
        set("objects", ([
        __DIR__"obj/tree" : 1,
        __DIR__"npc/lengqingping" : 1,
                        ]) );
        set("outdoors", "fengyun");
	set("coor/x",-10);
	set("coor/y",10);
	set("coor/z",20);
	setup();
  	replace_program(ROOM);
}
