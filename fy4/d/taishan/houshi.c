// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","��ʯ��");
  set("long",@LONG
����̩ɽ֮β������������޴��ɵ��ˣ�������������ع�ʯ��ᾡ���������
���ţ����¸��ӣ��ƺ���ã��ϸ��ʯ�ϣ���������ɧ�ͣ���ʫ������һ·��������
�Σ��������Ĳ��ɵ����˺�����𣬽���ס���쳤Х��
LONG
  );
  set("exits",([
	"south" : __DIR__"nantian",
               ]));
        set("outdoors", "fengyun");
	set("coor/x",10);
	set("coor/y",30);
	set("coor/z",120);
	setup();
  	replace_program(ROOM);
}
