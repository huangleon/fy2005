// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","����ͤ");
  set("long",@LONG
�˴�������֮�£�˫����ţ���������ɽ������ɽ��Ũ�ܵ������������ھ�
��֮�ϣ�������ɽ���Х����������İ������ɳĸ��ƶ����֣�����������裬��
������ɹȣ��ĵ���ۣ��ഫǬ¡�ʵ������顰�����Ѵ����������������
LONG
  );
  set("exits",([
	"down" : __DIR__"chaoyang",
	"up" : __DIR__"shiba",
               ]));
        set("objects", ([
        __DIR__"npc/zhu" : 1,
	__DIR__"npc/zyc" : 1,
                        ]) );
        set("outdoors", "fengyun");
	set("coor/x",10);
	set("coor/y",20);
	set("coor/z",100);
	setup();
  	replace_program(ROOM);
}
