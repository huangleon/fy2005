// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","������");
  set("long",@LONG
������Ҫ���������¼е���һ�򵱹أ����Ī�������˼е�����ǰ���ɵû�Ȼ
���ʣ�һƬ������ƽ�س�����ǰ�������ɽ��ʯ������ôһ�����������ڣ�Ҳ����
�˷�����˼�����������ؽ������޲����ش˵أ�����ǲ�������е������������
LONG
  );
  set("exits",([
	"southwest" : __DIR__"yanghuang",
               ]));
        set("objects", ([
        __DIR__"npc/ghost" : 5,
                        ]) );
        set("outdoors", "fengyun");
	set("coor/x",20);
	set("coor/y",30);
	set("coor/z",40);
	setup();
  	replace_program(ROOM);
}
