// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","ɽ��");
  set("long",@LONG
���·ת��ǰͻȻ����һ��ƽ�أ�Ȼ��ƽ��֮�ϰεض���һ��ССɽ�壬ɽ��
���ߣ�һ��ʯ��С·�̻�����ֱ��嶥��������һ�������ƶ���Сͤ�ӡ���������
���һƬ���̣�һ����������������
LONG
  );
  set("exits",([
	"east" : __DIR__"nantian",
	"up" : __DIR__"yueguan",
               ]));
        set("outdoors", "fengyun");
	set("coor/x",0);
	set("coor/y",20);
	set("coor/z",120);
	setup();
  	replace_program(ROOM);
}
